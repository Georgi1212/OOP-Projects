#ifndef _COMMANDS_CPP_
#define _COMMANDS_CPP_

#include "Commands.h"

void Commands::insantiateClientOrAdmin(Users*& user, const std::string& username, const std::string& password, const std::string& adminOrClient){    
    if(adminOrClient == "client"){
        user = new Client(username, password);
    }
    else{
        user = new Administrator(username, password);
    }
}

void Commands::open(const std::string& filename){
    out.open(filename);
    if(!out.is_open()){
        std::cout << "Cannot open " << filename << std::endl;
    }
    else{
        std::cout << "Successfully opened " << filename << std::endl;
    }
}

void Commands::close(const std::string& filename){
    std::remove(filename.c_str());
    out.open(filename, std::ios::trunc);
    out.close();
    std::cout << "Successfully closed " << filename << std::endl;
}

void Commands::save(const std::string& filename){
    database.printBooks(out);
    std::cout << "Successfully saved " << filename << std::endl;
    out.close();
}

void Commands::help(){
    std::cout << "The following commands are supported:" << std::endl;
    std::cout << "open <file>                         - opens <file>" << std::endl;
    std::cout << "close                               - closes currently opened file" << std::endl;
    std::cout << "save                                - saves the currently open file" << std::endl;
    std::cout << "help                                - prints this information" << std::endl;
    std::cout << "login                               - login the user" << std::endl;
    std::cout << "logout                              - log out the user" << std::endl;
    std::cout << "books info <isbn_value>             - outputs information about the book from given <isbn_value>" << std::endl;
    std::cout << "books find <option> <option_string> - find information about given <option> and <option_string>" << std::endl;
    std::cout << "books sort <option> [asc | desc]    - sort books by given <option> in ascending or descending order" << std::endl;
    std::cout << "books add <title>                   - adds a book from a given <title>" << std::endl;
    std::cout << "books remove <title>                - removes a book from a given <title>" << std::endl;
    std::cout << "users add <user> <password>         - adds a user from a given <username> and <password>" << std::endl;
    std::cout << "users remove <username>             - removes a user from a given <username>" << std::endl;
    std::cout << "exit                                - exits the program" << std::endl;
}

void Commands::login(const std::string& adminOrClient){
    database.users.push_back(new Administrator());

    std::string username, password;

    std::cout << "Enter your username: ";
    std::getline(std::cin, username, '\n');

    std::cout << "Enter your password: ";
    std::getline(std::cin, password, '\n');

    Users* entered_user;

    insantiateClientOrAdmin(entered_user, username, password, adminOrClient);

    bool flag = false;

    for(Users* user : database.users){
        if(user->getUsername() == entered_user->getUsername() && user->getPassword() == entered_user->getPassword()){
            std::cout << "Welcome, " << user->getUsername() << "!" << std::endl;
            flag = true;
            break;
        }
    }

    if(!flag){
        std::cout << "The username or the password you have entered is wrong! Type correct username and password or add a new account" << std::endl;
    }
}

void Commands::booksInfo(const std::string& isbn_value){
    std::cout << std::endl;

    for(Book book : database.books){
        if(book.getID() == isbn_value){
            std::cout << "Author: " << book.getAuthor() << std::endl << "Title: " << book.getTitle() << std::endl << "Genre: " << book.getGenre() << std::endl << 
            "Book short description: " << book.getShortDescription() << std::endl << "Year published: " << book.getYearOfPublishment() << std::endl << 
            "Rating: " << book.getRating() << std::endl << "ID: " << book.getID() << std::endl;
            break;
        }
    }

    std::cout << std::endl;
}

void Commands::booksFind(const std::string& option, const std::string& option_string){
    bool flagForExistingOptionString = false;
    for(Book book : database.books){
        if(option == "title" && option_string == book.getTitle()){
            std::cout << "Author: " << book.getAuthor() << std::endl;
            std::cout << "Genre: " << book.getGenre() << std::endl;
            std::cout << "Short Description: " << book.getShortDescription() << std::endl;
            std::cout << "Year of publishment: " << book.getYearOfPublishment() << std::endl;
            std::cout << "Rating: " << book.getRating() << std::endl;
            std::cout << "ID: " << book.getID() << std::endl;
            std::cout << "--------------------------------" << std::endl;
            flagForExistingOptionString = true;
        }
        else if(option == "author" && option_string == book.getAuthor()){
            std::cout << "Book title: " << book.getTitle() << std::endl;
            std::cout << "Genre: " << book.getGenre() << std::endl;
            std::cout << "Short Description: " << book.getShortDescription() << std::endl;
            std::cout << "Year of publishment: " << book.getYearOfPublishment() << std::endl;
            std::cout << "Rating: " << book.getRating() << std::endl;
            std::cout << "ID: " << book.getID() << std::endl;
            std::cout << "--------------------------------" << std::endl;
            flagForExistingOptionString = true;
        }
        else if(option == "genre" && option_string == book.getGenre()){
            std::cout << "Book title: " << book.getTitle() << std::endl;
            std::cout << "Author: " << book.getAuthor() << std::endl;
            std::cout << "Short Description: " << book.getShortDescription() << std::endl;
            std::cout << "Year of publishment: " << book.getYearOfPublishment() << std::endl;
            std::cout << "Rating: " << book.getRating() << std::endl;
            std::cout << "ID: " << book.getID() << std::endl;
            std::cout << "--------------------------------" << std::endl;
            flagForExistingOptionString = true;
        }
    }
    
    if(!flagForExistingOptionString){
        std::cout << "There is no information about that " << option << " with " << option_string << std::endl;
    }
}

