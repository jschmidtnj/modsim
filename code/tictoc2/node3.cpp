/*
 * node3.cpp
 *
 *  Created on: Feb 6, 2020
 *      Author: joshua
 */

#include <string.h>
#include <omnetpp.h>
using namespace omnetpp;
class Node3: public cSimpleModule {
protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};
Define_Module(Node3);
void Node3::initialize() {
    if (strcmp("node1", getName()) == 0) {
        //  The `ev'    object  works   like    `cout'  in  C++.
        EV << "Sending    initial message\n";
        cMessage *msg = new cMessage("tictocMsg");
        send(msg, "out");
    }
}
void Node3::handleMessage(cMessage *msg) {
    //  msg->getName()  is  name    of  the msg object, here    it  will    be  "tictocMsg".
    EV << getName() << " Received    message `" << msg->getName()
              << "', sending it  out again\n";
    send(msg, "out");
}
