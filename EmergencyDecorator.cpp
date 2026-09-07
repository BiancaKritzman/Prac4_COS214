//
// Created by Steev on 2026/09/07.
//

#include "EmergencyDecorator.h"
#include "ResponseComponent.h"

EmergencyDecorator::EmergencyDecorator(ResponseComponent* component)
    : ResponseComponent(component->getType()), response(component)
{
}

void EmergencyDecorator::checkIn()
{
    if (response != nullptr) {
        response->checkIn();
    }
}

EmergencyDecorator::~EmergencyDecorator()
{
}