//
// Created by Cha on 2021/5/21.
//

#ifndef UNTITLED4_DH_ENCRYPTION_H
#define UNTITLED4_DH_ENCRYPTION_H

#include <string>
#include <cstdio>
#include <ctime>
#include <random>

//DH
/*
 *  unsigned int g,p,X,Y;
    DH_encryption dh1,dh2;
    dh1.KeyGeneration();
    dh1.getPublic(g,p);
    dh2.setPublic(g,p);
    dh1.getPubKey(X);
    dh2.setOtherPublic(X);
    dh2.getPubKey(Y);
    dh1.setOtherPublic(Y);

    string Plaintext("RSA");
    string Ciphertext,decode;
    dh1.setPlaintext(Plaintext);
    Ciphertext=dh1.Encryption();
    dh2.setCiphertext(Ciphertext);
    decode=dh2.Decryption();

    cout<<decode;
*/

class DH_encryption {

public:
    void KeyGeneration();

    void setPublic(size_t &aG, size_t &aP) {    //设置质数P及其原根G
        _G = aG;
        _P = aP;
        std::default_random_engine e;
        _X = e() % _P;
    }

    void getPublic(size_t &aG, size_t &aP) {    //获取质数P及其原根G
        aG = _G;
        aP = _P;
    }

    void getPubKey(size_t &aX) { aX = _X; }     //获取公钥X

    void setOtherPublic(size_t &aY) {           //设置对方公钥
        _Y = aY;
        _Key = keygen();
    }

    void getKey(size_t &akey) { akey = _Key; }  //获取G^XY mode P ,得到的对等密钥

    void setPlaintext(std::string p) { Plaintext = p; }     //设置明文

    std::string Encryption();   //加密明文，返还密文

    void setCiphertext(std::string c) { Ciphertext = c; }   //设置密文

    std::string Decryption();   //设置密文，返还明文

private:
    size_t _G;
    size_t _P;
    size_t _Y;
    size_t _X;
    size_t _Key{};
    size_t _prime[1000]{};
    int _pNum = 0;
    std::string Plaintext, Ciphertext;

    void DH_encryption::getPrime();

    size_t generator(size_t p);

    size_t keygen();

    int ModularExponention(long long a, long long b, long long n);

};


#endif //UNTITLED4_DH_ENCRYPTION_H
