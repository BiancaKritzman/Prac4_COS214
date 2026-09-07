#ifndef PRAC4_COS214_EMERGENCYDECORATOR_H
#define PRAC4_COS214_EMERGENCYDECORATOR_H
#include "ResponseComponent.h"


class EmergencyDecorator : public ResponseComponent {
protected:
    ResponseComponent* response;
    public:
    EmergencyDecorator(ResponseComponent* component);
    void checkIn() override;
    virtual ~EmergencyDecorator();
};


#endif //PRAC4_COS214_EMERGENCYDECORATOR_H