void Commands::booksSort(const std::string& option, const std::string& ascOrDesc){
    if(ascOrDesc == "asc"){
        if(option == "title"){
            database.books.sort(compareByTitleAsc());
        }
        else if(option == "author"){
            database.books.sort(compareByAuthorAsc());
        }
        else if(option == "year"){
            database.books.sort(compareByYearAsc());
        }
        else{
            database.books.sort(compareByRatingAsc());
        }

        std::cout << "The books are sorted in ascending order" << std::endl;
    }
    else if(ascOrDesc == "desc"){
        if(option == "title"){
            database.books.sort(compareByTitleDesc());
        }
        else if(option == "author"){
            database.books.sort(compareByAuthorDesc());
        }
        else if(option == "year"){
            database.books.sort(compareByYearDesc());
        }
        else{
            database.books.sort(compareByRatingDesc());
        }

        std::cout << "The books are sorted in descending order" << std::endl;
    }
    else{
        throw std::invalid_argument("There is no such order");
    }
}

void Commands::booksAdd(const std::string& title){
    bool flag = false;

    for(Book book : database.books){
        if(book.getTitle() == title){
            flag = true;
        }
    }

    if(flag){
        std::cout << "You can't add a book, which already exists" << std::endl;
    }
    else{
        std::string author, genre, shortDescription, isbn_value;

        int yearOfPublishment;
        int rating;

        std::cout << "Enter the author of the book you want to add: ";
        std::getline(std::cin, author, '\n');

        std::cout << "Enter the genre of the book you want to add: ";
        std::getline(std::cin, genre, '\n');

        std::cout << "Enter the short description of the book you want to add: ";
        std::getline(std::cin, shortDescription, '\n');

        std::cout << "Enter the year of publishment of the book you want to add: ";
        std::cin >> yearOfPublishment;

        std::cin.ignore();

        std::cout << "Enter the id (ISBN) of the book you want to add: ";
        std::getline(std::cin, isbn_value, '\n');

        std::cout << "Enter the rating of the book you want to add: ";
        std::cin >> rating;

        std::cin.ignore();

        Book bookToAdd(author, title, genre, shortDescription, yearOfPublishment, rating, isbn_value);
        
        database.books.push_back(bookToAdd);
        std::cout << "The book " << title << " has been added" << std::endl; 
    }
}

void Commands::booksRemove(const std::string& title){
    bool flag = false;

    //for(int i = 0; i < database.books.size(); i++){
    //    if(database.books[i].getTitle() == title){
    //        database.books.erase(database.books.begin() + i);
    //        flag = true;
    //    }
    //}

    for(std::list<Book>::iterator it = database.books.begin(); it != database.books.end(); it++){
        if(it->getTitle() == title){
            database.books.erase(it);
            flag = true;
            break;
        }
    }

    if(flag){
        std::cout << "Book with title " << title << " has been removed" << std::endl; 
    }
    else{
        std::cout << "Book with title " << title << " is not removed, because it doesn't exist" << std::endl; 
    }
}

void Commands::usersAdd(const std::string& username, const std::string& password){
    bool flag = false;

    for(Users* user : database.users){
        if(user->getUsername() == username){
            flag = true;
        }
    }

    if(flag){
        std::cout << "You can't add a user, who already exists" << std::endl;
    }
    else{
        std::string adminOrClient;

        std::cout << "admin or client? - ";
        std::getline(std::cin, adminOrClient);

        Users* user;
        insantiateClientOrAdmin(user, username, password, adminOrClient);

        database.users.push_back(user);
        std::cout << "The user " << username << " has been added" << std::endl; 
    }
}

void Commands::usersRemove(const std::string& username){
    bool flag = false;

    //for(int i = 0; i < database.users.size(); i++){
    //    if(database.users[i]->getUsername() == username){
    //        database.users.erase(database.users.begin() + i);
    //        flag = true;
    //    }
    //}

    for(std::list<Users*>::iterator it = database.users.begin(); it != database.users.end(); it++){
        if((*it)->getUsername() == username){
            database.users.erase(it);
            flag = true;
            break;
        }
    }

    if(flag){
        std::cout << "The user " << username << " has been removed" << std::endl; 
    }
    else{
        std::cout << "The user " << username << " is not removed, because he/she doesn't exist" << std::endl; 
    }
}

#endif