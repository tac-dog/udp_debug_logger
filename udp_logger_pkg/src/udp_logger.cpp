#include "udp_logger.h"
#include <sstream>
#include <unistd.h>
#include <arpa/inet.h>

static int g_sock = -1;
static sockaddr_in g_addr;

void initUDPSocket(const std::string& ip, int port) {
    g_sock = socket(AF_INET, SOCK_DGRAM, 0);
    g_addr.sin_family = AF_INET;
    g_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &g_addr.sin_addr);
}

void closeUDPSocket() {
    if (g_sock >= 0) close(g_sock);
    g_sock = -1;
}

void sendJSON(double timestamp,
              std::initializer_list<std::pair<std::string, double>> values) {
    if (g_sock < 0) return;

    std::ostringstream ss;
    ss << "{ \"time\": " << timestamp;
    for (auto& kv : values) {
        ss << ", \"" << kv.first << "\": " << kv.second;
    }
    ss << " }\n";

    std::string msg = ss.str();
    sendto(g_sock, msg.c_str(), msg.size(), 0,
           (sockaddr*)&g_addr, sizeof(g_addr));
}