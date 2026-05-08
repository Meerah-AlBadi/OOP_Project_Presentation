#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
using namespace std;
// Product class (.h)
class Product {
    int ProductID;
    string Product_Name;
    double Price;
public:
    Product();   //Initializer Constructor
    Product(int id,string name,double p);  //Paramenterized Constructor
    int getProductID();   //returns Product id
    string getProductName();   // returns Product Name
    void setPrice(double p);   // set the price of the product
    void displayProduct_info();  // prints product information (id,name,price)
};

#endif
