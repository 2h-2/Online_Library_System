#ifndef USERLIST_H_INCLUDED
#define USERLIST_H_INCLUDED
#include <iostream>
#include <string.h>
#include "User.h"
using namespace std;

class UserList{
    User *users;
    int capacity;
    int usersCount;
public:
    UserList();
    UserList(int);
    void addUser(const User&);
    void deleteUser(int);
    User *searchUser(string);
    User *searchUser(int);
    friend ostream &operator<<(ostream&, UserList&);
    ~UserList();
};


#endif // USERLIST_H_INCLUDED
