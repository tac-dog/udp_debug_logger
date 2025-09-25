#include "udp_logger.h"
#include <unistd.h>

int main() {
    initUDPSocket("127.0.0.1", 9870);

    double t = 0.01, theta = 1.57, x = 0.21, y = 0.10;
    while (true)
    {
        //send here
        sendJSON(t, { {"theta", theta}, {"x", x}, {"y", y} });

        usleep(10000); // 100Hz
        t += 0.01;
    }

    closeUDPSocket();
}
