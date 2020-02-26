//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "Node.h"

Define_Module(Node);

void Node::sendMessage(cMessage *msg) {
    int outindex;
    double prob = uniform(0, 1);
    if (strcmp("node[0]", getFullName()) == 0) {
        if (prob < 0.1) {
            // to node 2
            outindex = 0;
        } else {
            // to node 3
            outindex = 1;
        }
    } else if (strcmp("node[1]", getFullName()) == 0) {
        if (prob < 0.9) {
            // to node 1
            outindex = 0;
        } else {
            // to node 3
            outindex = 1;
        }
    } else if (strcmp("node[2]", getFullName()) == 0) {
        EV << "Game over.\n";
        return;
    } else {
        EV << "Invalid node index.\n";
        return;
    }
    EV << "Randomly sending to " << outindex << ".\n";
    send(msg, "out", outindex);
}

void Node::initialize() {
    if (strcmp("node[0]", getFullName()) == 0) {
        EV << "Starting by sending first message from node 1\n";
        cMessage *msg = new cMessage("msg");
        sendMessage(msg);
    }
}

void Node::handleMessage(cMessage *msg) {
    int count = getAncestorPar("count");
    counter++;
    EV << "Received message " << count << ": " << msg->getName() << ".\n";
    sendMessage(msg);
}
