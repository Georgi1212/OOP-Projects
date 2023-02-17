#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <list>
#include <fstream>

#include "Book.cpp"
#include "Client.cpp"
#include "Administrator.cpp"

struct Database{
    public:
        std::list<Book> books;
        std::list<Users*> users;
    
    public:
        //std::vector<Book> getBooks();
        //std::vector<Users*> getUsers();

        void printBooks(std::ostream& out) const;
        //void printUsers(std::ostream& out) const;
};



#endif