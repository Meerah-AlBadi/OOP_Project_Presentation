//Inventory class
class Inventory {
private:
    Product products[100]; //stores all products in inventory
    int quantities[100]; //stores each products quantity
    int count; //checks the number of products in inventory
public:
    Inventory(); //constructor
    void add_product(Product prdct, int qty); //adds product function
    void reduce_stock(int id,int amount); //reduce stock function
};