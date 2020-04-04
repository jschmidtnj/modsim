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

#include "source3.h"

Define_Module(Source3);

void Source3::initialize()
{
     num_packets = par("num_jobs");
     counter = num_packets;
     EV<< "Sending initial message\n";
     cPacket *pkt = new cPacket("packet");
     pkt -> setBitLength(100);
     send(pkt, "out");
     counter--;
}

void Source3::handleMessage(cMessage *msg)
{
    cPacket* pkt = check_and_cast<cPacket *>(msg);
    int type = pkt -> getKind();
    if (type ==0){
        EV<<"ACK received \n";
        delete pkt;
        //send another packet
        if (counter >=1){
            cPacket *pkt1 = new cPacket ("packet");
            pkt1 -> setBitLength(100);
            send(pkt1, "out");
            counter--;
        }
    }
    else {
        EV<<"NACK received \n";
        pkt ->setBitError(false);
        send(pkt, "out");
    }
}
