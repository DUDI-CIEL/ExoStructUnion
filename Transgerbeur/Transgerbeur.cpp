#include <iostream>
#include <cstring>
using namespace std;

enum EEtat { vide, palette, rouleau };

struct SPalette {
    int poid;
    char ref;
};

struct SRouleau {
    float longueur;
    int num;
};

union UContenu {
    SPalette palette;
    SRouleau rouleau;
};

struct SCasier {
    int px;
    int py;
    EEtat etat;
    UContenu cont_casier;
};

int main() {
    cout << "Programme Transgerbeur" << endl;
    return 0;
}
