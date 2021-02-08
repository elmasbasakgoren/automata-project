#include<iostream>
#include<fstream>
#include<sstream>
#include "Point.h"

using namespace std;

const int POINT_COUNT = 48;

Point *points[POINT_COUNT];
int nextPointIndex = 0;
double totalDistance = 0;


void readCordinates() {
    string word;
    ifstream list("/Users/Elmas/att48_xy.txt");
    if (!list.is_open()) {
        cout << "Unable to open file";
        return;
    }
    int iteration = 0;
    while (list >> word) {
        if(iteration % 2 == 0){
            points[iteration / 2] = new Point();
            points[iteration / 2]->index = iteration / 2;
            stringstream convert(word);
            convert >> points[iteration / 2]->x;
        } else {
            stringstream convert(word);
            convert >> points[iteration / 2]->y;
        }
        iteration++;
    }

    list.close();
}

int findIndexOfNearestNonVisitedPoint(Point *from, int startIndex, int endIndex) {
    double shortestDistance = -1;
    int nearestIndex = -1;
    for (int i = startIndex; i <= endIndex; i++) {
        if (from->index == i || points[i]->visited) {
            continue;
        }
        if(shortestDistance == -1 || shortestDistance > from->distanceTo(points[i])){
            shortestDistance = from->distanceTo(points[i]);
            nearestIndex = i;
        }
    }
    totalDistance += shortestDistance;
    points[nearestIndex]->visited = true;
    nextPointIndex = nearestIndex;
    return nearestIndex;
}

void nearestNeighbour(int startIndex, int endIndex,int *output, bool completeCircle = true) {
    points[startIndex]->visited = true;
    nextPointIndex = startIndex;
    for (int i = startIndex; i < endIndex; i++) {
        output[i] = findIndexOfNearestNonVisitedPoint(points[nextPointIndex], startIndex, endIndex);
    }
    if(completeCircle){
        totalDistance += points[nextPointIndex]->distanceTo(points[startIndex]);
    }
}

void divideAndConquer() {
    int output[48];
    nearestNeighbour(0, 23, output, false);

    nearestNeighbour(24, 47, output, false);

    output[23] = 24;
    totalDistance += points[output[22]]->distanceTo(points[output[23]]);

    output[47] = 0;
    totalDistance += points[output[46]]->distanceTo(points[output[47]]);


    for (int i = 0; i < 48; ++i) {
        cout << i << " - " << output[i] << endl;
    }
}

int main() {
    readCordinates();
//    int output[48];
//    nearestNeighbour(0, 47, output, true);
//    for (int i = 0; i < 47; ++i) {
//        cout << output[i] << endl;
//    }

    divideAndConquer();
    cout << totalDistance << endl;

    return 0;
}
