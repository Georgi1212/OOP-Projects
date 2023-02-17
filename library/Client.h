#ifndef _CLIENT_H_
#define _CLIENT_H_

#include "Users.cpp"

class Client : public Users{
    public:
        Client(const std::string& _username, const std::string& _password);
        Client(const Client& other);
        Client& operator=(const Client& other) = delete;

        Users* clone() const override{
            return new Client(*this);
        }

        bool isAdminOrNot() const override{
            return false;
        }
};

#endif
