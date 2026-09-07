#include "EmergencyResponseSystem.h"
#include "ResponseMovement.h"
#include "Responder.h"

#include <iostream>

EmergencyResponseSystem::EmergencyResponseSystem(ResponseTeam* responseNetwork): currentIncident(nullptr),responseNetwork(responseNetwork) {}

void EmergencyResponseSystem::reportIncident(Incident* incident) {
    if (incident == nullptr) {
        return;
    }
    if (currentIncident != nullptr) {
        completeIncident();
    }
    currentIncident = incident;
    std::cout << "Incident reported: "<< incident->description << std::endl;
    std::cout << "Location: "<< incident->address << std::endl;
}

void EmergencyResponseSystem::dispatchIncident() {
    if (currentIncident == nullptr) {
        std::cout << "No incident to dispatch." << std::endl;
        return;
    }

    if (responseNetwork == nullptr) {
        std::cout << "No response network available." << std::endl;
        return;
    }

    ResponseMovement* movement = responseNetwork->createMovement("live");
    movement->first();
    while (!movement->isDone()) {
        ResponseComponent* component = movement->currentItem();
        Responder* responder = dynamic_cast<Responder*>(component);
        if (responder != nullptr) {
            if (responder->getType() == currentIncident->type && responder->isAvailable()) {
                responder->handleIncident(currentIncident, "dispatch");
            }
        }
        movement->next();
    }
    delete movement;
}

void EmergencyResponseSystem::completeIncident() {
    if (currentIncident == nullptr || responseNetwork == nullptr) {
        return;
    }
    ResponseMovement* movement = responseNetwork->createMovement("live");
    movement->first();
    while (!movement->isDone()) {
        ResponseComponent* component = movement->currentItem();
        Responder* responder = dynamic_cast<Responder*>(component);
        if (responder != nullptr && responder->getType() == currentIncident->type) {
            if (!responder->isAvailable()) {
                responder->completeIncident();
            }
        }
        movement->next();
    }
    delete movement;

    currentIncident = nullptr;
}

void EmergencyResponseSystem::attendance() {
    if (responseNetwork == nullptr) {
        return;
    }
    ResponseMovement* movement = responseNetwork->createMovement("snapshot");
    movement->first();
    while (!movement->isDone()) {
        ResponseComponent* component = movement->currentItem();
        component->checkIn();
        movement->next();
    }
    delete movement;
}

EmergencyResponseSystem::~EmergencyResponseSystem() {}