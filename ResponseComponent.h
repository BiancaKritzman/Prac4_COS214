#ifndef PRAC4_COS214_RESPONSECONTAINER_H
#define PRAC4_COS214_RESPONSECONTAINER_H

#include <vector>

#include "Type.h"
using namespace std;

class ResponseComponent {
    public:
        ResponseComponent();
        virtual void checkIn() = 0;
        virtual ~ResponseComponent();
};

#endif //PRAC4_COS214_RESPONSECONTAINER_H
