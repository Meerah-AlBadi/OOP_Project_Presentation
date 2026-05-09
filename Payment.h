#ifndef PAYMENT_H
#define PAYMENT_H
#include <iostream>
using namespace std;
class Payment{
private:
int idPayment;
string methodPayment;
double amount;
public:
Payment();
Payment(int id, string method, double a);
void displayPayment();
void processPayment();
};
#endif
