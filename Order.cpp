#include<iostream>
using namespace std;
class Order{
private:
  int quantity;
  string name;
  Payment payment; //composition 

public:
  void input(){
    cout<<"enter name of product: ";
    cin>>name;
    cout<<"enter quantity: ";
    cin>>quantity;

    payment.inputPayment();
  }

void display(){
  cout<<"product: "<<name<<endl;
  cout<<"quantity: "<<quantity<<endl;

  payment.displayPayment();
}

};

int main(){
  Order n;
  n.input();
  n.display();
  return 0;
}
