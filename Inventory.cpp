#include "Inventory.h"

Inventory::Inventory() {
    count=0;
}
void Inventory::add_product(Product prdct, int qty) {
    products[count]=prdct;
    quantities[count]=qty;
    count++;
}