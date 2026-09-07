#ifndef PRAC4_COS214_RESPONSETEAM_H
#define PRAC4_COS214_RESPONSETEAM_H
#include "ResponseComponent.h"
#include "ResponseMovement.h"
#include <string>
using namespace std;

class ResponseTeam : public ResponseComponent {
private:
    friend class LiveResponseMovement;
    friend class SnapshotResponseMovement;
    vector<ResponseComponent*> responses;
public:
        ResponseTeam(Type type) : ResponseComponent(type) {};
        void addResponse(ResponseComponent* response);
        void removeResponse(ResponseComponent* response);
        void checkIn() override;
        ResponseMovement* createMovement(string method);
        ~ResponseTeam();
};


#endif //PRAC4_COS214_RESPONSETEAM_H
