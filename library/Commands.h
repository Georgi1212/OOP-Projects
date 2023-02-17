#ifndef _COMMANDS_H_
#define _COMMANDS_H_

#include <string>
#include <algorithm>

#include "Comparator.h"
#include "Database.cpp"

class Commands{
    private:
        Database database;
        std::ofstream out;

        void insantiateClientOrAdmin(Users*& user, const std::string& username, const std::string& password, const std::string& adminOrClient);

    public:
        std::list<Book> getBooks() const { return database.books; }
        void open(const std::string& filename);
        
        void close(const std::string& filename);

        void save(const std::string& filename);

        void help();

        void login(const std::string& adminOrClient);

        void booksInfo(const std::string& isbn_value);

        void booksFind(const std::string& option, const std::string& option_string);

        void booksSort(const std::string& option, const std::string& ascOrDesc);

        void booksAdd(const std::string& title);

        void booksRemove(const std::string& title);

        void usersAdd(const std::string& username, const std::string& password);

        void usersRemove(const std::string& username);

};

#endif