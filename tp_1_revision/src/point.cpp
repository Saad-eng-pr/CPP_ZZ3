#include "point.hpp"

using namespace std;

ostream& operator<<(ostream & out, const Point & point) {
    point.afficher(out);
    return out;
}
