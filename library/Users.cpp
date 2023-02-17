#ifndef _USERS_CPP_
#define _USERS_CPP_

#include "Users.h"

void Users::copy(const Users& other){
    this->username = other.getUsername();
    this->password = other.getPassword();
}

void Users::destroy(){
    this->username = "";
    this->password = "";
}

Users::Users(const std::string& _username, const std::string& _password){
    this->username = _username;
    this->password = _password;
}

Users::Users(const Users& other){
    copy(other);
}   

std::string Users::getUsername() const{
    return this->username;
}

std::string Users::getPassword() const{
    return this->password;
}
        
void Users::setUsername(const std::string& _username){
    this->username = _username;
}

void Users::setPassword(const std::string& _password){
    this->password = _password;
}

std::ostream& operator<<(std::ostream& out, const Users& user){
    out << user.getUsername() << " " << user.getPassword();

    return out;
}

#endif