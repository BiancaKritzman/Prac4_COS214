#ifndef PRAC4_COS214_MOTORBIKERESPONSEMOVEMENT_H
#define PRAC4_COS214_MOTORBIKERESPONSEMOVEMENT_H

#include "ResponseMovement.h"

class SnapshotResponseMovement : public ResponseMovement {
public:
    void first() override;
    void next() override;
    void isDone() override;
    void currentItem() override;
};


#endif //PRAC4_COS214_MOTORBIKERESPONSEMOVEMENT_H
