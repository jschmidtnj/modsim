import org.omnetpp.queueing.PassiveQueue;
import org.omnetpp.queueing.Queue;
import org.omnetpp.queueing.Router;
import org.omnetpp.queueing.Sink;
import org.omnetpp.queueing.Source;


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
network networkqueue
{
    @display("bgb=454,341");
    submodules:
        source: Source {
            @display("p=64,49");
        }
        source1: Source {
            @display("p=47,136");
        }
        source2: Source {
            @display("p=56,219");
        }
        queue: Queue {
            @display("p=152,122");
        }
        router: Router {
            @display("p=226,115");
        }
        queue1: Queue {
            @display("p=296,39");
        }
        queue2: Queue {
            @display("p=305,123");
        }
        sink: Sink {
            @display("p=389,115");
        }
        source3: Source {
            @display("p=226,235");
        }
    connections:
        source.out --> queue.in++;
        source1.out --> queue.in++;
        source2.out --> queue.in++;
        queue.out --> router.in++;
        router.out++ --> queue1.in++;
        router.out++ --> queue2.in++;
        source3.out --> queue2.in++;
        queue2.out --> sink.in++;
        queue1.out --> sink.in++;
}
