#include <iostream>
#include "Card.h"
using namespace std;
class CardPayment : public Payment {
private:
    string cardNumber;

public:
    CardPayment(double amount, string cardNumber) : Payment(amount), cardNumber(cardNumber) {}

    bool processPayment() override {
        if (cardNumber.length() < 4) {
            cout << "Invalid card number.\n";
            paid = false;
            return false;
        }
        cout << "Card payment of " << fixed << setprecision(2) << amount << " OMR completed.\n";
        paid = true;
        return true;
    }

    void displayPaymentMethod() const override {
        cout << "Card Payment";
    }
};
