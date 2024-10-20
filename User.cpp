
#include "User.h"

int User::count = 0;

User::User(){
    name = "";
    age = 0;
    email = "";
    password = "";
    count++;
    id = count;

}

User::User(const User& u){
        name = u.name;
        age = u.age;
        email = u.email;
        password = u.password;
        id = u.id;
}

User::User(string name,int age, string email,string password){
        count++;
        this->id = count;
        this-> name = name;
        this-> age = age;
        this-> email = email;
        this-> password = password;
}

void User::operator=(const User& user){
    name = user.name;
    age = user.age;
    email = user.email;
    password = user.password;
    id = user.id;
};

void User::setId(int i){
        id = i;
    }
int User::getId(){
        return id;
    }
void User::setName(string i){
        name = i;
    }
string User::getName()const{
    return name;
}
void User::setAge(int i){
        age = i;
    }
int User::getAge(){
        return age;
    }
void User::setEmail(string i){
        email = i;
}
string User::getEmail(){
        return email;
    }
void User::setPassword(string i){
        password = i;
    }
string User::getPassword(){
        return password;
    }
void User::Display(){
    cout << "Name is " << name <<endl;
    cout << "Age is " << age <<endl;
    cout << "ID is " << id <<endl;
    cout << "Email is " << email <<endl;
};
bool User::operator==(const User& u){
    if(name==u.name && email==u.email && age==u.age && id==u.id) return true;
    return false;
};

ostream &operator<<(ostream& output,const User& u)
{
    output << "========User" << u.id << " Info========" <<endl;
    output << "Id: " << u.id  << " |Name: " << u.name << " | Age: " << u.age << " | Email: " << u.email <<endl;
    output << "================================\n";
    return output;
};

istream& operator>>(istream& input, User& u)
{
    cout << "Enter the user information in this order" <<endl;
    cout << "Name Age Email Password\t (Space Separated)" <<endl;
    input >> u.name >> u.age >> u.email >> u.password;
    cout << "================================\n";
    return input;

};


