#include "Admin.h"


#include <string>
using namespace std;

// Initialize static variable
int Admin:: adminCounter =1;

Admin::Admin() : User(){inventory = nullptr;}     // Default constructor

Admin::Admin (int id, string name, Inventory* inv) : User(id, name) {inventory =inv;}    // Parameterized constructor


void Admin::showMenu() {     // ShowS Admin's Menu 

    cout << "\n=========== ADMIN MENU ===========\n";

    cout << "1. Add Product\n";
    cout << "2. View Inventory\n";
    cout << "3. Update Product Stock\n";
    cout << "4. Update Product Price\n";
    cout << "5. Remove Product\n";
    cout << "0. Logout\n";
    cout << "Choose: ";
}


void Admin::addProduct() {
    int quantity;
    string ProductName, CompanyName;
    double price;

    cout << "Enter Product Name: ";
    cin.ignore();
    getline(cin,ProductName);

    cout << "Enter Product's Comapny Name: ";
    cin.ignore();
    getline(cin,CompanyName);
    
    cout << "Enter Product Price: ";
    cin >> price;

    cout << "Enter Product Quantity: ";
    cin >> quantity;

    // Validation - In case pricee is 0 or -ive "or" quantity is 0 or -ive
    if (price < 0 || quantity < 0) {

        cout << "Invalid price or quantity.\n";
        return;
    }

    Product product(ProductName,CompanyName,price);
    inventory->add_product(product,quantity);
}


void Admin::viewInventory() const{
    inventory->display_inventory();
}


void Admin::updateProductStock() {
    string ProductID;
    int quantity;

    cout << "Enter Product ID: ";
    cin >> ProductID;

    cout << "Enter new quantity of Product:";
    cin >> quantity;
    
    inventory -> updateStock(ProductID,quantity);
}

void Admin::removeProduct() {
    int ProductID;

    cout << "Enter Product ID to remove: ";
    cin >> ProductID;

    inventory -> removeProduct(ProductID);
}

void Admin::updateProductPrice() {
    string productID;
    double newPrice;

    cout << "Enter Product ID: ";
    cin >> productID;

    inventory->updatePrice(productID,price);
}
