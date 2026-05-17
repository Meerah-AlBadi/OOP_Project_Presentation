#ifndef CARD_H
#define CARD_H
#include <iostream>
#include<iomanip>
#include <string>
using namespace std;

class Payment{
protected:
double amont;
bool paid;
public:
Payment(double amount): amount(amount),paid(false){}
virtual bool processPayment() = 0; 
virtual void displayPaymentMethod() const = 0;

bool isPaid() const { return paid; }
double getAmount() const { return amount; }
virtual ~Payment() {}
};

class CardPayment : public Payment {
private:
string cardNumber;
public:
    CardPayment(double amount, string cardNumber);
    bool processPayment() override;
    void displayPaymentMethod() const override;
};
#endif
