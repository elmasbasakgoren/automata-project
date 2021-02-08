//
// Created by Mücahit Cücen on 23.05.2020.
//

#include "Point.h"
#include <cmath>

using namespace std;

Point::Point() {

}

double Point::distanceTo(Point *to) {
    return sqrt(pow(this->x - to->x, 2) + pow(this->y - to->y, 2));
}
