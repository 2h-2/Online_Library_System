#include "User.h"
#include "Book.h"
#include "UserList.h"
#include "BookList.h"


////////// User Menu /////////////////
void createUser(UserList &userList){
    User u;
    cin >> u;
    userList.addUser(u);
};

void searchUserByName(UserList userList){
    string name;
    cout << "Enter name: \n";
    cin >> name;
    User *u1 = userList.searchUser(name);
    if(u1 != 0) cout << *u1 <<endl;
    else cout << "no user with this name\n" <<endl;
}

void searchUserByID(UserList userList){
    int id;
    cout << "Enter ID: \n";
    cin >> id;
    User *u1 = userList.searchUser(id);
    if(u1 != 0) cout << *u1 <<endl;
    else cout << "no user with this id\n" <<endl;
}

void searchForUser(UserList userList){
    bool check = true;
    int num;

    while(check){
            cout << "   Search for the user \n";
            cout << "1- Search by name \n";
            cout << "2- Search by id\n";
            cout << "3- Return to users menu\n";
            cin >> num;
        switch (num) {
        case 1:{
            searchUserByName(userList);
            break;
        }
        case 2:{
            searchUserByID(userList);
            break;
        }
        case 3:
            check = false;
            break;
        }
    }


};

void displayAllUsers(UserList &userList){
    cout << userList <<endl;
}

void deleteUserByID(UserList &userList){
    bool check = true;
    while(check){
        int num;
        cout << "1- Delete: \n";
        cout << "2- return to book menu \n";

        cin >> num;
        switch (num) {
            case 1:{
                int id;
                cout << "Enter ID: \n";
                cin >> id;
                User *u1 = userList.searchUser(id);
                if(u1 != 0) userList.deleteUser(id);
                else cout << "no user with this id\n" <<endl;
                break;
            }
            case 2:
                check = false;
                break;
        }
    }
}

void user_menu(){
    int capacity;
    cout << "How many users will be added ?\n";
    cin >> capacity;
    UserList userList(capacity);
    bool check = true;

    while(check){
        int num;
        cout << "   User Menu\n";
        cout << "1- Create user and add it to the list \n";
        cout << "2- Search for a user\n";
        cout << "3- Display all users\n";
        cout << "4- Delete user\n";
        cout << "5- Back to the main\n";
        cin >> num;
        switch (num) {
            case 1:
                createUser(userList);
                break;
            case 2:
                searchForUser(userList);
                break;
            case 3:
                displayAllUsers(userList);
                break;
            case 4:
                deleteUserByID(userList);
                break;
            case 5:
                check = false;
                break;
        }
    }

}


////////// Book Menu /////////////////

void createBook(BookList &bookList){
    Book u;
    bookList.addBook(u);
};

void searchBookByName(BookList bookList){
    string name;
    cout << "Enter name: \n";
    cin >> name;
    Book *b1 = bookList.searchBook(name);
    if(b1 != 0) cout << *b1 <<endl;
    else cout << "no book with this name\n" <<endl;
}

void searchBookByID(BookList bookList){
    int id;
    cout << "Enter ID: \n";
    cin >> id;
    Book *b1 = bookList.searchBook(id);
    if(b1 != 0) cout << *b1 <<endl;
    else cout << "no book with this id\n" <<endl;
}

void searchForBook(BookList bookList){
    bool check = true;
    int num;

    while(check){
            cout << "   Search for the book \n";
            cout << "1- Search by name \n";
            cout << "2- Search by id\n";
            cout << "3- Return to book menu\n";
            cin >> num;
        switch (num) {
        case 1:{
            searchBookByName(bookList);
            break;
        }
        case 2:{
            searchBookByID(bookList);
            break;
        }
        case 3:
            check = false;
            break;
        }
    }


};

void displayAllBooks(BookList &bookList){
    cout << bookList <<endl;
}

void getHighestRating(BookList &bookList){
    Book b1 = bookList.getHighestRateBook();
    cout << b1 <<endl;
}

void getAllBooksForUser(BookList &bookList){
    User u;
    cin >> u;
    bookList.getBooksForUser(u);
}

void deleteBookByID(BookList &bookList){
    bool check = true;
    while(check){
        int num;
        cout << "1- Delete \n";
        cout << "2- return to book menu \n";

        cin >> num;
        switch (num) {
            case 1:{
                int id;
                cout << "Id : " ;
                cin >> id;
                Book *b1 = bookList.searchBook(id);
                if(b1 != 0) bookList.deleteBook(id);
                else cout << "no book with this id\n" <<endl;
                break;
            }
            case 2:
                check = false;
                break;
        }
    }
}

void book_menu(){
    int capacity;
    cout << "How many books will be added ?\n";
    cin >> capacity;
    BookList bookList(capacity);
    bool check = true;

    while(check){
        int num;
        cout << "   Book Menu\n";
        cout << "1- Create book and add it to the list \n";
        cout << "2- Search for a book\n";
        cout << "3- Display all books\n";
        cout << "4- Get the highest ratting\n";
        cout << "5- Get all books of a user\n";
        cout << "6- Get all books of a user\n";
        cout << "7- Back to the main\n";

        cin >> num;
        switch (num) {
            case 1:
                createBook(bookList);
                break;
            case 2:
                searchForBook(bookList);
                break;
            case 3:
                displayAllBooks(bookList);
                break;
            case 4:
                getHighestRating(bookList);
                break;
            case 5:
                getAllBooksForUser(bookList);
                break;
            case 6:
                deleteBookByID(bookList);
                break;
            case 7:
                check = false;
                break;
        }
    }

}


void main_menu(){

   bool check = true;

    while(check){
        int num;
        cout << "   Select one of the following choices\n";
        cout << "1- Book Menu\n";
        cout << "2- User Menu\n";
        cout << "3- Exit\n";

        cin >> num;
        switch (num) {
            case 1:
                book_menu();
                break;
            case 2:
                user_menu();
                break;
            case 3:
                check = false;
                break;
        }
    }

}


int main()
{

    main_menu();
    return 0;
}
