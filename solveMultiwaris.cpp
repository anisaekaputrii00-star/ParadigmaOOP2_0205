#include <iostream>
using namespace std;

class orang {
public:
    orang(int pUmur)
    {
        cout << "Orang dibuat\n" << endl;
    }
};

class pekerja : public orang {
public:
    pekerja(int pUmur) :
        orang(pUmur)
    {
        cout << "Pekerja dibuat\n" << endl;
    }
};

