#ifndef NUAGE_HPP_692736973
#define NUAGE_HPP_692736973

#include <iostream>
#include <vector>
#include "cartesien.hpp"
#include "polaire.hpp"

class Nuage;

Cartesien barycentre(const Nuage & );

class Nuage {
    private:
        std::vector<Point *> points;

    public:
        using const_iterator = std::vector<Point *>::const_iterator;
        using iterator = std::vector<Point *>::iterator;

    public:
        std::size_t size() const { return points.size(); }

        void ajouter(Point & point) { points.push_back(&point); }

        void ajouter(Point * point) { points.push_back(point); }

        const_iterator begin() const { return points.begin(); }

        const_iterator end() const { return points.end(); }

        iterator begin() { return points.begin(); }

        iterator end() { return points.end(); }
};

class BarycentreCartesien {
    public:
        Cartesien operator()(const Nuage & points) { return barycentre(points); }
};

class BarycentrePolaire {
    public: 
        Polaire operator()(const Nuage & points) { return Polaire(barycentre(points)); }
};

#endif