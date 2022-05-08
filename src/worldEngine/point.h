// Point definition

#ifndef POINT_H
#define POINT_H

namespace WorldEngine {

  class Point {

  protected:

    Point();
    Point(double, double, double, double, double, double);
    virtual ~Point();

  public:

    double posX, posY, posZ, velX, velY, velZ;

  };

}

#endif
