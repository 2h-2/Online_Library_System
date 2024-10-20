#include "UserList.h"

UserList::UserList(){
    capacity = 0;
    usersCount = 0;
}

UserList::UserList(int capacity){
    this->capacity = capacity;
    this->users = new User[capacity];
    this->usersCount = 0;
}

void UserList::addUser(const User &user){
    if(usersCount <= capacity-1){
        int Id = users[usersCount].getId();
        users[usersCount] = user;
        users[usersCount].setId(Id);
        usersCount++;
    }else{
        cout << "List overFlow...\n";
    }

}

User* UserList::searchUser(string name){
    for(int i=0; i<usersCount; i++){
        if(users[i].getName() == name){
            return &users[i];
        }
    }
    return 0;
};

User* UserList::searchUser(int id){
    for(int i=0; i<usersCount; i++){
        if(users[i].getId() == id){
            return &users[i];
        }
    }
    return 0;
};

void UserList::deleteUser(int d){
    User arr[usersCount];
    for(int i=0; i<usersCount; i++){
        if(users[i].getId() == d){
            for(int j=i; j<usersCount-1; j++){
                users[j] = users[j+1];
                //users[j].setId(users[j+1].getId());
            }
            usersCount--;
            break;
        }
    }
};

ostream &operator<<(ostream& output, UserList& userList)
{
    output << "========UserList" << "========" <<endl;
    for(int i=0; i<userList.usersCount; i++){

        output << "Id: " << userList.users[i].getId() << " |Name: " << userList.users[i].getName() << " | Age: " << userList.users[i].getAge() << " | Email: " << userList.users[i].getEmail() <<endl;
        output << "================================\n";
    }

    return output;
};

UserList::~UserList(){
    delete[] users;
};








