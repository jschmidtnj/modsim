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

#include "dest3.h"

Define_Module(Dest3);

void Dest3::initialize()
{
   delayStats.setName("Delay");
   histogram.setRange(0,0.5);
   histogram.setNumCells(25);
}

void Dest3::handleMessage(cMessage *msg)
{
   cPacket* pkt = check_and_cast<cPacket *>(msg);
   if(pkt ->hasBitError()){
       EV<<"Packet received in error\n";
       pkt-> setKind(1);//NACK
   }
   else {
       EV<<"Sending back same message as ACK\n";
       pkt-> setKind(0);//ACK
       simtime_t delay = simTime() -pkt ->getCreationTime();
       EV<<"delay =";
       EV<< delay;
       delayStats.collect(delay);
       histogram.collect(delay);
   }
   send(pkt, "out");
}

void Dest3::finish()
{
    recordScalar("mean delay", delayStats.getMean());
    recordScalar("max delay", delayStats.getMax());
    recordScalar("std deviation", delayStats.getStddev());
    recordScalar("variance", delayStats.getVariance());
    histogram.record();
    EV<<"histogram number of overflows =";
    EV<< histogram.getOverflowCell();
    EV<<"mean delay = \n";
    EV<< delayStats.getMean();
}
