#ifndef _ADMINISTRATOR_H
#define _ADMINISTRATOR_H

#include "Users.cpp"

class Administrator : public Users{
    public:
        Administrator();
        Administrator(const std::string& _username, const std::string& _password);
        Administrator(const Administrator& other);
        Administrator& operator=(const Administrator& other) = delete;

        Users* clone() const override{
            return new Administrator(*this);
        }

        bool isAdminOrNot() const override{
            return true;
        }
};

#endif
