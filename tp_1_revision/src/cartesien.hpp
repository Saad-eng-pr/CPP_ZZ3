#ifndef CARTESIEN_HPP_78576
#define CARTESIEN_HPP_78576

#include <iostream>
#include <cmath>
#include "point.hpp"

using namespace std;

class Cartesien : public Point {
    private : 
        double x;
        double y;

    public: 
        Cartesien();
        Cartesien(double, double);
        Cartesien(const Polaire &);
        double getX() const;
        double getY() const;
        void setX(double);
        void setY(double);
        void afficher(ostream &) const override;
        void convertir(Polaire &) const override;
        void convertir(Cartesien &) const override;          
};


#endif