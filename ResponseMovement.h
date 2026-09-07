#ifndef PRAC4_COS214_RESPONSEMOVEMENT_H
#define PRAC4_COS214_RESPONSEMOVEMENT_H
#include "ResponseComponent.h"

class ResponseMovement
{
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() = 0;
    virtual ResponseComponent* currentItem() = 0;
    virtual ~ResponseMovement();
};


#endif //PRAC4_COS214_RESPONSEMOVEMENT_H
