#include "Inventory.h"
#include <iostream>
using namespace std;

Inventory::Inventory() {
    count=0;
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
        products[count]=prdct;
        quantities[count]=qty;
        count++;
    }
void Inventory::reduce_stock(int id,int amount) {
    if (amount<=0) {
        cout<<"Invalid amount"; //exception handling for purchase amount
        return;
    }
    for (int i=0;i<count;i++) {
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
        cout<<products[i].get_ID()<<" "<<quantities[i]<<endl;
    }
}
