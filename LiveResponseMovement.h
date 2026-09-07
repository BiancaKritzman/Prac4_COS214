#ifndef PRAC4_COS214_AMBULANCERESPONSEMOVEMENT_H
#define PRAC4_COS214_AMBULANCERESPONSEMOVEMENT_H
#include "ResponseMovement.h"
#include "ResponseTeam.h"

class LiveResponseMovement : public ResponseMovement {
private:
    ResponseTeam* root;
    vector<ResponseComponent*> traversal;
    int position;
    void buildTraversal(ResponseComponent* component);
public:
    explicit LiveResponseMovement(ResponseTeam* root);
    void first() override;
    void next() override;
    bool isDone() override;
    ResponseComponent* currentItem() override;
    ~LiveResponseMovement() override;
};


#endif //PRAC4_COS214_AMBULANCERESPONSEMOVEMENT_H
