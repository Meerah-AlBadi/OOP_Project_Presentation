#include "Order.h"
int Order::orderCounter=1;
Order::Order(){
stringstream ss;
ss<<"O"<<orderCounter++;
orderID=ss.str();
payment=nullptr;
}

string Order::getOrderID() const{
  return orderID;
}
void Order::addItem(Product product, int quantity){
  orderItems.push_back(OrderItem(product,quantity));
}
double Order::calculateTotal() const{
  double total=0;
  for( const OrderItem& item: orderItems){
    total+=item.getSubtotal();
  }
  return total;
}

bool Order::isEmpty() const{
  return orderItems.empty();
}
void Order::returnItemsToInventory(Inventory& inventory) const{
  for (const OrderItems& item: orderItems){
    inventory.increaseStock(item.getProductID(),item.getQuantity());
  }
}

void Order::setPayment(Payment*p){
  if(payment!=nullptr){
    delete payment;
  }
  payment=p;
}

bool Order::pay(){
  if (payment==nullptr){
    cout<<"No payment method selected.\n";
    return false;
  }
  return payment->processPayment();
}

void Order::displayOrder() const{
  cout<<"\n============ORDER"<<orderID<<"=============\n";
  if (orderItems.empty()){
    cout<<"Order is empty.\n";
    return;
  }
  cout<<left<<setw(10)<<"ID"
      <<setw(25)<<"Product Name"
      <<setw(20)<<"Company"
      <<setw(10)<<"Price"
      <<setw(10)<<Qty"
      <<setw(10)<<"Subtotal"<<endl;
cout<<"----------------------------\n";

for(const OrderItem& item: orderItems){
  item.display();
}
cout<<"Total: "<<fixed<< setprecision(2)
    <<calculateTotal()<<"OMR\n";

cout<<"Payment: ";
if(payment!=nullptr){
  payment->displayPaymentMethod();
  cout<<endl;
}
else{ cout<<"Not selected\n";}
}

Order::~Order(){
    delete payment;
}
