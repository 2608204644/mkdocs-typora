#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <winsock2.h>

#include "Mysocket.h"
#include "DH_encryption.cpp"
#include "Rsa.cpp"

using namespace std;

#define BUF_SIZE 1024


int send(Mysocket &client, const string &message, Rsa &r);

int receive(Mysocket &client, string &message, Rsa &r);

int keyExchange(Mysocket &client, Rsa &r, Rsa &o);

int fileSend(Mysocket &client, Rsa &r, Rsa &o, string path);

int main() {
    Rsa myRSA, serverRSA;
    Mysocket client;
    string messages, news;
    int i, j;
    client.Connection("127.0.0.1", 8000);
    keyExchange(client, myRSA, serverRSA);

    cout<<"请输入要发送的文件的路径"<<endl;
    cin>>news;
    fileSend(client,myRSA,serverRSA,news);


    return 0;
}


int send(Mysocket &client, const string &message, Rsa &r) {
    r.setPlaintext(message);
    client.send(r.Encryption());
    return 0;
}

int receive(Mysocket &client, string &message, Rsa &r) {
    client.receive(message);
    r.setCiphertext(message);
    message = r.Decryption();
    return 0;
}


int keyExchange(Mysocket &client, Rsa &r, Rsa &o) {
    DH_encryption DH;

    unsigned int g, p, x, y;
    int pub, mode;
    string message;
    string news;

    client.send("hello");
    client.receive(message);

    DH.KeyGeneration();
    DH.getPublic(g, p);
    message = to_string(g);
    client.send(message);
    message = to_string(p);
    client.send(message);
    DH.getPubKey(x);
    message = to_string(x);
    client.send(message);
    client.receive(message);
    y = std::stoi(message);
    DH.setOtherPublic(y);
    r.getPublicKey(mode, pub);
    DH.setPlaintext(to_string(pub));
    client.send(DH.Encryption());
    DH.setPlaintext(to_string(mode));
    client.send(DH.Encryption());

    client.receive(message);
    DH.setCiphertext(message);
    message = DH.Decryption();
    pub = std::stoi(message);
    client.receive(message);
    DH.setCiphertext(message);
    message = DH.Decryption();
    mode = std::stoi(message);
    o.setPublicKey(mode, pub);

    return 0;
}

int fileSend(Mysocket &client, Rsa &r, Rsa &o, string path) {
    char message[1024];
    ifstream infile(path,ios::in|ios::binary);

    while (!infile.eof()) {
        infile.getline(message,1024);
        send(client, message, o);
    }
    infile.close();
    cout << "发送完成";
    send(client, "FILEEND", o);
    return 0;
}
