// Triangle internal implementation

#include <worldEngine/point.h>
#include <worldEngine/triangle.h>
#include <worldEngine/triangleInternal.h>

namespace WorldEngine {

  TriangleInternal::TriangleInternal(unsigned long long int id, Point &pointA,
  Point &pointB, Point &pointC) :
  Triangle(pointA, pointB, pointC), id(id) { }

}
