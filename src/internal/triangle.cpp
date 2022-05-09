// Triangle implementation

#include <public/point.h>
#include <public/triangle.h>

namespace WorldEngine {

  Triangle::Triangle(Point &pointA, Point &pointB, Point &pointC) :
  pointA(pointA), pointB(pointB), pointC(pointC) { }

  Triangle::~Triangle() { }

}
