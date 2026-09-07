//
// Created by Steev on 2026/09/07.
//

#ifndef PRAC4_COS214_AMBULANCERESPONSEMOVEMENT_H
#define PRAC4_COS214_AMBULANCERESPONSEMOVEMENT_H
#include "ResponseMovement.h"


class LiveResponseMovement : public ResponseMovement {
public:
    void first() override;
    void next() override;
    bool isDone() override;
    ResponseComponent* currentItem() override;
};


#endif //PRAC4_COS214_AMBULANCERESPONSEMOVEMENT_H
