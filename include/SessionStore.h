#ifndef SESSIONSTORE_H
#define SESSIONSTORE_H

#include <vector>
#include "Session.h"

using namespace std;
using StoreType = vector<Session*>;

class SessionStore
{
    public:
        SessionStore();
        virtual ~SessionStore();

        void push_back(Session* session);
        Session* back();
        int size();


        StoreType::iterator begin() { return m_data.begin(); };
        StoreType::iterator end()   { return m_data.end(); };

    protected:

    private:
        StoreType m_data;
};

#endif // SESSIONSTORE_H
