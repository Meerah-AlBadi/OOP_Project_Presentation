#include<iostream>
#include<string>
#include"User.h"
using namespace std;
User::User() {  //initialized constructor
    id =0;
    name="";
}
User::User (int i, string n) { //parameterized  constructor
    id = i;
    name = n;
}
int User::getID() { // return user id
    return id;
}
string User::getName() {  // return user name
    return name;
}
void User::display() {  // display user info
    cout<<"id = "<<id<<endl;
    cout<<"name = "<<name<<endl;
}
