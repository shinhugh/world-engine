// Triangle implementation

#include <worldEngine/point.h>
#include <worldEngine/triangle.h>

namespace WorldEngine {

  Triangle::Triangle(unsigned long long int id, Point &pointA, Point &pointB,
  Point &pointC) :
  id(id), pointA(pointA), pointB(pointB), pointC(pointC) { }

}
