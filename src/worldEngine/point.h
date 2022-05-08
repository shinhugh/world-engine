// Point definition

#ifndef POINT_H
#define POINT_H

namespace WorldEngine {

  struct Point {

    const unsigned long long int id; // TODO: Only make visible to World
    int referenceCount; // TODO: Only make visible to World
    double posX, posY, posZ;
    double velX, velY, velZ;

    Point(unsigned long long int);
    Point(unsigned long long int, double, double, double, double, double,
    double);

  };

}

#endif
