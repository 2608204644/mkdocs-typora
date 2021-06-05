//
// Created by Cha on 2021/5/28.
//

#ifndef TESTSERVER_MYSOCKETSERVER_H
#define TESTSERVER_MYSOCKETSERVER_H


#include <WinSock2.h>
#include <string>
#include <vector>
#include <iostream>

class mySocketServer {
public:

    mySocketServer(){       //构造函数，设置socket相关参数

#ifdef WIN32
#pragma comment(lib, "WS2_32.lib")
        static bool first = true;
        if (first) {
            WSADATA wsd;
            WSAStartup(MAKEWORD(2, 2), &wsd);
            first = false;
        }
#endif
        WSAData wsd;
        WSAStartup(MAKEWORD(2,2),&wsd);
        ListenSocket = socket(AF_INET,SOCK_STREAM,0);
        ListenAddr.sin_family=AF_INET;
    }
    bool Listening(const std::string & ipadd = "127.0.0.1",int port = 8000);    //设置ip，端口

    int send(const char *message) const;    //发送内容

    int send(const std::string & message) const;    //重载

    int receive(char *message);     //接受内容

    int receive(std::string & message); //重载


private:
    SOCKET Client;
    SOCKET ListenSocket;
    SOCKADDR_IN ListenAddr;
    char news[1024];
    char buffer[1024];
    const static int BUFFERSIZE = 1024;
    const static int PORT=8000;

};


#endif //TESTSERVER_MYSOCKETSERVER_H
