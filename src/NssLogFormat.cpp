#include <iostream>
#include <iomanip>
#include <iostream>
#include "NssLogFormat.h"

using namespace std;

NssLogFormat::NssLogFormat()
{
    //ctor
}

NssLogFormat::~NssLogFormat()
{
    //dtor
}

void NssLogFormat::writeSession(ostream &oss, Session* session)
{
    oss << "CLIENT_RANDOM ";
    for (auto &h : session->preMasterSecret )
    {
        oss << std::uppercase << std::setfill('0') << setw(2) << std::hex << h;
    };
    oss << " ";
    for (auto &h : session->masterSecret )
    {
        oss << std::uppercase << std::setfill('0') << setw(2) << std::hex << h;
    }
    oss << std::endl;
}
