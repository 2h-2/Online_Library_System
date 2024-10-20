#ifndef BOOKLIST_H_INCLUDED
#define BOOKLIST_H_INCLUDED
#include <iostream>
#include <string.h>
#include "Book.h"
using namespace std;

class BookList{
    Book* books;
    int capacity;
    int booksCount;
public:
    BookList();
    BookList(int);

    void addBook(const Book&);
    Book *searchBook(string);
    Book *searchBook(int);
    void deleteBook(int);
    Book getHighestRateBook();
    void getBooksForUser(const User&);
    friend ostream&operator<<(ostream &,const BookList & );
    ~BookList();
};


#endif // BOOKLIST_H_INCLUDED
