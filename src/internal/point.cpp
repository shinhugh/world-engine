// Point implementation

#include <public/point.h>

namespace WorldEngine {

  Point::Point() :
  posX(0), posY(0), posZ(0), velX(0), velY(0), velZ(0) { }

  Point::Point(double posX, double posY, double posZ, double velX, double velY,
  double velZ) :
  posX(posX), posY(posY), posZ(posZ), velX(velX), velY(velY), velZ(velZ) { }

  Point::~Point() { }

}
