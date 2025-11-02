#ifndef NUAGE_HPP_780720829
#define NUAGE_HPP_780720829

#include <iostream>
#include <vector>

#include "cartesien.hpp"
#include "polaire.hpp"
#include "point.hpp"

template <typename T>
class Nuage;

template <typename T>
T barycentre_v1(const Nuage<T> & nuage);

template <typename T>
class Nuage {
    private:
        std::vector<T> points;

    public:
        Nuage() = default;

        using iterator = typename std::vector<T>::iterator;
        using const_iterator = typename std::vector<T>::const_iterator;

        const_iterator begin() const;
        const_iterator end() const;

        iterator begin();
        iterator end();  

        size_t size() const;
        
        void ajouter(const T & t); 
};


template <typename T>
T barycentre_v1(const Nuage<T> & nuage) {
    Cartesien c;
    double xR = 0.0;
    double yR = 0.0;
    int n = 0;

    for (const T & t : nuage) {
        c = Cartesien(t);
        xR += c.getX();
        yR += c.getY();
        ++n;
    }

    return ( n == 0 ? T() : T(Cartesien(xR/n, yR/n)));
}

template <>
Polaire barycentre_v1<Polaire>(const Nuage<Polaire> & nuage) {
    double angleR = 0.0;
    double distanceR = 0.0;
    int n = 0;

    for (const Polaire & t : nuage) {
        angleR += t.getAngle();
        distanceR += t.getDistance();
        ++n;
    }

    return ( n == 0 ? Polaire() : Polaire(angleR/n, distanceR/n));
}

// template <typename T>
// Nuage<T>::Nuage() {}  //on la remplacer par Nuage() = default;

template <typename T>
typename Nuage<T>::const_iterator Nuage<T>::begin() const {
    return points.begin();
}

template <typename T>
typename Nuage<T>::const_iterator Nuage<T>::end() const {
    return points.end();
}

template <typename T>
typename Nuage<T>::iterator Nuage<T>::begin() {
    return points.begin();
}

template <typename T>
typename Nuage<T>::iterator Nuage<T>::end() {
    return points.end();
}

template <typename T>
size_t Nuage<T>::size() const {
    return points.size();
}

template <typename T>
void Nuage<T>::ajouter(const T & t) {
    points.push_back(t);
}



#endif