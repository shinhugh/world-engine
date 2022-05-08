// Point implementation

#include <worldEngine/point.h>

namespace WorldEngine {

  Point::Point(unsigned long long int id) :
  id(id), referenceCount(0), posX(0), posY(0), posZ(0), velX(0), velY(0),
  velZ(0) { }

  Point::Point(unsigned long long int id, double posX, double posY, double posZ,
  double velX, double velY, double velZ) :
  id(id), referenceCount(0), posX(posX), posY(posY), posZ(posZ), velX(velX),
  velY(velY), velZ(velZ) { }

}
