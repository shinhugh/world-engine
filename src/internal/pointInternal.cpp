// Point internal implementation

#include <internal/pointInternal.h>
#include <public/point.h>

namespace WorldEngine {

  PointInternal::PointInternal(unsigned long long int id) :
  id(id), referenceCount(0) { }

  PointInternal::PointInternal(unsigned long long int id, double posX,
  double posY, double posZ, double velX, double velY, double velZ) :
  Point(posX, posY, posZ, velX, velY, velZ), id(id), referenceCount(0) { }

}
