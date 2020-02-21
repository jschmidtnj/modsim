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

#include "destARQ.h"
#include <omnetpp.h>

Define_Module(Destination);

void Destination::initialize() {
    loseProb = par("loseProb").doubleValue();
}

void Destination::handleMessage(cMessage *msg) {
    // lose message with probability of 0.1
    if (uniform(0, 1) < loseProb) {
        EV << "message lost\n";
        bubble("message lost"); // animate
        delete msg;
    } else {
        EV << "Sending back same message as ACK.\n";
        send(msg, "out");
    }
}
