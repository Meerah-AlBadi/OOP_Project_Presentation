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
    for (int i=0;i<products.size();i++) {
        if (products[i].getProductID()==prdct.getProductID()){
            quantities[i]+=qty;
            return;
        }
    }
        products[products.size()]=prdct; 
        quantities[size]=qty;
        size++;
    }
void Inventory::reduce_stock(int id,int amount) { //function to reduce product after stock purchase
    if (amount<=0) {
        cout<<"Invalid amount"; //exception handling for purchase amount
        return;
    }
    for (int i=0;i<products.size();i++) {
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
    for (int i=0; i<products.size();i++) {
        cout<<products[i].getProductName()<<" "<<products[i].getProductID()<<" "<<quantities[i]<<endl;
    }
}
// Function to findProduct
Product* Inventory::findProduct (int ProductID) { 
    for (int i=0; i<products.size() ;i++) {
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
    for (int i=0; i<products.size() ; i++) {
        if (products[i].getProductID() == productID) {
            quantities[i] = newQuantity;
            cout<<"Stock updates successfully"<<endl;
            return true;
        }
    }
    cout<<"product not found"<<endl;
    return false;
}

// Remove a product
bool Inventory::removeProduct(int productID) {
    for (int i=0; i<size ; i++) {
        if (products[i].getProductID()== productID) {
            for (int j=i;j<size-1 ; j++) {
                products[j]= products[j+1];
                quantities[j]=quantities[j+1];
            }
            size--;
            cout<<"product removed successfully"<<endl;
            return true;
        }
    }
    cout<<"product not found"<<endl;
    return false;
}

