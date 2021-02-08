
#ifndef AUTOMATA_POINT_H
#define AUTOMATA_POINT_H


class Point {
public:
    int x, y, index;
    bool visited;

    Point();

    double distanceTo(Point *p);
};


#endif //AUTOMATA_POINT_H
