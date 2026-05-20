#ifndef CARD_H
#define CARD_H
#include <iostream>
#include<iomanip>
#include <string>
#include "Payment.h"
using namespace std;

class CardPayment : public Payment {
private:
string cardNumber;
public:
    CardPayment(double amount, string cardNumber);
    bool processPayment() override;
    void displayPaymentMethod() const override;
};
#endif
