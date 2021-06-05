#include <iostream>
#include <string>
#include <fstream>

#include "mySocketServer.cpp"
#include "DH_encryption.cpp"
#include "Rsa.cpp"

using namespace std;

int send(mySocketServer &client, const string &message, Rsa &r);    //向指定客户端发送，RSA算法加密后的message

int receive(mySocketServer &client, string &message, Rsa &r);       //使用RSA算法解密，获得相应客户端的message

int keyExchange(mySocketServer &client, Rsa &r, Rsa &o);            //密钥交换

int fileReceive(mySocketServer &client, Rsa &r, Rsa &o);            //文件接收

int main() {
    Rsa myRSA, clientRSA;   //定义RSA加密算法实例
    string message;         //消息交换
    mySocketServer server;  //服务端实例

    server.Listening();     //绑定，并监听
    keyExchange(server, myRSA, clientRSA); //密钥交换

    fileReceive(server,myRSA,clientRSA);    //文件传输

    return 0;
}

int send(mySocketServer &client, const string &message, Rsa &r) {
    r.setPlaintext(message);
    client.send(r.Encryption());
    return 0;
}

int receive(mySocketServer &client, string &message, Rsa &r) {
    client.receive(message);
    r.setCiphertext(message);
    message = r.Decryption();
    return 0;
}


int keyExchange(mySocketServer &client, Rsa &myRsa, Rsa &other) {
    DH_encryption DH;

    unsigned int g, p, x, y;
    int pub, mode;
    string message;
    string news;

    client.receive(message);
    if (message != "hello")exit(404);
    client.send("ok");


    client.receive(message);
    g = std::stoi(message);
    client.receive(message);
    p = std::stoi(message);
    client.receive(message);
    y = std::stoi(message);
    DH.setPublic(g, p);
    DH.setOtherPublic(y);
    DH.getPubKey(x);
    message = to_string(x);
    client.send(message);

    client.receive(message);
    DH.setCiphertext(message);
    pub = std::stoi(DH.Decryption());
    client.receive(message);
    DH.setCiphertext(message);
    mode = std::stoi(DH.Decryption());
    other.setPublicKey(mode, pub);

    myRsa.getPublicKey(mode, pub);
    DH.setPlaintext(to_string(pub));
    client.send(DH.Encryption());
    DH.setPlaintext(to_string(mode));
    client.send(DH.Encryption());

    return 0;
}

int fileReceive(mySocketServer &client, Rsa &r, Rsa &o) {
    string message;
    ofstream outfile;

    outfile.open("file.txt", ios::out | ios::trunc|ios::binary );
    receive(client,message,r);
    while (message!="FILEEND") {
        outfile<<message;
        if(message.size()!=1024)outfile<<std::endl;
        receive(client,message,r);
    }
    outfile.close();
    cout << "已接收";
    return 0;
}