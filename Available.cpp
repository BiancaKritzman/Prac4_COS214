#include "Available.h"
#include <iostream>
using namespace std;
Available::Available() {}

bool Available::isAvailable() const {
    return true;
}

void Available::handleIncident() {
    cout << "Responder is available and can handle the incident." << endl;
}

Available::~Available() {}