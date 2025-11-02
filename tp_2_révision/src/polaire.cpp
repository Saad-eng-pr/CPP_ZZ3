#include "polaire.hpp"
#include "cartesien.hpp"

Polaire::Polaire() : a(0), d(0) {}

Polaire::Polaire(double inA, double inD) : a(inA), d(inD) {}

Polaire::Polaire(const Cartesien & cartesien) {
    cartesien.convertir(*this);
}

double Polaire::getAngle() const {
    return a;
}

double Polaire::getDistance() const {
    return d;
}

void Polaire::setAngle(double inA) {
    a = inA;
}

void Polaire::setDistance(double inD) {
    d = inD;
}

void Polaire::afficher(ostream & out) const {
    out << "(a=" << getAngle() << ";d=" << getDistance() << ")" ;
}

void Polaire::convertir(Cartesien & cartesien) const {
    cartesien.setX(d * std::cos(a * M_PI / 180));
    cartesien.setY(d * std::sin(a * M_PI / 180));
}

void Polaire::convertir(Polaire & polaire) const  {
    polaire.setAngle(a);
    polaire.setDistance(d);
}