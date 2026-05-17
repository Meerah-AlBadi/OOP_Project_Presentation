#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <sstream>

using namespace std;
// Product class (.h)
class Product {
    static int ProductCounter;
    string productID, productName, companyName;
    double price;
public:
    Product();                     // Default Constructor

    Product(string pr_name, string co_name, double pr) ;     // Parametarized Constructor

    string getProductID();      // returns Product id

    string getProductName();    // returns Product Name

    string getCompanyName();    // returns Product's Campany name

    double getPrice();          // return Product's Price

    void setProductName(string pr_name);   //  a setter method to set Name of product

    bool setPrice(double pr);     //  a setter method (bool because it checks if price is valid otherwise it returns false )

    void display() const;     // Prints Product Information

    bool operator<(const Product& obj) const;     // Operator Overloading which is used to compare products by price
    
};
#endif
