#include <iostream>
using namespace std;

class TemelIshler {
public:
    void yuxudanDur();
    void paltarGeyin();
    void eluzunuYu();
    void yemekYe();
};

class mashinimVar: TemelIshler {
public:
    void yuxudanDur();
    void paltarGeyin();
    void eluzunuYu();
    void yemekYe();
};

class Muellim: public TemelIshler { // Single
public:
    void avtobusaMin();
    void vaxtindaDerseChat();
    void cedveleBax();
    void dersinOlanSinifeGir();
};

class Polis : public TemelIshler { // Multiply Eyni Zamanda Hierarcal Olur Ustdeki Ile birlikte
public:
    void avtobusaMin();
    void vaxtindaIsheGet();
    void formaniGeyin();
    void telimlereQatil();
};

class Bussinessman : public mashinimVar { // MultiLevel
public:
    void mashinlaIsheGet();
    void birNeceSheyImzala();
};

int main() {
    cout << "Hakuna Matata" << endl;
}
