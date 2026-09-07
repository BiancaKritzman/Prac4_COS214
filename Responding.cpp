#include "Responding.h"
#include <iostream>

using namespace std;

Responding::Responding() {
}

void Responding::handleIncident() {
    cout << "Responder is currently responding to an incident." << endl;
}

Responding::~Responding() {
}