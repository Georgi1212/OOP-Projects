#ifndef _DATABASE_CPP_
#define _DATABASE_CPP_

#include "Database.h"
/*
std::vector<Book> Database::getBooks(){
    return books;
}

std::vector<Users*> Database::getUsers(){
    return users;
}*/

void Database::printBooks(std::ostream& out) const{
    for(Book book : books){
        out << book << '\n';
    }
}
/*
void Database::printUsers(std::ostream& out) const{
    for(Users* user : users){
        out << *user << '\n';
    }
}*/

#endif