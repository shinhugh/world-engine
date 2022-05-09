// World state manager implementation

#include <map>
#include <typeinfo>
#include <internal/pointInternal.h>
#include <internal/triangleInternal.h>
#include <internal/utilInternal.h>
#include <public/point.h>
#include <public/triangle.h>
#include <public/world.h>

namespace WorldEngine {

  // TODO: Expose Points and Triangles without direct access to vectors
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

    void copy(const WorldImpl &src) {
      std::map<const Point *, Point *> pointMap;
      for (std::map<unsigned long long int, PointInternal>::const_iterator it
      = src.points.begin(); it != src.points.end(); it++) {
        points.insert({it->first, it->second});
        pointMap.insert({&it->second, &points.at(it->first)});
      }
      for (std::map<unsigned long long int, TriangleInternal>::const_iterator it
      = src.triangles.begin(); it != src.triangles.end(); it++) {
        Point &pointA = *pointMap.at(&it->second.pointA),
        &pointB = *pointMap.at(&it->second.pointB),
        &pointC = *pointMap.at(&it->second.pointC);
        triangles.insert({it->second.id,
        TriangleInternal(it->second.id, pointA, pointB, pointC)});
      }
    }

  public:

    WorldImpl() { }

    WorldImpl(const WorldImpl &src) {
      copy(src);
    }

    ~WorldImpl() { }

    WorldImpl & operator=(const WorldImpl &src) {
      triangles.clear();
      points.clear();
      copy(src);
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
      PointInternal &pointInternal = dynamic_cast<PointInternal &>(point);
      if (!points.count(pointInternal.id) || pointInternal.referenceCount) {
        return false;
      }
      points.erase(pointInternal.id);
      return true;
    }

    Triangle & createTriangle(Point &pointA, Point &pointB, Point &pointC) {
      PointInternal &pointInternalA = dynamic_cast<PointInternal &>(pointA),
      &pointInternalB = dynamic_cast<PointInternal &>(pointB),
      &pointInternalC = dynamic_cast<PointInternal &>(pointC);
      pointInternalA.referenceCount++;
      pointInternalB.referenceCount++;
      pointInternalC.referenceCount++;
      unsigned long long int id = generateId();
      triangles.insert({id, TriangleInternal(id, pointA, pointB, pointC)});
      return triangles.at(id);
    }

    bool destroyTriangle(Triangle &triangle) {
      TriangleInternal &triangleInternal = dynamic_cast<TriangleInternal &>
      (triangle);
      if (!triangles.count(triangleInternal.id)) {
        return false;
      }
      dynamic_cast<PointInternal &>(triangle.pointA).referenceCount--;
      dynamic_cast<PointInternal &>(triangle.pointB).referenceCount--;
      dynamic_cast<PointInternal &>(triangle.pointC).referenceCount--;
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
