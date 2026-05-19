#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H

#include "Product.h"
#include <string>
using namespace std;

class InventoryItem {
    Product product;      // Composition because (HAS-A "strong") - Stores all the product Info
    int quantity;
public:
    InventoryItem(Product pr, int quan);

    Product getProduct() const;      // return product information const => because it is not editable from here

    Product& getProduct();    // allows modification (REFRENCE)

    int getQuantity();    // returns quantity of the product

    bool setQuantity(int quan);    // a setter function to set quantity of an object, boolean because it alse doas a small validation

    bool reduceQuantity(int re_amount);     //reduces quantity of a product "when an order is made"

    void display() const;   //Print Product Info (calling a method in Product )  + quantity

};

#endif
