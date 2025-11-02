#ifndef VECTEUR_HPP_8092809
#define VECTEUR_HPP_8092809

#include <iostream>

class Vecteur;

std::ostream& operator<<(std::ostream& , const Vecteur & );
Vecteur operator+(const Vecteur & , const Vecteur & );
int operator*(const Vecteur & , const Vecteur & );

class Iterateur {
    private:
        int * position;

    public:
        Iterateur(int * p) : position(p) {}

        Iterateur & operator++() { ++position; return *this; } 
        Iterateur operator++(int) { 
            Iterateur temp(position);
            ++position;
            return temp;
        }

        int operator*() const { return *position; }

        bool operator==(const Iterateur & i) { return position == i.position; }
        bool operator!=(const Iterateur & i) { return position != i.position; }
};

class Vecteur {
    private: 
        int * elements;
        unsigned taille;
        unsigned capacite;

    public:
        Iterateur begin() const { return Iterateur(elements); }
        Iterateur end() const { return Iterateur(elements + taille); }
        
        explicit Vecteur(unsigned c = 100) : elements(new int[c]), taille(0), capacite(c) {}
        Vecteur(const Vecteur & v) : elements(nullptr), taille(0), capacite(0) { copier(v); }
        
        unsigned getTaille() const { return taille; }
        unsigned getCapacite() const { return capacite; }

        void ajouter(int);
        void retirer();

        int operator[](unsigned i) const { return elements[i]; } //pour un vecteur constant, on a donc que acces lecture
        int & operator[](unsigned i) { return elements[i]; } //pour un vecteur non constant, on donc acces a la lecture et ecriture
        
        Vecteur & operator=(const Vecteur & v) {
            if (this != &v) {
                copier(v);
            } 
            return *this;
        }
        
        ~Vecteur() { delete[] elements; }

    private:
        void copier(const Vecteur & v);
};

#endif