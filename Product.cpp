#include "Product.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

// Initialize static variable
int Product::ProductCounter = 1;

Product::Product() {
    productID ="";
    productName = "";
    companyName ="";
    price =0.0;
}

Product::Product(string pr_name, string co_name, double pr) {

    // Automatic Id creation
    stringstream ss;
    ss << "P" << ProductCounter++;
    productID = ss.str();

    productName = pr_name;
    companyName = co_name;
    price = pr;
}


string Product::getProductID() {
    return productID;
}

string Product::getProductName() {
    return productName;
}

string Product::getCompanyName() {
    return companyName;
}

double Product::getPrice() {
    return price;
}

void Product::setProductName(string pr_name) {
    productName = pr_name;
}

bool Product::setPrice(double pr) {
    if (pr<0) {
        cout << "Invalid Price!" <<endl;
        return false;
    }
    price = pr;
    return true;
}

void Product::display() const {
    cout << left << setw(10) <<productID << setw(25) << productName << setw(20) << companyName << setw(10) << fixed << setprecision(2) << price;

}

bool Product::operator<(const Product& obj) const {
     return price < obj.price;
}
