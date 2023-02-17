#ifndef _BOOK_H_
#define _BOOK_H_

#include <iostream>
#include <string>

class Book{
    private:
        std::string author;
        std::string title;
        std::string genre;
        std::string shortDescription;
        std::string id;
        int yearOfPublishment;
        int rating;

        void copy(const Book& other);
        void destroy();
    
    public:
        Book();
        Book(std::string _author, std::string _title, std::string _genre, std::string _shortDescription, 
            int _yearOfPublishment, int _rating, std::string _id);
        Book(const Book& other);
        Book& operator=(const Book& other);

        std::string getAuthor() const;
        std::string getTitle() const;
        std::string getGenre() const;
        std::string getShortDescription() const;
        int getYearOfPublishment() const;
        int getRating() const;
        std::string getID() const;

        void setAuthor(const std::string& _author);
        void setTitle(const std::string& _title);
        void setGenre(const std::string& _genre);
        void setShortDescription(const std::string& _shortDescription);
        void setYearOfPublishment(const int& _yearOfPublishment);
        void setRating(const int& _rating);
        void setID(const std::string& _id);

        friend std::ostream& operator<<(std::ostream& out, const Book& book);

};

#endif