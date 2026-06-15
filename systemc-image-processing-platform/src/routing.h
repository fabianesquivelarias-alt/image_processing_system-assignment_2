#include <systemc.h>
#include <tlm.h>
#include <tlm_utils/simple_target_socket.h>
#include <tlm_utils/simple_initiator_socket.h>
#include "defines.h"

SC_MODULE(routing) {
    //bus targets to receive pkts
    tlm_utils::simple_target_socket<routing> target_cpu;
    tlm_utils::simple_target_socket<routing> target_accelator;
    // bus initiators to send pkts
    tlm_utils::simple_initiator_socket<routing> init_ram_mem;
    tlm_utils::simple_initiator_socket<routing> init_disk_storage;
    tlm_utils::simple_initiator_socket<routing> init_accelator;

    SC_CTOR(routing) : target_cpu("target_cpu"), target_accelator("target_accelator"),
                   init_ram_mem("init_ram_mem"), init_disk_storage("init_disk_storage"), init_accelator("init_accelator") {
        target_cpu.register_b_transport(this, &routing::b_transport_cpu);
        target_accelator.register_b_transport(this, &routing::b_transport_accel);
    }

    void b_transport_cpu(tlm::tlm_generic_payload& trans, sc_time& delay) {
        // handle incoming transactions
    }

    void b_transport_accel(tlm::tlm_generic_payload& trans, sc_time& delay) {
        // handle incoming transactions
    }
};
