#include <omnetpp.h>
#include <string.h>

using namespace omnetpp;

const int maxNode2Receive = 10;

class Node : public cSimpleModule {
 protected:
  virtual void initialize() override;
  virtual void handleMessage(cMessage *msg) override;

 private:
  unsigned int messageReceiveCount = 0;
};
Define_Module(Node);
void Node::initialize() {
  if (strcmp("node1", getName()) == 0) {
    EV << "Sending initial message" << endl;
    cMessage *msg = new cMessage("tictocMsg");
    send(msg, "out");
  }
}
void Node::handleMessage(cMessage *msg) {
  EV << getName() << " received message " << msg->getName() << endl;
  messageReceiveCount++;
  bool sendMessage = true;
  if (strcmp("node2", getName()) == 0) {
    EV << "node 2 receive message #" << messageReceiveCount << endl;
    sendMessage = messageReceiveCount != maxNode2Receive;
  }
  if (sendMessage) {
    EV << "sending it out again" << endl;
    send(msg, "out");
  }
}