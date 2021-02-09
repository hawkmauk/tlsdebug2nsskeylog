#ifndef NSSLOGFORMAT_H
#define NSSLOGFORMAT_H

#include <iostream>
#include "Session.h"


class NssLogFormat
{
    public:
        NssLogFormat();
        virtual ~NssLogFormat();

        void writeSession(std::ostream&, Session*);

    protected:

    private:
};

#endif // NSSLOGFORMAT_H
