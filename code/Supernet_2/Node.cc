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

void Node::initialize() {
    if (strcmp("node[0]", getFullName()) == 0) {
        cMessage *msg = new cMessage("msg");
        send(msg, "out", 1);
        EV << "Starting with the first message\n";
    }
}

void Node::handleMessage(cMessage *msg) {
    int count = getAncestorPar("count");
    counter++;
    int outgateindex = intuniform(0, count - 2);
    send(msg, "out", outgateindex);
    EV << "Received message " << count << ": " << msg->getName()
              << ". Randomly sending to " << outgateindex << ".\n";
}
