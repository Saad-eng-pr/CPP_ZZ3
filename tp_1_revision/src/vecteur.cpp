#include "vecteur.hpp"

using namespace std;

void Vecteur::ajouter(int x) {
    if (capacite == taille) {
        int * tab = new int[capacite * 2];
        for (unsigned i = 0; i<taille; i++) {
            tab[i] = elements[i];
        }
        if (elements) {
            delete[] elements;
        }

        elements = tab;
        capacite *= 2;
    }

    elements[taille++] = x;
}

void Vecteur::retirer() {
    if(taille > 0) {
        --taille;
    }
}

void Vecteur::copier(const Vecteur & v) {
    if (capacite < v.getTaille()) {
        if (elements) delete[] elements;
        capacite = v.getTaille();
        elements = new int[capacite];
    }

    taille = v.getTaille();
    for (unsigned i = 0; i < taille; i++) {
        elements[i] = v.elements[i];
    }
}

ostream& operator<<(ostream& out, const Vecteur & v) {
    for (int x : v) out << x << " ";

    return out;
}

Vecteur operator+(const Vecteur & v1, const Vecteur & v2) {
    Vecteur v(v1.getTaille() + v2.getTaille());

    v = v1; //Operateur de copie qu'on a deja cree

    for(unsigned i = 0; i < v2.getTaille(); i++)  v.ajouter(v2[i]);

    return v;
}

int operator*(const Vecteur & v1, const Vecteur & v2) {
    if( v1.getTaille() != v2.getTaille() ) throw string("Erreur produit scalaire");

    int result = 0;

    for(unsigned i=0; i < v1.getTaille(); i++) result += v1[i]*v2[i];

    return result;
}