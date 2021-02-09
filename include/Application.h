#ifndef APPLICATION_H
#define APPLICATION_H

#include <boost/program_options.hpp>
#include <boost/filesystem/fstream.hpp>

namespace po = boost::program_options;
namespace fs = boost::filesystem;

class Application
{
    public:
        Application(int argc, char** argv);
        virtual ~Application();

        int exec();

    protected:

    private:
        // And now the most interesting, the program itself with the console menu.
        po::options_description m_desc {"Allowed options"};
        po::variables_map m_vm; // container for saving selected program options

        // Required variables for working with menu options
        size_t m_blockSize;
        fs::path m_inputFilePath;
        fs::path m_outputFilePath;
};

#endif // APPLICATION_H
