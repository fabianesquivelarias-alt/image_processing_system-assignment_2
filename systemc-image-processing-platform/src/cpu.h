#include <systemc.h>
#include <tlm.h>
#include <tlm_utils/simple_initiator_socket.h>

SC_MODULE(cpu) {
    tlm_utils::simple_initiator_socket<cpu> socket;

    SC_CTOR(cpu) : socket("socket") {
        SC_THREAD(run);
    }

    void run() {
    }
};
