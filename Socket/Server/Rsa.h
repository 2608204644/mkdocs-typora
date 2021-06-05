#ifndef RSA_H
#define RSA_H

#include<string>

//RSA
/*
 * int apub,amode;
 * int bpub,bmode;
 * Rsa usera,userb;
 * caesarCipher caesar;
 * string Plaintext("3");
 * string Ciphertext,decode,temp;

----------RSA加密解密过程-------------

    usera.setPlaintext(Plaintext);          //设置明文
    userb.getPublicKey(bpub,bmode);         //获取userb的公钥
    usera.setPublicKey(bpub,bmode);         //设置公钥
    Ciphertext = usera.Encryption();        //加密

    cout<<"加密密钥:"<<Ciphertext<<" "<<endl; //输出

    userb.setCiphertext(Ciphertext);         //userb设置密文
    decode=userb.Decryption();               //用私钥解密

    cout<<"解密密钥:"<<decode<<endl;           //输出

*/

class Rsa {
private:

    int e, d, n, p;
    int on, oe;
    std::string Plaintext, Ciphertext;

    int gcd(int a, int b);//求最大公约数
    bool isPrimarity(int number);//质数判断
    int ModularExponention(long long a, long long b, long long n);//求a^bmodn
    int ModularInverse(int a, int b);

    void extgcd(long long a, long long b, long long &d, long long &x, long long &y);//拓展欧几里得
    void KeyGeneration();

public:

    Rsa();

    ~Rsa();

    void getPublicKey(int &n, int &e);      //获取己方计算的公钥

    void setPublicKey(int &aon, int &aoe);  //设置对方的公钥

    void setPlaintext(std::string p) { Plaintext = p; }     //设置明文

    std::string Encryption();   //实现加密,返回对应密文

    void setCiphertext(std::string c) { Ciphertext = c; }   //设置密文

    std::string Decryption();   //实现解密，返回对应明文
};


Rsa::Rsa() {
    KeyGeneration();
}

Rsa::~Rsa() {
}


#endif