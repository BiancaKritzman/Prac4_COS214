#include "Responder.h"
#include "Available.h"
#include "Responding.h"
#include <iostream>

using namespace std;

Responder::Responder(Type type) : ResponseComponent(type){
    currentState = new Available();
}

void Responder::setState(ResponderState* state) {
    if (currentState != nullptr) {
        delete currentState;
    }
    currentState = state;
}

void Responder::checkIn() {
    if (currentState != nullptr) {
        currentState->handleIncident();
    }
}

bool Responder::isAvailable() const {
    return currentState != nullptr &&
           currentState->isAvailable();
}

void Responder::completeIncident() {
    setState(new Available());
}

void Responder::handleIncident(Incident* incident, string method) {
    if (incident == nullptr) {
        return;
    }
    cout << "Responder handling incident: "<< incident->description << endl;
    setState(new Responding());
    currentState->handleIncident();
}

Responder::~Responder() {
    delete currentState;
}