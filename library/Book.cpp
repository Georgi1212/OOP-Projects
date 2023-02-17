#ifndef _BOOK_CPP_
#define _BOOK_CPP_

#include "Book.h"

void Book::copy(const Book& other){
    this->author = other.getAuthor();
    this->title = other.getTitle();
    this->genre = other.getGenre();
    this->shortDescription = other.getShortDescription();
    this->yearOfPublishment = other.getYearOfPublishment();
    this->rating = other.getRating();
    this->id = other.getID();	
}

void Book::destroy(){
    this->author = "";
    this->title = "";
    this->genre = "";
    this->shortDescription = "";
    this->yearOfPublishment = 0;
    this->rating = 0;
    this->id = "";
}

Book::Book(){
    author = "";
    title = "";
    genre = "";
    shortDescription = "";
    yearOfPublishment = 0;
    this->rating = 0;
    this->id = "";
}

Book::Book(std::string _author, std::string _title, std::string _genre, std::string _shortDescription, 
    int _yearOfPublishment, int _rating, std::string _id){
        this->author = _author;
        this->title = _title;
        this->genre = _genre;
        this->shortDescription = _shortDescription;
        this->yearOfPublishment = _yearOfPublishment;
        this->rating = _rating;
        this->id = _id;
}

Book::Book(const Book& other){
    copy(other);
}

Book& Book::operator=(const Book& other){
    if(this == &other){
        destroy();
        copy(other);
    }

    return *this;
}

std::string Book::getAuthor() const{
    return this->author;
}

std::string Book::getTitle() const{
    return this->title;
}

std::string Book::getGenre() const{
    return this->genre;
}

std::string Book::getShortDescription() const{
    return this->shortDescription;
}

int Book::getYearOfPublishment() const{
    return this->yearOfPublishment;
}

int Book::getRating() const{
    return this->rating;
}

std::string Book::getID() const{
    return this->id;
}

void Book::setAuthor(const std::string& _author){
    this->author = _author;
}

void Book::setTitle(const std::string& _title){
    this->title = _title;
}
void Book::setGenre(const std::string& _genre){
    this->genre = _genre;
}

void Book::setShortDescription(const std::string& _shortDescription){
    this->shortDescription = _shortDescription;
}

void Book::setYearOfPublishment(const int& _yearOfPublishment){
    this->yearOfPublishment = _yearOfPublishment;
}

void Book::setRating(const int& _rating){
    this->rating = _rating;
}

void Book::setID(const std::string& _id){
    this->id = _id;
}

std::ostream& operator<<(std::ostream& out, const Book& book){
    out << "Title: " << book.getTitle() << "; Author: " << book.getAuthor() << "; Genre: " << book.getGenre() <<
     "; Year of publishment: " << book.getYearOfPublishment() << "; ID: " << book.getID() << "; Rating: " << book.getRating();

    return out;
}

#endif