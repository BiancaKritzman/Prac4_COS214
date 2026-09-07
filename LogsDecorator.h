#ifndef PRAC4_COS214_LOGSDECORATOR_H
#define PRAC4_COS214_LOGSDECORATOR_H
#include "EmergencyDecorator.h"


class LogsDecorator : public EmergencyDecorator {
public:
    LogsDecorator(ResponseComponent* component);
    void checkIn() override;
    ~LogsDecorator() override;
};


#endif //PRAC4_COS214_LOGSDECORATOR_H
