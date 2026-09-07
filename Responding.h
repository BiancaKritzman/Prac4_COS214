#ifndef PRAC4_COS214_RESPONDING_H
#define PRAC4_COS214_RESPONDING_H
#include "ResponderState.h"


class Responding : public ResponderState{
public:
    Responding();
    bool isAvailable() const override;
    void handleIncident() override;
    ~Responding() override;
};


#endif //PRAC4_COS214_RESPONDING_H
