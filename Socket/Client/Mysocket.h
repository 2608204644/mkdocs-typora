//
// Created by Cha on 2021/5/28.
//

#ifndef CLIENT_MYSOCKET_H
#define CLIENT_MYSOCKET_H

#include <winsock2.h>
#include <string>


class Mysocket {
public:
    Mysocket() {
#ifdef WIN32
#pragma comment(lib, "WS2_32.lib")
        static bool first = true;
        if (first) {
            WSADATA ws;
            WSAStartup(MAKEWORD(2, 2), &ws);
            first = false;
        }
#endif
        socketC = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        serverAddr.sin_family = AF_INET;
    }

    bool Connection(const char *ipAddress, const int &port);

    int send(const char *message) const;

    int send(const std::string &message) const;

    int receive(char *message);

    int receive(std::string &message);


private:
    SOCKET socketC;
    SOCKADDR_IN serverAddr;
    char news[1024];
    char buffer[1024];
    const static int BUFFERSIZE = 1024;
};


#endif //CLIENT_MYSOCKET_H
