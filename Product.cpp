#include <iostream>
#include <string>
#include "Product.h"
using namespace std;
// Product class (.cpp)

Product() {    //Initializer Constructor
    ProductID =0;
    Product_Name="";
    Price =0;
}
Product(int id,string name,double p): ProductID(id),Product_Name(name),Price(p) {}//Paramenterized Constructor


int getProductID() {return ProductID;}   //returns Product id
string getProductName() {return Product_Name}   // returns Product Name
void setPrice(double p) {   // set the price of the product
    if (p>=0) {
        Price =p;
    }
}

void displayProductinfo() {              // prints Product
    cout << "Product ID: "<<getProductID()<<endl;
    cout << "Product Name: "<<getProductName()<<endl;
    cout << "Product Price: "<<Price<<"OMR "<<endl;
}
