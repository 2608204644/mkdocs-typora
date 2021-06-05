//
// Created by Cha on 2021/5/21.
//

#include "DH_encryption.h"
#include <iostream>
#include <cstring>
#include <sstream>

void DH_encryption::getPrime()//线性筛选素数
{
    int NUM = 7919;
    bool f[50000];
    memset(f, 0, sizeof(f));
    for (int i = 2; i < NUM; ++i) {
        if (!f[i]) {
            f[i] = 1;
            _prime[_pNum++] = i;
        }
        for (int j = 0; j < _pNum && i * _prime[j] < NUM; ++j) {
            f[i * _prime[j]] = 1;
            if (i % _prime[j] == 0) {
                break;
            }
        }
    }
}

int DH_encryption::ModularExponention(long long a, long long b, long long n) {
    long long y = 1;
    while (b != 0) {
        if (b & 1)
            y = (y * a) % n;
        a = (a * a) % n;
        b = b >> 1;
    }
    return (int) y;
}

size_t DH_encryption::generator(size_t p) {
    size_t x, t;
    bool flag = true;
    bool xx[10000];
    for (x = 0; x < p; x++) {
        flag = true;
        memset(xx, 0, p);
        for (size_t i = 1; i <= p; i++) {
            t = ModularExponention(x, i, p);
            if (xx[t] == 1) {
                flag = false;
                break;
            }
            xx[t] = 1;
        }
        if (flag == true)break;
    }
    if (flag == true)return x;
}


void DH_encryption::KeyGeneration() {
    size_t p, g, x;
    getPrime();
    std::default_random_engine e;
    std::uniform_int_distribution<unsigned> u(100, 1000);
    p = _prime[u(e)];
    g = generator(p);
    x = e() % p;

    _P = p;
    _G = g;
    _X = x;
}

size_t DH_encryption::keygen() {
    if (_X == 0 || _Y == 0)return 0;
    else return (size_t) pow(_X, _Y);
}


std::string DH_encryption::Encryption() {
    int cipher;
    std::string cipherText;
    for (int i = 0; i < Plaintext.length(); i++) {
        cipher = toascii(Plaintext[i]) ^ _Key;
        cipherText += std::to_string(cipher);
        cipherText += " ";
    }
    return cipherText;
}

std::string DH_encryption::Decryption() {
    int decipher, count = 0, pos;
    std::string decry;
    std::istringstream iss(Ciphertext);
    while (iss >> decipher) {
        decipher = decipher ^ _Key;
        decry += (char) decipher;
    }

    return decry;
}

