#ifndef _USERS_H_
#define _USERS_H_

#include <string>

class Users{
    protected:
        std::string username;
        std::string password;

        void copy(const Users& other);
        void destroy();

    public:
        Users() = default;
        Users(const std::string& _username, const std::string& _password);
        Users(const Users& other);
        Users& operator=(const Users& other) = delete;

        std::string getUsername() const;
        std::string getPassword() const;
        
        void setUsername(const std::string& _username);
        void setPassword(const std::string& _password);

        virtual Users* clone() const = 0;
        virtual bool isAdminOrNot() const = 0;

        friend std::ostream& operator<<(std::ostream& out, const Users& user);

};

#endif