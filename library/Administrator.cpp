#ifndef _ADMINISTRATOR_CPP_
#define _ADMINISTRATOR_CPP_

#include "Administrator.h"

Administrator::Administrator(){
    username = "admin";
    password = "i<3c++";
}

Administrator::Administrator(const std::string& _username, const std::string& _password) : Users::Users(_username, _password){}

Administrator::Administrator(const Administrator& other) : Users::Users(other){}

#endif