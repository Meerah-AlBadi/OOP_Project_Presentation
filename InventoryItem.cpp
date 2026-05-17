#include "InventoryItem.h"

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


InventoryItem::InventoryItem(Product pr, int quan) {
    product = pr;

    if (quan <0 )
        quantity =0;
    else
        quantity = quan;
}

Product InventoryItem::getProduct() const {
    return product;
}

Product& InventoryItem::getProduct() {
    return product;
}

int InventoryItem::getQuantity() {
    return quantity;
}

bool InventoryItem::setQuantity(int quan) {
    if (quan <0 ) {
        cout << "Invalid Quantity!" << endl;
        return false;
    }
    
    quantity = quan;
    return true;
}


bool InventoryItem::reduceQuantity(int re_amount) {
    if (re_amount <= 0) {
        cout << "Invalid Quantity amount!" <<endl;
        return false;
    }
    
    if (re_amount > quantity) {
        cout << "Not enough product stick! " << endl;
        return false;
    }
    quantity -= re_amount;
    return true;
}

void InventoryItem::display() const {
    product.display();
    cout << setw(10) << quantity << endl;
}
