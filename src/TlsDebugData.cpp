#include "TlsDebugData.h"

#include <fstream>
#include <string>
#include <sstream>

using namespace std;
const regex TlsDebugData::REGEX_HEXLINE{"^[0-9]{4}:(\\s[\\da-fA-F]{2}){8}  (\\s[\\da-fA-F]{2}){8}"};
const regex TlsDebugData::REGEX_HEXDELIM{" "};
const regex TlsDebugData::REGEX_HEXCHAR{"[\\da-fA-F]{2}"};

TlsDebugData::TlsDebugData()
{
    //ctor
}

TlsDebugData::~TlsDebugData()
{
    //dtor
}

int TlsDebugData::readSessions(ifstream &ifs, SessionStore &keyset)
{
    string line;

    // extract the data from the file
    while (getline(ifs,line))
    {
        if( line == "PreMaster Secret:" )
        {
            // create a new session in the keyset
            keyset.push_back(new Session);
            // add the client nonce
            getHexData(ifs, keyset.back()->preMasterSecret, Session::pmSize);
        }
        // we need to find the first instance of "Client Nonce" before
        // searching for the other elements
        else if ( keyset.size() == 0)
        {
            continue;
        }
        else if ( line == "Client Nonce:" )
        {
            getHexData(ifs, keyset.back()->clientNonce, Session::cnSize);
        }
        else if ( line == "Server Nonce:" )
        {
            getHexData(ifs, keyset.back()->serverNonce, Session::snSize);
        }
        else if ( line == "Master Secret:")
        {
            getHexData(ifs, keyset.back()->masterSecret, Session::msSize);
        }
        else if ( line == "Client write key:" )
        {
            getHexData(ifs, keyset.back()->clientWriteKey, Session::cwSize);
        }
        else if ( line == "Server write key:" )
        {
            getHexData(ifs, keyset.back()->serverWriteKey, Session::swSize);
        }
    }

    return 0;
}

void TlsDebugData::getHexData(ifstream &file, unsigned short* data, size_t length)
{
    string line;
    int index = 0,lines = 0;
    smatch m;

    //determine the number of lines to process based on size
    lines = length / 16;

        // Iterate the lines to process
        for (int i = 0; i < lines; i++)
        {
            // get the next hex line
            getline(file,line);
            if (regex_search(line,m,TlsDebugData::REGEX_HEXLINE) == false)
            {
                break;
            }
            // extract the hexdata from the log and
            // split the line into hex values
            stringstream hexData(line.substr(6,49));
            string hexValue;
            // add each character to the array if it's not a space
            while(hexData.good())
            {
                getline(hexData,hexValue,' ');
                if (regex_search(hexValue,TlsDebugData::REGEX_HEXCHAR))
                    data[index++] = std::stoi(hexValue,0,16);
            }
        }
}
