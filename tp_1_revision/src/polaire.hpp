#ifndef POLAIRE_HPP_78576
#define POLAIRE_HPP_78576

#include <iostream>
#include <cmath>
#include "point.hpp"


using namespace std;

class Polaire : public Point {
    private : 
        double a;
        double d;

    public: 
        Polaire();
        Polaire(double, double);
        Polaire(const Cartesien &);
        double getAngle() const;
        double getDistance() const;
        void setAngle(double);
        void setDistance(double);
        void afficher(ostream &) const override;
        void convertir(Cartesien &) const override;  
        void convertir(Polaire &) const override;  
};


#endif