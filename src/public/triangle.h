// Triangle definition

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <public/point.h>

namespace WorldEngine {

  class Triangle {

  protected:

    Triangle(Point &, Point &, Point &);
    virtual ~Triangle();

  public:

    Point &pointA, &pointB, &pointC;

  };

}

#endif
