#ifndef CASH_H
#define CASH_H
#include <iostream>
#include <iomanip>
#include "Payment.h"
using namespace std;
class CashPayment : public Payment {
public:
    CashPayment(double amount);
    bool processPayment() override;
    void displayPaymentMethod() const override;
};
#endif
