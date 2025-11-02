#include "cartesien.hpp"
#include "polaire.hpp"

Cartesien::Cartesien() : x(0), y(0) {}

Cartesien::Cartesien(double inX, double inY) : x(inX), y(inY) {}

Cartesien::Cartesien(const Polaire & polaire) {
    polaire.convertir(*this);
}

double Cartesien::getX() const {
    return x;
}

double Cartesien::getY() const {
    return y;
}

void Cartesien::setX(double inX) {
    x = inX;
}

void Cartesien::setY(double inY) {
    y = inY;
}

void Cartesien::afficher(ostream & out) const {
    out << "(x=" << getX() << ";y=" << getY() << ")" ;
}

void Cartesien::convertir(Polaire & polaire) const {
    polaire.setAngle(std::atan2(y, x) * 180 / M_PI);
    polaire.setDistance(std::hypot(x, y));
}

void Cartesien::convertir(Cartesien & cartesien) const {
    cartesien.setX(x);
    cartesien.setY(y);
}