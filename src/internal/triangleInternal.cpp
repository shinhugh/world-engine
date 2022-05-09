// Triangle internal implementation

#include <internal/triangleInternal.h>
#include <public/point.h>
#include <public/triangle.h>

namespace WorldEngine {

  TriangleInternal::TriangleInternal(unsigned long long int id, Point &pointA,
  Point &pointB, Point &pointC) :
  Triangle(pointA, pointB, pointC), id(id) { }

}
