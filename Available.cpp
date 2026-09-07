#include "Available.h"
#include <iostream>
using namespace std;
Available::Available() {}

void Available::handleIncident() {
    cout << "Responder is available and can handle the incident." << endl;
}

Available::~Available() {}