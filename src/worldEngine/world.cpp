// World state manager implementation

#include <map>
#include <typeinfo>
#include <util/util.h>
#include <worldEngine/point.h>
#include <worldEngine/pointInternal.h>
#include <worldEngine/triangle.h>
#include <worldEngine/triangleInternal.h>
#include <worldEngine/world.h>

namespace WorldEngine {

  // TODO: Thread-safety

  class WorldImpl {

  private:

    std::map<unsigned long long int, PointInternal> points;
    std::map<unsigned long long int, TriangleInternal> triangles;

    unsigned long long int generateId() {
      static unsigned long long int nextId = 0;
      while (points.count(nextId) || triangles.count(nextId)) {
        nextId++;
      }
      return nextId++;
    }

  public:

    WorldImpl() { }

    WorldImpl(const WorldImpl &src) {
      // TODO: Copy points
      // TODO: Create mapping of Points and use it to copy Triangles
    }

    ~WorldImpl() { }

    WorldImpl & operator=(const WorldImpl &src) {
      // TODO: Reset
      // TODO: Copy points
      // TODO: Create mapping of Points and use it to copy Triangles
      return *this;
    }

    Point & createPoint() {
      unsigned long long int id = generateId();
      points.insert({id, PointInternal(id)});
      return points.at(id);
    }

    Point & createPoint(double posX, double posY, double posZ, double velX,
    double velY, double velZ) {
      unsigned long long int id = generateId();
      points.insert({id, PointInternal(id, posX, posY, posZ, velX, velY,
      velZ)});
      return points.at(id);
    }

    bool destroyPoint(Point &point) {
      if (!dynamic_cast<PointInternal *>(&point)) {
        return false;
      }
      PointInternal &pointInternal = static_cast<PointInternal &>(point);
      if (!points.count(pointInternal.id)) {
        return false;
      }
      if (pointInternal.referenceCount) {
        return false;
      }
      points.erase(pointInternal.id);
      return true;
    }

    Triangle & createTriangle(Point &pointA, Point &pointB, Point &pointC) {
      if (!dynamic_cast<PointInternal *>(&pointA)
      || !dynamic_cast<PointInternal *>(&pointB)
      || !dynamic_cast<PointInternal *>(&pointC)) {
        // TODO: Indicate failure somehow
      }
      PointInternal &pointInternalA = static_cast<PointInternal &>(pointA);
      PointInternal &pointInternalB = static_cast<PointInternal &>(pointB);
      PointInternal &pointInternalC = static_cast<PointInternal &>(pointC);
      if (!points.count(pointInternalA.id) || !points.count(pointInternalB.id)
      || !points.count(pointInternalC.id)) {
        // TODO: Indicate failure somehow
      }
      pointInternalA.referenceCount++;
      pointInternalB.referenceCount++;
      pointInternalC.referenceCount++;
      unsigned long long int id = generateId();
      triangles.insert({id, TriangleInternal(id, pointA, pointB, pointC)});
      return triangles.at(id);
    }

    bool destroyTriangle(Triangle &triangle) {
      if (!dynamic_cast<TriangleInternal *>(&triangle)) {
        return false;
      }
      TriangleInternal &triangleInternal = static_cast<TriangleInternal &>
      (triangle);
      if (!triangles.count(triangleInternal.id)) {
        return false;
      }
      static_cast<PointInternal &>(triangle.pointA).referenceCount--;
      static_cast<PointInternal &>(triangle.pointB).referenceCount--;
      static_cast<PointInternal &>(triangle.pointC).referenceCount--;
      triangles.erase(triangleInternal.id);
      return true;
    }

    void update() { // TODO: Add parameter for elapsed time
      // TODO: Update position for each Point by using its velocities and
      //       the elapsed time
    }

  };

  // ----------------------------------------

  World::World() :
  impl(new WorldImpl()) { }

  World::World(const World &src) :
  impl(new WorldImpl(*(WorldImpl *)src.impl)) { }

  World::~World() {
    delete (WorldImpl *)impl;
  }

  World & World::operator=(const World &src) {
    WorldImpl &worldImpl = *(WorldImpl *)impl;
    worldImpl = *(WorldImpl *)src.impl;
    return *this;
  }

  Point & World::createPoint() {
    WorldImpl &worldImpl = *(WorldImpl *)impl;
    return worldImpl.createPoint();
  }

  Point & World::createPoint(double posX, double posY, double posZ, double velX,
  double velY, double velZ) {
    WorldImpl &worldImpl = *(WorldImpl *)impl;
    return worldImpl.createPoint(posX, posY, posZ, velX, velY, velZ);
  }

  bool World::destroyPoint(Point &point) {
    WorldImpl &worldImpl = *(WorldImpl *)impl;
    return worldImpl.destroyPoint(point);
  }

  Triangle & World::createTriangle(Point &pointA, Point &pointB,
  Point &pointC) {
    WorldImpl &worldImpl = *(WorldImpl *)impl;
    return worldImpl.createTriangle(pointA, pointB, pointC);
  }

  bool World::destroyTriangle(Triangle &triangle) {
    WorldImpl &worldImpl = *(WorldImpl *)impl;
    return worldImpl.destroyTriangle(triangle);
  }

  void World::update() {
    WorldImpl &worldImpl = *(WorldImpl *)impl;
    worldImpl.update();
  }

}
