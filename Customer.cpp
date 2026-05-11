#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer(): User(){}  // call default constructor of user class

Customer::Customer(int id, string name):User(id, name){}
// parameterized  constructor it sends id and name to user contsructor

void Customer::displayCustomer() { // function to display customer information
    cout<<"==== Customer details ===="<<endl ; //print title
    displayUser(); //call function from user class
}
