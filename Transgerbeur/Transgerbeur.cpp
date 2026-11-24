#include <iostream>
#include <cstring>
using namespace std;

enum EEtat { vide, palette, rouleau };

struct SPalette {
    int poid;
    char ref[20];
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

    SRouleau ro1 = { 10.5f, 1001 };

    SPalette pa1;
    pa1.poid = 500;
    strcpy_s(pa1.ref, "REF_PAL_01");

    EEtat etatC1 = vide;

    UContenu cont;
    cont.palette = pa1;
    cont.rouleau = ro1;

    SCasier c1;
    c1.cont_casier.palette = pa1;
    c1.etat = palette;
    c1.px = 2;
    c1.py = 3;

    SCasier c2 = { 4, 5, palette, { pa1 } };

    // Si vous voulez un tableau de 2 casiers :
    SCasier tabcasier[2];
    tabcasier[0] = c1;
    tabcasier[1] = c2;


    return 0;
}
