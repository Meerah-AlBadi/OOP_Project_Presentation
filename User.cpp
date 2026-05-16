#include "User.h"

// Default constructor
User::User() {
    id = "";
    name = "";
    password = "";
}

// Parameterized constructor
User::User(string name, string password)
    : name(name), password(password) {
}

// Getter for ID
string User::getId() const {
    return id;
}

// Getter for name
string User::getName() const {
    return name;
}

// Login function
bool User::login(string enteredId, string enteredPassword) const {
    return id == enteredId && password == enteredPassword;
}

// Destructor
User::~User() {
}
