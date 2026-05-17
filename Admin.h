// Admin Class 
#ifndef ADMIN_H
#define ADMIN_H


#include <string>
using namespace std;

// Including necessary classes
#include "User.h"
#include "Inventory.h"
#include "Product.h"

class Admin: public User {   // Admin class is inherited from class User
        static int adminCounter;
        Inventory* inventory;   //Pointer to inventory object
public:
    Admin();  // Initializer Constructor
    Admin (int id, string name, Inventory* inv);  //parameterized  Constructor

    void showMenu() override;
    void addProduct();  // Add product to inventory
    void viewInventory() const;   // view products on inventory
    void updateProductStock();   //update a product stock in inventory
    void updateProductPrice();    // remove a product from the inventory
    void updateProductPrice();
};

#endif
