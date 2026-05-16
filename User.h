#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User {
protected:
    string id;
    string name;
    string password;

public:
    // Default constructor
    User();

    // Parameterized constructor
    User(string name, string password);

    // Getter functions
    string getId() const;
    string getName() const;

    // Login function
    bool login(string enteredId, string enteredPassword) const;

    // Pure virtual function
    virtual void showMenu() = 0;

    // Virtual destructor
    virtual ~User();
};

#endif
