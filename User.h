#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include <iostream>
#include <string.h>

using namespace std;

class User{
private:
           string name;
           int age;
           int id;
           string password;
           string email;
public:
          static int count;
          User();
          User(string  , int  , string  , string  );
          User(const User& );
          bool operator==(const User&);
          void operator=(const User&);
          void setName(string );
          string getName()const;
          void setPassword(string );
          string getPassword();
          void setEmail(string );
          string getEmail();
          void setAge(int );
          int getAge();
          void setId(int );
          int getId();
          void Display ();
          friend ostream &operator<<(ostream&,const User&);
          friend istream &operator>>(istream&, User&);
};

#endif // USER_H_INCLUDED
