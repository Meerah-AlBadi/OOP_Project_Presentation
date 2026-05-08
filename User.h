// Class User
#ifndef USER_h
#define USER_h               
#include<string>
using namespace std;

class User {
protected:
    int id;        // user id
    string name;  //user name
    public:
    User() ;// initialized  constructor
    User(int i, string n) ; //parameterized  constructor
    int getId() ;// return user id
    string getName() ; // return user name
    void display() ; // display user info
};
#endif
