// Point internal definition

#ifndef POINT_INTERNAL_H
#define POINT_INTERNAL_H

#include <worldEngine/point.h>

namespace WorldEngine {

  class PointInternal : public Point {

  public:

    const unsigned long long int id;
    unsigned int referenceCount;

    PointInternal(unsigned long long int);
    PointInternal(unsigned long long int, double, double, double, double,
    double, double);

  };

}

#endif
