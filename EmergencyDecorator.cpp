//
// Created by Steev on 2026/09/07.
//

#include "EmergencyDecorator.h"

EmergencyDecorator::EmergencyDecorator(ResponseComponent* component)
    : response(component)
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