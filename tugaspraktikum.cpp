#include <iostream>
using namespace std;

// Abstract Base Class
class RekeningBank {
protected:
    double saldo;

public:
    RekeningBank(double saldo) {
        this->saldo = saldo;
    }

    virtual void potongAdmin() = 0;

    void tampilSaldo() {
        cout << "Saldo akhir: Rp " << saldo << endl;
    }
};

// Rekening Syariah
class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(double saldo) : RekeningBank(saldo) {}

    void potongAdmin() override {
        cout << "Rekening Syariah: Bebas biaya admin." << endl;
    }
};

// Rekening Konvensional
class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(double saldo) : RekeningBank(saldo) {}

    void potongAdmin() override {
        saldo -= 15000;
        cout << "Rekening Konvensional: Potongan admin Rp 15.000" << endl;
    }
};

// Rekening Premium
class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(double saldo) : RekeningBank(saldo) {}

    void potongAdmin() override {
        if (saldo > 10000000) {
            cout << "Rekening Premium: Bebas biaya admin." << endl;
        } else {
            saldo -= 50000;
            cout << "Rekening Premium: Potongan admin Rp 50.000" << endl;
        }
    }
};

int main() {

    RekeningBank* rekening1 = new RekeningSyariah(5000000);
    RekeningBank* rekening2 = new RekeningKonvensional(5000000);
    RekeningBank* rekening3 = new RekeningPremium(12000000);
    RekeningBank* rekening4 = new RekeningPremium(8000000);

    rekening1->potongAdmin();
    rekening1->tampilSaldo();

    cout << endl;

    rekening2->potongAdmin();
    rekening2->tampilSaldo();

    cout << endl;

    rekening3->potongAdmin();
    rekening3->tampilSaldo();

    cout << endl;

    rekening4->potongAdmin();
    rekening4->tampilSaldo();

    delete rekening1;
    delete rekening2;
    delete rekening3;
    delete rekening4;

    return 0;
}