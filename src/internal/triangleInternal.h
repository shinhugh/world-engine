// Triangle internal definition

#ifndef TRIANGLE_INTERNAL_H
#define TRIANGLE_INTERNAL_H

#include <public/point.h>
#include <public/triangle.h>

namespace WorldEngine {

  class TriangleInternal : public Triangle {

  public:

    const unsigned long long int id;

    TriangleInternal(unsigned long long int, Point &, Point &, Point &);

  };

}

#endif
