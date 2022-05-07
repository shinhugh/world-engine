// Triangle definition

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <worldEngine/point.h>

namespace WorldEngine {

  struct Triangle {

    Point &pointA, &pointB, &pointC;

    Triangle(Point &, Point &, Point &);

  };

}

#endif
