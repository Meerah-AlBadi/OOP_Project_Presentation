#ifndef CASH_H
#define CASH_H
#include <iostream>
#include <iomanip>

using namespace std;
class Payment {
protected:
double amount;
bool paid;
public:
    Payment(double amount) : amount(amount), paid(false) {}
    virtual bool processPayment() = 0;
    virtual void displayPaymentMethod() const = 0;
    bool isPaid() const { return paid; }
    double getAmount() const { return amount; }
    virtual ~Payment() {}
};
class CashPayment : public Payment {
public:
    CashPayment(double amount);
    bool processPayment() override;
    void displayPaymentMethod() const override;
};
#endif
