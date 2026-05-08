#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "User.h"
using namespace std;
// customer class inherits from parent class(user class)
class Customer: public User {
public:
    Customer(); // defualt constructor

    Customer(int id, string name);//parametrized constructor

    void displayCustomer(); //display  customer details
};
#endif
