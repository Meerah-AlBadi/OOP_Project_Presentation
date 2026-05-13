//Inventory class
#ifndef INVENTORY_H
#define INVENTORY_H

#include "Product.h"
#include <vector>

class Inventory {
private:
    std::vector<Product> products; //stores all products in inventory
	std::vector<int> quantities; // stores quantity of each product
public:
    Inventory(); //constructor
	~Inventory(); //destructor
    void add_product(Product prdct, int qty); //adds product function
    void reduce_stock(int id,int amount); //reduce stock function
    void display_inventory(); //displays inventory function
    Product* findProduct(int ProductID); //find product declaration
	bool updateStock(int productID, int newQuantity); //update stock declaration
	bool removeProduct(int productID); //remove product declaration
};

#endif
