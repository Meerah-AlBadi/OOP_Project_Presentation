#include "Store.h"
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int Store::readChoice() {
    int choice;
    cout << "Enter your Choice: ";

    try {
        cin >> choice;

        if (cin.fail()) {
            throw runtime_error("Invalid input! Please enter a number");
        }

        return choice;
    }

    catch (const runtime_error& ex) {
        cin.clear();
        cin.ignore(10000,'\n');

        cout << ex.what() << endl;
        return -1;
    }

}

Admin* Store::findAdmin(string id, string password) {
    for (Admin& admin: admins) {
        if (admin.login(id,password)) {  // admin is a refrence to an Admin object
            return &admin;
        }
    }
    return nullptr;
}

Customer* Store::findCustomer(string id, string password) {
    for (Customer& customer: customers) {
        if (customer.login(id,password)) {
            return &customer;
        }
    }
    return nullptr;
}

Store::Store() {
    // Just Sample Examples
    inventory.addProduct(Product("Minecraft","Mojang",12.500),10);   // Add a product to inventory by creating a product object and takes quantity
    inventory.addProduct(Product("FIFA 25","EA Sports",24.900),8);
    inventory.addProduct(Product("Call Of Duty","Activision",30.900),5);
}

void Store::run() {
    int option;

    option = 1;

    while(option !=0) {

        cout << endl;
        cout << "========== GAMING STORE MANAGEMENT SYSTEM ==========" << endl;
        cout << "1. Creat Admin Account" << endl;
        cout << "2. Creat Customer Account" << endl;
        cout << "3. Admin Sign In" << endl;
        cout << "4. Customer Sign In" << endl;
        cout << "0. Exit" << endl;

        option = readChoice();

        switch (option) {
            case 1:
                creatAdminAccount();
                break;
            case 2:
                creatCustomerAccount();
                break;
            case 3:
                adminSignIn();
                break;
            case 4:
                customerSignIn();
                break;
            case 0:
                cout << "Exiting system...\n";
                break;
        }
    }

}

void Store::creatAdminAccount() {

    string Name, Password;

    cout << "Enter Admin's Name: ";
    cin.ignore();
    getline(cin,Name);

    cout << "Creat Password (Make It Storng!): ";
    cin >> Password;

    Admin admin(Name, Password, &inventory);
    admins.push_back(admin);

    cout << "Admin Account Created Successfully. " << endl;
    cout << "Your Admin Id Is: " << admin.getId() << endl;
    cout << "Please Remember Your ID and Password for Sign in ! ";
}

void Store::creatCustomerAccount() {

    string Name, Password;

    cout << "Enter Customer's Name: ";
    cin.ignore();
    getline(cin,Name);

    cout << "Creat Password (Make It Storng!): ";
    cin >> Password;

    Customer customer(Name, Password);
    customers.push_back(customer);

    cout << "Customer Account Created Successfully. " << endl;
    cout << "Your Customer Id Is: " << customer.getId() << endl;
    cout << "Please Remember Your ID and Password for Sign in ! ";
}


void Store::adminSignIn() {

    string Id, Password;

    cout << "Enter Admin ID: ";
    cin >> Id;

    cout << "Enter Password: ";
    cin >> Password;

    Admin* admin = findAdmin(Id, Password);

    if (admin == nullptr) {
        cout << "Invalid Admin Id or Password!";
        return;
    }

    cout << "Welcome, " << admin->getName() << "<3" <<endl;
    adminMenu(admin);
}


void Store::customerSignIn() {

    string Id, Password;

    cout << "Enter Customer ID: ";
    cin >> Id;

    cout << "Enter Password: ";
    cin >> Password;

    Customer* customer = findCustomer(Id, Password);

    if (customer == nullptr) {
        cout << "Invalid Customer Id or Password!";
        return;
    }

    cout << "Welcome, " << customer->getName() << "<3 " <<endl;
    customerMenu(customer);
}

void Store::adminMenu(Admin* admin) {

    int option;
    option = 1;
    while (option!=0) {

        admin ->showMenu();
        option = readChoice();

        switch (option) {
            case 1:
                admin -> addProduct();
                break;
            case 2:
                admin -> viewInventory();
                break;
            case 3:
                admin -> updateProductStock();
                break;
            case 4:
                admin -> updateProductPrice();
                break;
            case 5:
                admin -> removeProduct();
                break;
            case 0:
                cout << "Admin logged out " << endl;
                break;

        }
    }
}


void Store::customerMenu(Customer* customer) {

    int option;
    option = 1;
    while (option!=0) {

        customer ->showMenu();
        option = readChoice();

        switch (option) {
            case 1:
                customer -> viewProducts(inventory);
                break;
            case 2:
                customer -> placeOrder(inventory);
                break;
            case 3:
                customer -> viewOrderHistory();
                break;
            case 0:
                cout << "Customer logged out " << endl;
                break;

        }
    }
}
