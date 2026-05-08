#include <iostream>
#include <string>
#include "Product.h"
using namespace std;

Product::Product() {    //Initializer Constructor
    ProductID =0;
    Product_Name="";
    Price =0;
}
Product::Product(int id,string name,double p): ProductID(id),Product_Name(name),Price(p) {}//Paramenterized Constructor


int Product::getProductID() {return ProductID;}   //returns Product id

string Product::getProductName() {return Product_Name;}   // returns Product Name

void Product::setPrice(double p) {   // set the price of the product
    if (p>=0) {
        Price =p;
    }
}

void Product::displayProduct_info() {  // print Product information
    cout <<"Product ID: "<<getProductID() <<endl;
    cout << "Product Name: "<< getProductName() <<endl;
    cout << "Product Price: " << Price << "OMR "<<endl;
}
