#include "BookList.h"

BookList::BookList(){
    capacity = 0;
    booksCount = 0;
};

BookList::BookList(int capacity){
    this->capacity = capacity;
    this->books = new Book[capacity];
    this->booksCount = 0;
};


void BookList::addBook(const Book& book){
    if(booksCount <= capacity-1){
        int id = books[booksCount].getId();
        books[booksCount] = book;
        books[booksCount].setId(id);
        booksCount++;
    }else{
        cout << "BookList overFlow...\n";
    }
};

void BookList::deleteBook(int d){
    for(int i=0; i<booksCount; i++){
        if(books[i].getId() == d){
            for(int j=i; j<booksCount-1; j++){
                books[j] = books[j+1];
            }
            booksCount--;
            break;
        }
    }
};

Book* BookList::searchBook(string title){
    for(int i=0; i<booksCount; i++){
        if(books[i].getTitle() == title){
           return &books[i];
    }
    return 0;
}};

Book* BookList::searchBook(int id){
    for(int i=0; i<booksCount; i++){
        if(books[i].getId() == id){
           return &books[i];
    }
    }
    return 0;
};

Book BookList::getHighestRateBook(){
    Book bookMax = books[0];
    for(int i=1; i<=booksCount; i++){
        if(bookMax.getAverageRating() < books[i].getAverageRating()){
            bookMax = books[i];
        }
    }
    return bookMax;
};

void BookList::getBooksForUser(const User& user){
    bool check = false;
    for(int i=0; i<booksCount; i++){
        if(books[i].getAuthor() == user){
            check = true;
            cout << books[i];
        }
    }
    if(!check) cout << "No books for this user.\n" <<endl;
};

ostream&operator<<(ostream &output,const BookList &book){
    output << "========BookList" << "========" <<endl;
    for(int i=0; i<book.booksCount; i++){
        output << "Id: " << book.books[i].getId() << " |Title: " << book.books[i].getTitle() << " | Isbn: " << book.books[i].getIsbn() << " | Category: " << book.books[i].getCategory() << " | AverageRating: " << book.books[i].getAverageRating() <<endl;
        cout <<endl;

        /*if(book.books[i].getAuthor().getName()!=""){
            cout << book.books[i].getAuthor() <<endl;
        }*/
        output << "================================\n";
    }

    return output;
};

BookList::~BookList(){
    delete[] books;
};
