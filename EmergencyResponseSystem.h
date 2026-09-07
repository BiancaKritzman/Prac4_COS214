#ifndef PRAC4_COS214_EMERGENCYRESPONSESYSTEM_H
#define PRAC4_COS214_EMERGENCYRESPONSESYSTEM_H
#include "Incident.h"
#include "ResponseTeam.h"

class EmergencyResponseSystem {
private:
    Incident* currentIncident;
    ResponseTeam* responseNetwork;
public:
    explicit EmergencyResponseSystem(ResponseTeam* responseNetwork);
    void reportIncident(Incident* incident);
    void dispatchIncident();
    void attendance();
    void completeIncident();
    ~EmergencyResponseSystem();
};


#endif //PRAC4_COS214_EMERGENCYRESPONSESYSTEM_H
