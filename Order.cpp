#include <iostream>
#include "Order.h"
using namespace std;
Order:: Order() {
OrderID =0;
customer = nullptr;
product = nullptr;
quantity =0;
total =0;
}

Order:: Order(int id, Customer* c, Product* p, int quan, Payment pay): OrderID(id), customer(c), product(p), quantity(quan),payment(pay) {}

void Order:: displayOrder() {
cout << "==== Order details ====" << endl;
cout << "Order ID: "<< OrderID << endl;
cout << "Customer Name: " << customer ->getName() << endl;
cout << "Product Name: " << product -> getProductName() << endl;
cout << "Quantity of bought product : " << quantity << endl;
cout << "Total " << total << "OMR "<<endl;
payment.displayPayment(); //Prints Payment Details of the order
}
