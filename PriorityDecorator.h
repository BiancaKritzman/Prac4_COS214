#ifndef PRAC4_COS214_PRIORITYDECORATOR_H
#define PRAC4_COS214_PRIORITYDECORATOR_H
#include "EmergencyDecorator.h"

class PriorityDecorator : public EmergencyDecorator {
public:
    PriorityDecorator(ResponseComponent* component);
    void checkIn() override;
    ~PriorityDecorator() override;
};

#endif //PRAC4_COS214_PRIORITYDECORATOR_H
