#include "Inventory.h"
#include <iostream>
using namespace std;

Inventory::Inventory() {
    size=0;
}
void Inventory::add_product(Product prdct, int qty) {
    if (qty<=0) { //exception handling for quantity
        cout<<"Invalid quantity";
        return;
    }
    for (int i=0;i<count;i++) {
        if (products[i].get_ID()==prdct.get_ID()) {
            quantities[i]+=qty;
            return;
        }
    }
        products[size]=prdct;
        quantities[size]=qty;
        size++;
    }
void Inventory::reduce_stock(int id,int amount) {
    if (amount<=0) {
        cout<<"Invalid amount"; //exception handling for purchase amount
        return;
    }
    for (int i=0;i<size;i++) {
        if (products[i].get_ID()==id) {
            if (quantities[i]>=amount){
                quantities[i]-=amount;
            }
            else{
                cout<<"Not enough stock";
            }
            return;
        }
    }
    cout<<"Product is not found";
}
void Inventory::display_inventory() {
    for (int i=0; i<count;i++) {
        cout<<products[i].getProductID()<<" "<<quantities[i]<<endl;
    }
}
// Function to findProduct
Product* Inventory::findProduct (int ProductID) {
    for (int i=0; i<size ;i++) {
        if (Product[i].getProductID() == ProductID) {
            return &Product[i];
        }
    }

    return nullptr;
}

// Function to update Stock of a product
bool Inventory::updateStock(int productID, int newQuantity) {
    if (newQuantity < 0) {
        cout<<"Invalid stock quantity"<<endl;
        return false;
    }
    for (int i=0; i<size ; i++) {
        if (products[i].getProductId() == productID) {
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
        if (product[i].getProductID()== productID) {
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

