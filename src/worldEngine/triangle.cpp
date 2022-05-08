// Triangle implementation

#include <worldEngine/point.h>
#include <worldEngine/triangle.h>

namespace WorldEngine {

  Triangle::Triangle(Point &pointA, Point &pointB, Point &pointC) :
  pointA(pointA), pointB(pointB), pointC(pointC) { }

  Triangle::~Triangle() { }

}
