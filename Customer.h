#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "User.h"
using namespace std;
// customer class inherits from parent class(user class)
class Customer: public User {
    int CustomerID;
    string CustomerName;;
public:
    Customer(); // defualt constructor

    Customer(int id, string name);//parametrized constructor
    string gerCusName();    // return Customer name
    void displayCustomer(); //display  customer details
};
#endif
