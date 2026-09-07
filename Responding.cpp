#include "Responding.h"
#include <iostream>

using namespace std;

Responding::Responding() {}

bool Responding::isAvailable() const {
    return false;
}

void Responding::handleIncident() {
    cout << "Responder is currently responding to an incident." << endl;
}

Responding::~Responding() {}