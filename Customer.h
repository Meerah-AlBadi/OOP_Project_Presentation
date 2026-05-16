#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <vector>
#include <sstream>

#include "User.h"
#include "Order.h"
#include "Inventory.h"
#include "Product.h"
#include "CashPayment.h"
#include "CardPayment.h"

using namespace std;

class Customer : public User {
private:
    static int customerCounter;
    vector<Order*> orders;

public:
    // Constructors
    Customer();
    Customer(string name, string password);

    // Override function
    void showMenu() override;

    // Functions
    void viewProducts(const Inventory& inventory) const;
    void placeOrder(Inventory& inventory);
    void viewOrderHistory() const;

    // Destructor
    ~Customer();
};

#endif
