#include "Inventory.h"

Inventory::Inventory() {
    count=0;
}
void Inventory::add_product(Product prdct, int qty) {
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