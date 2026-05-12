// ----------------------MAIN--------------------------
 #include <iostream>
#include <string>
 using namespace std;

#include "User.h"
#include "Admin.h"
#include "Customer.h"
#include "Inventory.h"
#include "Product.h"
#include "Order.h"
#include "Payment.h"
 int main() {
     Inventory inventory; // Inventory object
     int option=-1;
     while (option !=0) {
         cout << "==== Gaming Store Management System ===="<<endl;
         cout << "1. Admin" << endl;
         cout << "2. Customer" << endl;
         cout << "0. Exit" << endl;
         cout <<  "Enter Your Chosen Option: ";
         cin >> option;

         // Erorr Handeling: 
         // if (cin.fail()) {        // Checks if input failed
         //     cin.clear();        //  Removes the error state so cin works again
         //     cin.ignore(1000,'\n');    // Deletes the wrong input from memory
         //     cout << "Invalid input!!" << endl << "Please enter a number." << endl;  // Display an error message
         //     continue;
         // }
      
         switch (option) {
             case 1: {
                 int AdminID;
                 string Admin_Name;

                 cout << "Enter Admin ID: ";
                 cin >> AdminID;

                 cout << "Enter Admin Name: ";
                 cin.ignore();
                 getline(cin,Admin_Name);

                 Admin admin(AdminID, Admin_Name, &inventory);

                 cout << endl<<"--- Admin Information ---" << endl;
                 admin.displayUser();

                 int Admin_Option=-1;

                 while (Admin_Option !=0) {
                     cout << "==== Admin Menu ====" << endl;
                     cout << "1.Add Product"<< endl;
                     cout << "2.Remove Product" << endl;
                     cout << "3.View Inventory"<< endl;
                     cout << "4.Update Product Stock" <<endl;
                     cout << "0.Back" << endl;
                     cout << "Enter Your Chosen Option: ";
                     cin >> Admin_Option;

                     // if (cin.fail()) {
                     //     cin.clear();
                     //     cin.ignore(1000,'\n');
                     //     cout << "Invalid input!! Please enter a number.";
                     //     continue;
                     // }

                     switch (Admin_Option) {
                         case 1: {
                             admin.Add_Product();
                             break;
                         }
                         case 2:
                             admin.Remove_Product();
                             break;
                         case 3:
                             admin.View_Inventory();
                             break;
                         case 4:
                             admin.Update_Product_Stock();
                             break;
                         case 0:
                             cout << "Returning to main menu"<<endl;
                             break;
                         default:
                             cout << "Invalid Choice! Try Again" << endl;
                     }
                 }
                 break;
         }

             case 2: {
                 int CustomerID;
                 string Customer_Name;

                 cout << "Enter Customer ID: ";
                 cin >> CustomerID;

                 cout << "Enter Customer Name: ";
                 cin.ignore();
                 getline(cin,Customer_Name);

                 Customer customer(CustomerID, Customer_Name);
                 cout << "--- Customer Information ---" << endl;
                 customer.displayUser();

                 int orderID, productID,quantity;

                 cout << "Enter Order ID: ";
                 cin >> orderID;

				             inventory.display_inventory();

                 cout << "Enter Product ID: ";
                 cin >> productID;

                 cout << "Enter Quantity:";
                 cin >> quantity;

                 Product* SelectedProduct = inventory.findProduct(productID);

                 if(SelectedProduct == nullptr) {
 					                     cout << "Product Not Found!" << endl;
					                      break;
				             }

                 string PaymentMethod;

                 int PaymentID;

                 cout << "Enter Payment ID: ";
                 cin >> PaymentID;

                 cout << "Enter Payment Method: ";
                 cin.ignore();
                 getline(cin,PaymentMethod);

				             double total = SelectedProduct-> getPrice() *quantity;

                 Payment payment(PaymentID, PaymentMethod,total);

				             Order order(orderID, &customer, SelectedProduct,quantity, payment);
                 order.displayOrder();

				             inventory.reduce_stock(productID, quantity);

                 cout << "Order Completed! Inventory updated successfully" <<endl;
                 break;
             }
          
             case 0: {
                 cout << "System Closed!" << endl;
                 break;
             }
          
             default:   // if input != 1,2,3,0 then this runs and print an error message
                 cout << "Invalid option!! Try Again" << endl;

         }

     }
     return 0;
 }
