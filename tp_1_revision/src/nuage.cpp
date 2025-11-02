#include "nuage.hpp"

Cartesien barycentre(const Nuage & points) {
    Cartesien c;
    double xRslt = 0.0;
    double yRslt = 0.0;
    int i = 0;
    

    for( Point * p : points ) {
        p->convertir(c);
        xRslt += c.getX();
        yRslt += c.getY();
        ++i;
    }

    return (i == 0 ? Cartesien() : Cartesien(xRslt / i, yRslt / i));
};