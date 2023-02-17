#ifndef _COMPARATOR_H_
#define _COMPARATOR_H_

#include "Book.cpp"

struct compareByTitleAsc {
    bool operator()(const Book& lhs, const Book& rhs){
        return lhs.getTitle() < rhs.getTitle();
    }
};

struct compareByTitleDesc{
    bool operator()(const Book& lhs, const Book& rhs){
        return lhs.getTitle() > rhs.getTitle();
    }
};

struct compareByAuthorAsc{
    bool operator()(const Book& lhs, const Book& rhs){
        return lhs.getAuthor() < rhs.getAuthor();
    }
};

struct compareByAuthorDesc{
    bool operator()(const Book& lhs, const Book& rhs){
        return lhs.getAuthor() > rhs.getAuthor();
    }
};

struct compareByYearAsc{
    bool operator()(const Book& lhs, const Book& rhs){
        return lhs.getYearOfPublishment() < rhs.getYearOfPublishment();
    }
};

struct compareByYearDesc{
    bool operator()(const Book& lhs, const Book& rhs){
        return lhs.getYearOfPublishment() > rhs.getYearOfPublishment();
    }
};

struct compareByRatingAsc{
    bool operator()(const Book& lhs, const Book& rhs){
        return lhs.getRating() < rhs.getRating();
    }
};

struct compareByRatingDesc{
    bool operator()(const Book& lhs, const Book& rhs){
        return lhs.getRating() > rhs.getRating();
    }
};

#endif