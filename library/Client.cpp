#ifndef _CLIENT_CPP_
#define _CLIENT_CPP_

#include "Client.h"

Client::Client(const std::string& _username, const std::string& _password) : Users::Users(_username, _password){}

Client::Client(const Client& other) : Users::Users(other){}

#endif