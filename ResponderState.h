#ifndef PRAC4_COS214_RESPONDERSTATE_H
#define PRAC4_COS214_RESPONDERSTATE_H


class ResponderState {
    public:
    ResponderState();
    virtual void handleIncident() = 0;
    virtual ~ResponderState();
};


#endif //PRAC4_COS214_RESPONDERSTATE_H
