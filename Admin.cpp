#include "Admin.h"

#include <iostream>
#include <string>
using namespace std;

Admin::Admin() : User(){
    inventory = nullptr;}

Admin::Admin (int id, string name, Inventory* inv) : User(id, name) {inventory =inv;}

void Admin::Add_Product() {
    int ProductID, quantity;
    string ProductName;
    double price;

    cout << "Enter Product ID: ";
    cin >> ProductID;

    cout << "Enter Product Name: ";
    cin.ignore();
    getline(cin,ProductName);

    cout << "Enter Product Price: ";
    cin >> price;

    cout << "Enter Product Quantity: ";
    cin >> quantity;

    Product product(ProductID,ProductName,price);
    inventory->addProduct(product,quantity);
}

void Admin::View_Inventory() {
    inventory->display_inventory();}


void Admin::Update_Product_Stock() {
    int ProductID, quantity;

    cout << "Enter Product ID: ";
    cin >> ProductID;

    cout << "Enter quantity:";
    cin >> quantity;
}

void Admin::Remove_Product() {
    int ProductID;

    cout << "Enter Product ID to remove: ";
    cin >> ProductID;

    inventory -> removeProduct(ProductID);
}
