#ifndef PRAC4_COS214_RESPONSETEAM_H
#define PRAC4_COS214_RESPONSETEAM_H
#include "ResponseComponent.h"
#include "ResponseMovement.h"
#include <string>
using namespace std;

class ResponseTeam : public ResponseComponent {
private:
    Type type;
    vector<ResponseComponent*> responses;
    public:
        ResponseTeam();
        void addResponse(ResponseComponent* response);
        void removeResponse(ResponseComponent* response);
        void checkIn() override;
        ResponseMovement* createMovement(string method);
        vector<ResponseComponent*> getChildren();
        ~ResponseTeam();
};


#endif //PRAC4_COS214_RESPONSETEAM_H
