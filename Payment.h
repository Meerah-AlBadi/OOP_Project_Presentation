#ifndef PAYMENT_H
#define PAYMENT_H

class Payment {
protected:
double amount;
bool paid;
public:
    Payment(double amount);
virtual bool processPayment() = 0;
virtual void displayPaymentMethod() const = 0;
bool isPaid() const;
virtual ~Payment() {}
};
#endif
