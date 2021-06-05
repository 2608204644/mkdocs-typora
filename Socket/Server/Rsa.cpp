#include <algorithm>
#include <ctime>
#include <math.h>
#include <string>
#include <sstream>
#include <ctype.h>

#include"Rsa.h"

//求最大公约数
int Rsa::gcd(int a, int b) {
    int c = 0;
    if (a < b) std::swap(a, b);
    c = b;
    do {
        b = c;
        c = a % b;
        a = b;
    } while (c != 0);
    return b;
}

//质数判断
bool Rsa::isPrimarity(int number) {
    int flag = 0;
    int a;
    for (a = 2; a < sqrt(number) + 1; a++) {
        if (number % a == 0) {
            flag = 1;
            break;
        }
    }
    if (flag) return false;
    return true;
}

//求a^bmodn
int Rsa::ModularExponention(long long a, long long b, long long n) {
    long long y = 1;
    while (b != 0) {
        if (b & 1)
            y = (y * a) % n;
        a = (a * a) % n;
        b = b >> 1;
    }
    return (int) y;
}

//拓展欧几里得
void Rsa::extgcd(long long a, long long b, long long &d, long long &x, long long &y) {
    if (!b) {
        d = a;
        x = 1;
        y = 0;
    } else {
        extgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}

//获取(1/a)modb的结果
int Rsa::ModularInverse(int a, int b) {
    long long d, x, y;
    extgcd(a, b, d, x, y);
    return d == 1 ? (x + b) % b : -1;
}

void Rsa::KeyGeneration() {
    int p, q;
    int phi_n;
    srand(time(0));
    do {
        do
            p = rand();
        while (p % 2 == 0);

    } while (!isPrimarity(p));

    do {
        do
            q = rand();
        while (q % 2 == 0);
    } while (!isPrimarity(q));

    n = p * q;
    phi_n = (p - 1) * (q - 1);

    do
        e = rand() % (phi_n - 2) + 2; // 1 < e < phi_n
    while (gcd(e, phi_n) != 1);

    d = ModularInverse(e, phi_n);
}

std::string Rsa::Encryption() {
    int cipher;
    std::string cipherText;
    for (int i = 0; i < Plaintext.length(); i++) {
        cipher = ModularExponention(toascii(Plaintext[i]), oe, on);
        cipherText += std::to_string(cipher);
        cipherText += " ";
    }
    return cipherText;
}

std::string Rsa::Decryption() {
    int decipher, count = 0, pos;
    std::string decry;
    std::istringstream iss(Ciphertext);
    while (iss >> decipher) {
        decipher = ModularExponention(decipher, d, n);
        decry += (char) decipher;
    }

    return decry;
}

void Rsa::getPublicKey(int &an, int &ae) {
    an = n;
    ae = e;
}

void Rsa::setPublicKey(int &aon, int &aoe) {
    on = aon;
    oe = aoe;
}