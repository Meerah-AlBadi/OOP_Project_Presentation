#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include "customer.h"
#include "product.h"
#include "Payment.h"
using namespace std;

class Order {
int OrderID;
Customer* customer;
Product* product;
Payment payment;
int quantity;
int total;
public:
Order();   // Initializer Constructor
Order(int id, Customer* c, Product* p, int quan, Payment pay);    //Parameterized Counstructor
void displayOrder();    // Print Order details
};
#endif
