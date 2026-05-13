//Inventory class
#ifndef INVENTORY_H
#define INVENTORY_H

#include "Product.h"
#include <vector>
class Inventory {
private:
    vector<Product> products; //stores all products in inventory
	vector<int> quantities; //stores each products quantity
    int size; //checks the number of products in inventory
public:
    Inventory(); //constructor
    void add_product(Product prdct, int qty); //adds product function
    void reduce_stock(int id,int amount); //reduce stock function
    void display_inventory(); //displays inventory funtion
    Product* findProduct(int ProductID); //find product declaration
	bool updateStock(int productID, int newQuantity); //update stock declaration
	bool removeProduct(int productID); //remove product declaration
};

#endif
