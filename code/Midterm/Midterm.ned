import org.omnetpp.queueing.Delay;
import org.omnetpp.queueing.Fork;
import org.omnetpp.queueing.PassiveQueue;
import org.omnetpp.queueing.Queue;
import org.omnetpp.queueing.Router;
import org.omnetpp.queueing.Server;
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
network Midterm
{
    @display("bgb=1489,1000");
    submodules:
        client3: Source {
            @display("p=41,541");
        }
        client_4_sink: Sink {
            @display("p=451,750");
        }
        client4: Source {
            @display("p=41,668");
        }
        api_server_2: Server {
            @display("p=381,598");
        }
        send_to_client_4: PassiveQueue {
            @display("p=141,750");
        }
        client_4_process_updates: Server {
            @display("p=308,750");
        }
        api_server_2_input: PassiveQueue {
            @display("p=227,598");
        }
        client_3_process_updates: Server {
            @display("p=316,477");
        }
        send_to_client_3: PassiveQueue {
            @display("p=141,477");
        }
        client_3_sink: Sink {
            @display("p=472,477");
        }
        local_cache_2_input: PassiveQueue {
            @display("p=588,707");
        }
        local_cache_2: Server {
            @display("p=714,707");
        }
        job_manager_2_input: PassiveQueue {
            @display("p=587,814");
        }
        job_manager_2: Server {
            @display("p=729,814");
        }
        pub_sub_orchestration_input: PassiveQueue {
            @display("p=936,381");
        }
        pub_sub_orchestration: Server {
            @display("p=1142,381");
        }
        central_server_input: PassiveQueue {
            @display("p=920,504");
        }
        central_server: Server {
            @display("p=1073,504");
        }
        database_input: PassiveQueue {
            @display("p=1191,504");
        }
        database: Server {
            @display("p=1299,504");
        }
        database_sink: Sink {
            @display("p=1405,504");
        }
        central_update_delay: Delay {
            @display("p=759,504");
        }
        api_peer_update: Delay {
            @display("p=769,381");
        }
        fork_api_2_jobs: Fork {
            @display("p=511,598");
        }
        cache_2_updated: Sink {
            @display("p=842,707");
        }
        job_manager_2_added: Sink {
            @display("p=881,814");
        }
        send_updates_to_clients: Fork {
            @display("p=1322,381");
        }
        api_server_1: Server {
            @display("p=389,203");
        }
        api_server_1_input: PassiveQueue {
            @display("p=235,203");
        }
        cache_1_updated: Sink {
            @display("p=858,43");
        }
        client1: Source {
            @display("p=49,146");
        }
        client2: Source {
            @display("p=49,273");
        }
        client_1_process_updates: Server {
            @display("p=324,82");
        }
        client_1_sink: Sink {
            @display("p=480,82");
        }
        client_2_process_updates: Server {
            @display("p=316,355");
        }
        client_2_sink: Sink {
            @display("p=459,355");
        }
        fork_api_1_jobs: Fork {
            @display("p=519,203");
        }
        job_manager_1: Server {
            @display("p=823,164");
        }
        job_manager_1_added: Sink {
            @display("p=975,164");
        }
        job_manager_1_input: PassiveQueue {
            @display("p=666,164");
        }
        local_cache_1: Server {
            @display("p=730,43");
        }
        local_cache_1_input: PassiveQueue {
            @display("p=604,43");
        }
        send_to_client_1: PassiveQueue {
            @display("p=149,82");
        }
        send_to_client_2: PassiveQueue {
            @display("p=149,355");
        }
    connections:
        send_to_client_4.out++ --> client_4_process_updates.in++;
        client_4_process_updates.out --> client_4_sink.in++;
        client3.out --> api_server_2_input.in++;
        client4.out --> api_server_2_input.in++;
        api_server_2_input.out++ --> api_server_2.in++;
        send_to_client_3.out++ --> client_3_process_updates.in++;
        client_3_process_updates.out --> client_3_sink.in++;
        local_cache_2_input.out++ --> local_cache_2.in++;
        job_manager_2_input.out++ --> job_manager_2.in++;
        pub_sub_orchestration_input.out++ --> pub_sub_orchestration.in++;
        central_server_input.out++ --> central_server.in++;
        database_input.out++ --> database.in++;
        database.out --> database_sink.in++;
        central_update_delay.out --> central_server_input.in++;
        api_peer_update.out --> pub_sub_orchestration_input.in++;
        fork_api_2_jobs.out++ --> local_cache_2_input.in++;
        fork_api_2_jobs.out++ --> job_manager_2_input.in++;
        fork_api_2_jobs.out++ --> central_update_delay.in++;
        fork_api_2_jobs.out++ --> api_peer_update.in++;
        fork_api_2_jobs.out++ --> send_to_client_4.in++;
        api_server_2.out --> fork_api_2_jobs.in;
        central_server.out --> database_input.in++;
        local_cache_2.out --> cache_2_updated.in++;
        pub_sub_orchestration.out --> send_updates_to_clients.in;
        send_updates_to_clients.out++ --> send_to_client_3.in++;
        job_manager_2.out --> job_manager_2_added.in++;
        send_to_client_1.out++ --> client_1_process_updates.in++;
        client_1_process_updates.out --> client_1_sink.in++;
        client_2_process_updates.out --> client_2_sink.in++;
        job_manager_1_input.out++ --> job_manager_1.in++;
        client1.out --> api_server_1_input.in++;
        local_cache_1_input.out++ --> local_cache_1.in++;
        api_server_1_input.out++ --> api_server_1.in++;
        send_to_client_2.out++ --> client_2_process_updates.in++;
        client2.out --> api_server_1_input.in++;
        api_server_1.out --> fork_api_1_jobs.in;
        local_cache_1.out --> cache_1_updated.in++;
        fork_api_1_jobs.out++ --> local_cache_1_input.in++;
        fork_api_1_jobs.out++ --> job_manager_1_input.in++;
        fork_api_1_jobs.out++ --> send_to_client_2.in++;
        job_manager_1.out --> job_manager_1_added.in++;
        fork_api_1_jobs.out++ --> api_peer_update.in++;
        fork_api_1_jobs.out++ --> central_update_delay.in++;
        send_updates_to_clients.out++ --> send_to_client_1.in++;
}
