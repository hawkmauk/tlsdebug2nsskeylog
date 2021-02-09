#ifndef TLSDEBUGDATA_H
#define TLSDEBUGDATA_H

#include <istream>
#include <regex>

#include "Session.h"
#include "SessionStore.h"

using namespace std;

class TlsDebugData
{
    private:
     // beginning of hexdump line used to extract keys
        const static std::regex REGEX_HEXLINE;
        const static std::regex REGEX_HEXDELIM;
        const static std::regex REGEX_HEXCHAR;
        void getHexData(ifstream &file, unsigned short* data, size_t length);

    public:
        TlsDebugData();
        virtual ~TlsDebugData();

        int readSessions(ifstream &ifs, SessionStore &keyset);

};

#endif // TLSDEBUGDATA_H
