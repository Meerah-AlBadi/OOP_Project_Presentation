#include <iostream>
#include "Payment.h"
using namespace std;
class Payment {
protected:
    double amount;
    bool paid;
public:
    Payment(double amount) : amount(amount), paid(false) {}

    virtual bool processPayment() = 0;
    virtual void displayPaymentMethod() const = 0;

    bool isPaid() const {
        return paid;
    }
    virtual ~Payment() {}
};
