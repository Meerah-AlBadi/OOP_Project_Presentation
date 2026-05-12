// Admin Class 
#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
using namespace std;

// Including necessary classes
#include "User.h"
#include "Inventory.h"
#include "Product.h"

class Admin: public User {   // Admin class is inherited from class User
        Inventory* inventory;   //Pointer to inventory object
public:
    Admin();  // Initializer Constructor
    Admin (int id, string name, Inventory* inv);  //parameterized  Constructor

    void Add_Product();  // Add product to inventory

    void View_Inventory();   // view products on inventory

    void Update_Product_Stock();   //update a product stock in inventory

    void Remove_Product();    // remove a product from the inventory
    void Update_Product_Price();
};

#endif
