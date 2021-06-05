//
// Created by Cha on 2021/5/28.
//

#include "mySocketServer.h"

bool mySocketServer::Listening(const std::string & ipadd,int port) {
    ListenAddr.sin_addr.S_un.S_addr = inet_addr(ipadd.c_str());
    ListenAddr.sin_port=htons(port);
    if (bind(ListenSocket, (LPSOCKADDR) &ListenAddr, sizeof(ListenAddr)) == SOCKET_ERROR)return false;
    listen(ListenSocket, 5);
    Client = accept(ListenSocket, 0, 0);
}

int mySocketServer::send(const char *message) const {
    return ::send(Client, message, BUFFERSIZE, 0);
}


int mySocketServer::send(const std::string &message) const {
    return send(message.c_str());
}

int mySocketServer::receive(char *message) {
    int t;
    memset(buffer, 0, BUFFERSIZE);
    t = recv(Client, buffer, BUFFERSIZE, 0);
    strcpy_s(message, BUFFERSIZE, buffer);
    return t;
}

int mySocketServer::receive(std::string &message) {
    int t = receive(news);
    std::string ms{news};
    message = ms;
    return t;
}