#ifndef PRAC4_COS214_RESPONDER_H
#define PRAC4_COS214_RESPONDER_H
#include "ResponseComponent.h"
#include "ResponderState.h"
#include "Incident.h"
#include <string>

class Responder : public ResponseComponent {
private:
    ResponderState* currentState;
    public:
        void setState(ResponderState* state);
        Responder(Type type);
        bool isAvailable() const;
        void completeIncident();
        void checkIn();
        void handleIncident(Incident* incident, string method);
        ~Responder();
};


#endif //PRAC4_COS214_RESPONDER_H
