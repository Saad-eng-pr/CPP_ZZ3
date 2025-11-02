#ifndef POINT_HPP_8627
#define POINT_HPP_8627

#include <iostream>

using namespace std;

class Point;
class Cartesien;
class Polaire;

ostream& operator<<(ostream &, const Point & );

class Point {

    public:
        virtual void afficher(ostream & ) const = 0;
        virtual void convertir(Polaire &) const = 0;
        virtual void convertir(Cartesien &) const = 0;
};


#endif