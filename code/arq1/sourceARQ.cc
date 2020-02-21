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

#include "sourceARQ.h"

Define_Module(Source);

Source::Source() {
    timeout = 1.0;
}

Source::~Source() {
    cancelAndDelete(timeoutEvent);
}

void Source::initialize() {
    timeoutEvent = new cMessage("timeoutEvent"); // schedule timeout for first packet

    // generate and send message
    EV << "Sending initial message\n";
    cMessage *msg = new cMessage("packet");
    send(msg, "out");
    scheduleAt(simTime() + timeout, timeoutEvent);
}

void Source::handleMessage(cMessage *msg) {
    if (msg == timeoutEvent) {
        // receiving timeout event, no acknowledgement (ACK) was received and timer expired
        // therefore don't resend
        EV << "Timeout expired, resending message and restarting timer\n";
        cMessage *newMsg = new cMessage("packet");
        send(newMsg, "out");
        scheduleAt(simTime() + timeout, timeoutEvent);
    } else {
        EV << "Timeout cancelled.\n";
        cancelEvent(timeoutEvent);
        delete msg;

        // send another message
        cMessage *newMsg = new cMessage("packet");
        send(newMsg, "out");
        scheduleAt(simTime() + timeout, timeoutEvent);
    }
}
