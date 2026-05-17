#include "OrderItem.h"

#include <iostream>
#include <iomanip>
using namespace std;

OrderItem::OrderItem(Product pr, int quan) {

    product= pr;

    if (quan <0) {
        quantity =0;
    }
    else
        quantity = quan;

}

string OrderItem::getProductID() const {
    return product.getProductID();
}

int OrderItem::getQuantity() const {
    return quantity;
}

double OrderItem::getSubtotal() const {
    return product.getPrice()*quantity;
}

void OrderItem::display() const {
    product.display();
    cout << setw(10) << quantity << setw(10) << getSubtotal() << endl;
}
