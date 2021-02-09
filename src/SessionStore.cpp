#include "SessionStore.h"

SessionStore::SessionStore(){};
SessionStore::~SessionStore(){};

void SessionStore::push_back(Session* session)
{
    m_data.push_back(session);
}

Session* SessionStore::back()
{
    return m_data.back();
}

int SessionStore::size()
{
    return m_data.size();
}
