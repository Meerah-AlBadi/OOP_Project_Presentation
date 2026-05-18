// Class Store

#ifndef STORE_H
#define STORE_H

#include "Inventory.h"
#include "Admin.h"
#include "Customer.h"

#include <iostream>
#include <vector>
using namespace std;



class Store {    // The class that connect all ideas and hence will be called by the main
    Inventory inventory;    //Stores all products and stock
    vector<Admin> admins;    // Stores all admins in the system
    vector<Customer> customers;        // Stores all customers in the system

    //Utility Function (Private functions used within the class only)
    int readChoice();     // Reads User's choic safely from the menu
    Admin* findAdmin(string id, string password);     // Search for the Admin in the vector
    Customer* findCustomer(string id, string password);     // Search for the Customer in the vector

public:
    Store();   // Initializer Constructor
    void run();    // Display the Main menu and ask user for choice
    void creatAdminAccount();   // Creates Admin's login account
    void creatCustomerAccount();  // Creates Customer's login account
    void adminSignIn();    // ask for required info to log the admin to the system
    void customerSignIn();  // ask for required info to log the customer to the system
    void adminMenu(Admin* admin);    // Display admin's menu
    void customerMenu(Customer* customer);  // Display Customer's menu
};

#endif
