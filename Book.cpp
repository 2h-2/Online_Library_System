#include "Book.h"

int Book::count = 0;

Book::Book(){
    title= "";
    isbn = "";
    count++;
    id= count;
    category = "";
    averageRating = 0.0;
    numRates = 0;
    sumRates = 0.0;
    hasAuthor = false;
}

Book::Book(const Book& b){
    title= b.title;
    isbn = b.isbn;
    id= b.id;
    category = b.category;
    averageRating = b.averageRating;
    numRates = b.numRates;
    sumRates = b.sumRates;
    if(b.hasAuthor){
        author = new User(*b.author);
    }
}

Book::Book(string t, string ib, string c, const User& u){
    title= t;
    isbn = ib;
    count++;
    id= count;
    category = c;
    averageRating =0.0;
    hasAuthor = true;
    author = new User(u);
    numRates = 0;
    sumRates = 0.0;
}

Book::Book(string t, string ib, string c){
    title= t;
    isbn = ib;
    count++;
    id= count;
    category = c;
    averageRating =0.0;
    numRates = 0;
    sumRates = 0.0;
}

void Book::setTitle(string t){
    title = t;
}

string Book::getTitle(){
    return title;
}

void Book::setId(int t){
    id = t;
}

int Book::getId(){
    return id;
}

void Book::setIsbn(string t){
    isbn = t;
}

string Book::getIsbn(){
    return isbn;
}
void Book::setCategory(string t){
    category = t;
}

string Book::getCategory(){
    return category;
}

void Book::setAuthor(const User &user){
    hasAuthor = true;
    author = new User(user);
}

User &Book::getAuthor()const{
    return *author;
}

void Book::rateBook(double rate){
    if(rate <= 5 && rate >= 1){
        numRates++;
        sumRates += rate;
        averageRating = sumRates/numRates;
    }else{
        cout << "please rate from 1 to 5\n";
    }
}

double Book::getAverageRating(){
    return averageRating;
}

bool Book::operator==(const Book& b){
    return (title == b.title && isbn == b.isbn && category == b.category && id == b.id && author == b.author) ;
};

ostream &operator<<(ostream& output,const Book& b)
{
    output << "========Book (" << b.id << ") Info========" <<endl;
    output << "Title: " << b.title << " | Isbn: " << b.isbn << " | Category: " << b.category << " | AverageRating: " << b.averageRating <<endl;
    cout <<endl;

    /*if(b.author->getName()!=""){
        cout <<  *(b.author) <<endl;
    }*/
    return output;
};

istream& operator>>(istream& input, Book& b)
{
    cout << "Enter the Book information in this order" <<endl;
    cout << "Title Isbn Category AverageRating\t (Space Separated)" <<endl;
    input >> b.title >> b.isbn >> b.category >> b.averageRating;
    cout << "================================\n";
    return input;

};

Book::~Book()
{
    delete author;
};
