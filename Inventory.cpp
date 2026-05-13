#include "Inventory.h"
#include <iostream>
using namespace std;

Inventory::Inventory() { //constructor
}
void Inventory::add_product(Product prdct, int qty) { //function to add product/update quantity
    if (qty<=0) { //exception handling for quantity
        cout<<"Invalid quantity";
        return;
    }
    for (size_t i=0;i<products.size();i++) {
        if (products[i].getProductID()==prdct.getProductID()){
            quantities[i]+=qty;
            return;
        }
    }
        products.push_back(prdct); 
        quantities.push_back(qty);
    }
void Inventory::reduce_stock(int id,int amount) { //function to reduce product after stock purchase
    if (amount<=0) {
        cout<<"Invalid purchase amount"; //exception handling for purchase amount
        return;
    }
    for (size_t i=0;i<products.size();i++) {
        if (products[i].getProductID()==id) {
            if (quantities[i]>=amount){
                quantities[i]-=amount;
            }
            else{
                cout<<"Not enough stock";
            }
            return;
        }
    }
    cout<<"Product is not found"; //if there is not matching prdct
}
void Inventory::display_inventory() { //function to display all stored products and quantites
    cout << endl;
    cout << "==== Inventory ====" << endl;
    for (size_t i=0; i<products.size();i++) {
        cout<<products[i].getProductName()<<" "<<products[i].getProductID()<<" "<<quantities[i]<<endl;
    }
}
// Function to findProduct
Product* Inventory::findProduct (int ProductID) { 
    for (size_t i=0; i<products.size() ;i++) {
        if (products[i].getProductID() == ProductID) {
            return &products[i];
        }
    }

    return nullptr; //if no matching product
}

// Function to update Stock of a product
bool Inventory::updateStock(int productID, int newQuantity) {
    if (newQuantity < 0) {
        cout<<"Invalid stock quantity"<<endl;
        return false;
    }
    for (size_t i=0; i<products.size() ; i++) {
        if (products[i].getProductID() == productID) {
            quantities[i] = newQuantity;
            cout<<"Stock updated successfully"<<endl;
            return true;
        }
    }
    cout<<"Product not found"<<endl;
    return false;
}

// Remove a product
bool Inventory::removeProduct(int productID) {
    for (size_t i=0; i<products.size() ; i++) {
        if (products[i].getProductID()== productID) {
            products.erase(products.begin()+i);
            quantities.erase(quantities.begin()+i);
            
            cout<<"Product removed successfully"<<endl;
            return true;
        }
    }
    cout<<"Product not found"<<endl;
    return false;
}

