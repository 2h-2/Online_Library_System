#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED
#include <iostream>
#include <string.h>
#include "User.h"

using namespace std;
class Book{
    string title;
    string isbn;
    int id;
    string category;
    double averageRating;
    User *author;
    int numRates;
    double sumRates;
    bool hasAuthor;
public:
    static int count;
    Book();
    Book(const Book&);
    Book(string, string, string, const User&);
    Book(string t, string ib, string c);


    void setTitle(string);
    string getTitle();
    void setIsbn(string);
    string getIsbn();
    void setId(int);
    int getId();
    void setCategory(string);
    string getCategory();
    void rateBook(double );
    double getAverageRating();
    void setAuthor(const User&);
    User &getAuthor()const;
    bool operator==(const Book&);
    friend ostream &operator<<(ostream &, const Book &);
    friend istream &operator>>( istream &, Book &);
    ~Book();
};

#endif // BOOK_H_INCLUDED
