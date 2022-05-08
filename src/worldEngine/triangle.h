// Triangle definition

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <worldEngine/point.h>

namespace WorldEngine {

  struct Triangle {

    const unsigned long long int id; // TODO: Only make visible to World
    Point &pointA, &pointB, &pointC;

    Triangle(unsigned long long int, Point &, Point &, Point &);

  };

}

#endif
