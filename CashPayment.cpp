#include <iostream>
#include "CashPayment.h"
using namespace std;
class CashPayment : public Payment {
public:
    CashPayment(double amount) : Payment(amount) {}

    bool processPayment() override {
        cout << "Cash payment of " << fixed <<setprecision(2)<< amount << " OMR completed.\n";
        paid = true;
        return true;
    }

    void displayPaymentMethod() const override {cout << "Cash Payment"; }
};
