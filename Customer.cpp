#include "Customer.h"

#include <iostream>
#include <string>
using namespace std;


// Initialize static variable
int Customer::customerCounter = 1;

// Default constructor
Customer::Customer() : User() {
}

// Parameterized constructor
Customer::Customer(string name, string password)
    : User(name, password) {

    stringstream ss;
    ss << "C" << customerCounter++;
    id = ss.str();
}

// Show menu
void Customer::showMenu() {
    cout << "\n=========== CUSTOMER MENU ===========\n";
    cout << "1. View Products\n";
    cout << "2. Place Order\n";
    cout << "3. View Order History\n";
    cout << "0. Logout\n";
    cout << "Choose: ";
}

// View products
void Customer::viewProducts(const Inventory& inventory) const {
    inventory.displayInventory();
}

// Place order
void Customer::placeOrder(Inventory& inventory) {

    Order* order = new Order();
    char addMore;

    do {
        string productID;
        int quantity;

        inventory.displayInventory();

        cout << "Enter product ID: ";
        cin >> productID;

        Product* product = inventory.findProduct(productID);

        if (product == nullptr) {
            cout << "Product not found.\n";
        }
        else {

            cout << "Enter quantity: ";
            cin >> quantity;

            if (quantity <= 0) {
                cout << "Invalid quantity.\n";
            }
            else if (inventory.isAvailable(productID, quantity)) {

                order->addItem(*product, quantity);
                inventory.reduceStock(productID, quantity);

                cout << "Product added to order.\n";
            }
            else {
                cout << "Not enough stock.\n";
            }
        }

        cout << "Add another product? (y/n): ";
        cin >> addMore;

    } while (addMore == 'y' || addMore == 'Y');

    if (order->isEmpty()) {

        cout << "Order cancelled because it is empty.\n";

        delete order;
        return;
    }

    order->displayOrder();

    int paymentChoice;

    cout << "\nChoose payment method:\n";
    cout << "1. Cash\n";
    cout << "2. Card\n";
    cout << "Choose: ";

    cin >> paymentChoice;

    double total = order->calculateTotal();

    // Cash payment
    if (paymentChoice == 1) {

        order->setPayment(new CashPayment(total));
    }

    // Card payment
    else if (paymentChoice == 2) {

        string cardNumber;
        bool validCard = false;

        for (int attempt = 1; attempt <= 3; attempt++) {

            cout << "Enter card number (attempt "
                 << attempt << " of 3): ";

            cin >> cardNumber;

            if (cardNumber.length() >= 4) {

                validCard = true;
                break;
            }

            cout << "Invalid card number. Try again.\n";
        }

        if (!validCard) {

            cout << "Card payment failed after 3 attempts. "
                 << "Order cancelled.\n";

            order->returnItemsToInventory(inventory);

            delete order;
            return;
        }

        order->setPayment(
            new CardPayment(total, cardNumber)
        );
    }

    // Invalid payment choice
    else {

        cout << "Invalid payment choice. Order cancelled.\n";

        order->returnItemsToInventory(inventory);

        delete order;
        return;
    }

    // Payment process
    if (order->pay()) {

        orders.push_back(order);

        cout << "Order placed successfully. Order ID: "
             << order->getOrderID() << endl;
    }
    else {

        cout << "Payment failed. Order cancelled.\n";

        order->returnItemsToInventory(inventory);

        delete order;
    }
}

// View order history
void Customer::viewOrderHistory() const {

    if (orders.empty()) {

        cout << "No orders found.\n";
        return;
    }

    for (const Order* order : orders) {

        order->displayOrder();
    }
}

// Destructor
Customer::~Customer() {

    for (Order* order : orders) {

        delete order;
    }
}
