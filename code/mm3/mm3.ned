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

import org.omnetpp.queueing.PassiveQueue;
import org.omnetpp.queueing.Server;
import org.omnetpp.queueing.Sink;
import org.omnetpp.queueing.Source;


network Mm3
{
    @display("bgb=407,205");
    submodules:
        source: Source {
            @display("p=28,83");
        }
        passiveQueue: PassiveQueue {
            @display("p=147,83");
        }
        server: Server {
            @display("p=253,24");
        }
        server1: Server {
            @display("p=253,93");
        }
        server2: Server {
            @display("p=253,162");
        }
        sink: Sink {
            @display("p=356,84");
        }
    connections:
        source.out --> passiveQueue.in++;
        passiveQueue.out++ --> server.in++;
        passiveQueue.out++ --> server1.in++;
        passiveQueue.out++ --> server2.in++;
        server.out --> sink.in++;
        server2.out --> sink.in++;
        server1.out --> sink.in++;
}
