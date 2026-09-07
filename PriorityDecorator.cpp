#include "PriorityDecorator.h"
#include <iostream>

PriorityDecorator::PriorityDecorator(ResponseComponent* component)
    : EmergencyDecorator(component)
{
}

void PriorityDecorator::checkIn()
{
    std::cout << "[PRIORITY] High-priority response activated." << std::endl;

    if (response != nullptr) {
        response->checkIn();
    }
}

PriorityDecorator::~PriorityDecorator()
{
}