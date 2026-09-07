#ifndef PRAC4_COS214_MOTORBIKERESPONSEMOVEMENT_H
#define PRAC4_COS214_MOTORBIKERESPONSEMOVEMENT_H

#include "ResponseMovement.h"
#include "ResponseTeam.h"

class SnapshotResponseMovement : public ResponseMovement {
private:
    vector<ResponseComponent*> snapshot;
    int position;
    void buildSnapshot(ResponseComponent* component);
public:
    explicit SnapshotResponseMovement(ResponseTeam* root);
    void first() override;
    void next() override;
    bool isDone() override;
    ResponseComponent* currentItem() override;
    ~SnapshotResponseMovement() override;
};


#endif //PRAC4_COS214_MOTORBIKERESPONSEMOVEMENT_H
