#ifndef PRAC4_COS214_AVAILABLE_H
#define PRAC4_COS214_AVAILABLE_H
#include "ResponderState.h"


class Available : public ResponderState{
    public:
    Available();
    void handleIncident() override;
    ~Available() override;
};


#endif //PRAC4_COS214_AVAILABLE_H
