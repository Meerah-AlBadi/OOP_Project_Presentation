#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include<vector>
#include<string>
#include<sstream>
#include<iomanip>
#include"OrderItem.h"
#include"Product.h"
#include"Payment.h"
#include<"Inventory.h"

using namespace std;
class Order{
private:
static int orderCounter;
string orderID;
vector<OrderItem> orderItems;
Payment* payment;

public:
Order();
string getOrderID() const;
void addItem(Product product, int quantity);
double calculateTotal() const;
bool isEmpty() const;

void returnItemsToInventory(Inventory& inventory) const;
void setPayment(Payment*p);
bool pay();
void displayOrder() const;
~Order();
};

#endif  
