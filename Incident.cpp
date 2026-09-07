#include "Incident.h"

#include "ResponseComponent.h"

Incident::Incident(string description, string address, Type type)
    : description(description), address(address), type(type) {
}

Incident::~Incident() {}