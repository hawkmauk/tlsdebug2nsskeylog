#ifndef SESSION_H
#define SESSION_H

class Session
{
    public:
        Session();
        virtual ~Session();

        static const unsigned int cnSize = 32;
        static const unsigned int snSize = 32;
        static const unsigned int pmSize = 32;
        static const unsigned int msSize = 48;
        static const unsigned int cwSize = 32;
        static const unsigned int swSize = 32;

        unsigned short clientNonce[cnSize];
        unsigned short serverNonce[snSize];
        unsigned short preMasterSecret[pmSize];
        unsigned short masterSecret[msSize];
        unsigned short clientWriteKey[cwSize];
        unsigned short serverWriteKey[swSize];

    protected:

    private:
};

#endif // SESSION_H
