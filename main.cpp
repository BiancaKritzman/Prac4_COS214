#include <iostream>

#include "ResponseTeam.h"
#include "Responder.h"
#include "EmergencyResponseSystem.h"
#include "Incident.h"
#include "PriorityDecorator.h"
#include "LogsDecorator.h"
#include "ResponseMovement.h"

using namespace std;

int main()
{
    cout << "----- TASKFORGE EMERGENCY RESPONSE SYSTEM -----" << endl;


    // create teams and responders

    ResponseTeam* root = new ResponseTeam(Medical);

    ResponseTeam* gautengTeam = new ResponseTeam(Medical);
    ResponseTeam* pretoriaTeam = new ResponseTeam(Medical);
    ResponseTeam* medicalTeam = new ResponseTeam(Medical);

    Responder* medicalResponder1 = new Responder(Medical);
    Responder* medicalResponder2 = new Responder(Medical);
    Responder* policeResponder = new Responder(Police);


    //add responders to teams

    medicalTeam->addResponse(medicalResponder1);
    medicalTeam->addResponse(medicalResponder2);

    pretoriaTeam->addResponse(medicalTeam);
    pretoriaTeam->addResponse(policeResponder);

    gautengTeam->addResponse(pretoriaTeam);
    root->addResponse(gautengTeam);


    EmergencyResponseSystem system(root);


    // SCENARIO 1---------------------------------------

    cout << "\n----- SCENARIO 1: MEDICAL EMERGENCY -----" << endl;

    Incident* incident = new Incident("Person injured in road accident", "Pretoria CBD", Medical);

    system.reportIncident(incident);

    cout << "\nDispatching responder..." << endl;
    system.dispatchIncident();

    cout << "\nCompleting incident..." << endl;
    system.completeIncident();


    // decorated responder

    cout << "\n----- DECORATED RESPONDER -----" << endl;

    Responder* decoratedResponder = new Responder(Fire);
    PriorityDecorator* priority = new PriorityDecorator(decoratedResponder);
    LogsDecorator* logs = new LogsDecorator(priority);

    logs->checkIn();


    // SCENARIO 2-------------------------------

    cout << "\n----- SCENARIO 2: RUNTIME STRUCTURE CHANGE -----" << endl;


    // snapshot before change
    ResponseMovement* snapshot = root->createMovement("snapshot");
    snapshot->first();

    cout << "\nSnapshot created." << endl;


    // add responder after snapshot
    Responder* newMedicalResponder = new Responder(Medical);
    medicalTeam->addResponse(newMedicalResponder);

    cout << "New medical responder added." << endl;


    // go through old snapshot
    cout << "\nSnapshot traversal:" << endl;

    while (!snapshot->isDone())
    {
        ResponseComponent* current = snapshot->currentItem();

        if (current != nullptr)
        {
            current->checkIn();
        }

        snapshot->next();
    }

    delete snapshot;


    // go through live traversal

    cout << "\nLive traversal:" << endl;

    ResponseMovement* live = root->createMovement("live");
    live->first();

    while (!live->isDone())
    {
        ResponseComponent* current = live->currentItem();

        if (current != nullptr)
        {
            current->checkIn();
        }

        live->next();
    }

    delete live;


    delete incident;
    delete root;

    delete logs;
    delete priority;
    delete decoratedResponder;

    return 0;
}