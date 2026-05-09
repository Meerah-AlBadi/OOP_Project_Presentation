#include <iostream>
#include "Payment.h"
using namespace std;
Payment::Payment(){
  idPayment=0;
  methodPayment="";
  amount=0;
}
Payment::Payment(int id, string method, double a)
: idPayment(id), methodPayment(method), amount(a){}

void Payment::displayPayment(){
  cout << "--- Payment Details ---"<<endl;
  cout<<"Payment ID: "<<idPayment<<endl;
  cout <<"Payment Method: "<<methodPayment<<endl;
  cout<< "Amount: OMR" <<amount<<endl;
}
