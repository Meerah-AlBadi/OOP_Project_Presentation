#ifndef ORDERITEM_H
#define ORDERITEM_H

#include "Product.h"
#include <string>
using namespace std;


class OrderItem {
    product product;       // Composition (OrderItem HAS-A Product )
    int quantity;
public:
    OrderItem(Product pr, int quan);     //Constructor (Takes a product object + quantity )

    string getProductID() const;    // return Product Id (calle from the Product class)

    int getQuantity() const;      // return the quantity of an ordered Product

    double getSubtotal() const;     //Calculates the total price using quamtity of one product

    void display() const;    // Shows information of one tyoe of ordered product
};

#endif
