// Point definition

#ifndef POINT_H
#define POINT_H

namespace WorldEngine {

  struct Point {

    double posX, posY, posZ;
    double velX, velY, velZ;

    Point();
    Point(double, double, double, double, double, double);

  };

}

#endif
