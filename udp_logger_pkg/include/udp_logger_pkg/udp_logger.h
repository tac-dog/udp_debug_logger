#pragma once
#include <string>
#include <initializer_list>
#include <sys/socket.h>
#include <netinet/in.h>

void initUDPSocket(const std::string& ip, int port);
void closeUDPSocket();

void sendJSON(double timestamp,
              std::initializer_list<std::pair<std::string, double>> values);