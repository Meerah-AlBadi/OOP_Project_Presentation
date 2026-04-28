//Inventory class
class Inventory {
private:
    Product products[100]; //array stores all products in inventory
    int quantities[100]; //array stores each products quantity
    int count; //checks the number of products in inventory
public:
    Inventory();
    void addProduct(Product prdct, int qty);

};