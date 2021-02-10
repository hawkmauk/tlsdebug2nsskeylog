#include <iostream>
#include <fstream>
#include <string>

#include "Application.h"
#include "TlsDebugData.h"
#include "SessionStore.h"
#include "NssLogFormat.h"

Application::Application(int argc, char** argv)
{
    // Add menu items
    m_desc.add_options()
            ("help", "produce help message")  // Help
            ("input,i",  po::value<fs::path>(&m_inputFilePath)->composing(), "set input file path")              // Input file, you can write either --input-file, or -i
            ("output,o", po::value<fs::path>(&m_outputFilePath)->composing(), "set output file path")            // Output file
            ;
    po::store(po::parse_command_line(argc, argv, m_desc), m_vm);  // parse passed arguments
    po::notify(m_vm); // write arguments to variables in the program
}

Application::~Application()
{
    //dtor
}

int Application::exec()
{
    int input;
    SessionStore keyStore;

    // If there is a request for help
    if (m_vm.count("help"))
    {
        // Then we display the menu description
        std::cout << m_desc << std::endl;
        return 1;
    }

    // If at least input and output parameters were entered
    if (! m_vm.count("input") && ! m_vm.count("output"))
    {
        // then we initialize the program, but in this case we only
        // display information about the entered parameters
        std::cout << m_desc << std::endl;
        return 1;
    }

    TlsDebugData data;
    ifstream ifs;
    ifs.open(m_inputFilePath.string(), std::ifstream::in);
    input = data.readSessions(ifs, keyStore);
    ifs.close();

    cout << "There are " << keyStore.size() << " sessions logged" << endl;

    NssLogFormat output;
    ofstream ofs;
    ofs.open(m_outputFilePath.string(), std::ofstream::out);

    for (auto session : keyStore){
        output.writeSession(ofs, session);
    }

    ofs.close();

    return input;
}
