#ifndef PRAC4_COS214_INCIDENT_H
#define PRAC4_COS214_INCIDENT_H
#include <string>
#include "Type.h"
using namespace std;


class Incident {
    public:
    string description;
    string address;
    Type type;
    Incident(string description, string address, Type type);
    ~Incident();
};


#endif //PRAC4_COS214_INCIDENT_H
