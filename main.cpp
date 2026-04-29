//temporary draft only for testing purposes
#include "Inventory.h"
#include <iostream>
using namespace std;

int main() {
    Inventory inventory; //Inventory object
    int qty,id;
    cout<<"Enter the ID of the product:";
    cin>>id;
    cout<<"Enter quantity:";
    cin>>qty;
    if (qty<=0) {
        cout<<"Invalid input";
        return 0;
    }
    Product p(id); //temporary until Product class is created
    inventory.add_product(p,qty);
    int amount_purchase;
    cout<<"Enter amount to purchase:";
    cin>>amount_purchase;
    if (amount_purchase<=0) {
        cout<<"Invalid input";
        return 0;
    }
    inventory.reduce_stock(id,amount_purchase);
    inventory.display_inventory();
    return 0;
}
