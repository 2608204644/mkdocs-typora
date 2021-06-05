//
// Created by Cha on 2021/5/28.
//

#include "Mysocket.h"

bool Mysocket::Connection(const char *ipAddress, const int &port) {
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(ipAddress);
    connect(socketC, (SOCKADDR *) &serverAddr, sizeof(serverAddr));
    return true;
}

int Mysocket::send(const char *message) const {
    return ::send(socketC, message, BUFFERSIZE, 0);
}


int Mysocket::send(const std::string &message) const {
    return send(message.c_str());
}

int Mysocket::receive(char *message) {
    int t;
    memset(buffer, 0, BUFFERSIZE);
    t = recv(socketC, buffer, BUFFERSIZE, 0);
    strcpy_s(message, BUFFERSIZE, buffer);
    return t;
}

int Mysocket::receive(std::string &message) {
    int t = receive(news);
    std::string ms{news};
    message = ms;
    return t;
}
