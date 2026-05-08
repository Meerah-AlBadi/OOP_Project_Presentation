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
