#include "LogsDecorator.h"

#include <iostream>

LogsDecorator::LogsDecorator(ResponseComponent* component)
    : EmergencyDecorator(component)
{
}

void LogsDecorator::checkIn()
{
    std::cout << "[LOG] Response activity recorded." << std::endl;

    if (response != nullptr) {
        response->checkIn();
    }

    std::cout << "[LOG] Response activity completed." << std::endl;
}

LogsDecorator::~LogsDecorator()
{
}