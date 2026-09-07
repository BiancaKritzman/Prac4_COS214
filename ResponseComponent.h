#ifndef PRAC4_COS214_RESPONSECONTAINER_H
#define PRAC4_COS214_RESPONSECONTAINER_H

#include <vector>

#include "Type.h"
using namespace std;

class ResponseComponent {
    protected:
    Type type;
    public:
        ResponseComponent(Type type);
        Type getType() const { return this->type; };
        virtual void checkIn() = 0;
        virtual ~ResponseComponent() {};
};

#endif //PRAC4_COS214_RESPONSECONTAINER_H
