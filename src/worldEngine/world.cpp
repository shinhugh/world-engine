// World state manager implementation

#include <map>
#include <util/util.h>
#include <worldEngine/point.h>
#include <worldEngine/triangle.h>
#include <worldEngine/world.h>

namespace WorldEngine {

  // TODO: Thread-safety
  // TODO: Only allow creating Triangles from registered Points
  // TODO: Only allow destroying registered Points and Triangles

  class WorldImpl {

  private:

    std::map<unsigned long long int, Point> points;
    std::map<unsigned long long int, Triangle> triangles;

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
      points.insert({id, Point(id)});
      return points.at(id);
    }

    Point & createPoint(double posX, double posY, double posZ, double velX,
    double velY, double velZ) {
      unsigned long long int id = generateId();
      points.insert({id, Point(id, posX, posY, posZ, velX, velY, velZ)});
      return points.at(id);
    }

    bool destroyPoint(Point &point) {
      if (point.referenceCount) {
        return false;
      }
      points.erase(point.id);
      return true;
    }

    Triangle & createTriangle(Point &pointA, Point &pointB, Point &pointC) {
      pointA.referenceCount++;
      pointB.referenceCount++;
      pointC.referenceCount++;
      unsigned long long int id = generateId();
      triangles.insert({id, Triangle(id, pointA, pointB, pointC)});
      return triangles.at(id);
    }

    bool destroyTriangle(Triangle &triangle) {
      triangle.pointA.referenceCount--;
      triangle.pointB.referenceCount--;
      triangle.pointC.referenceCount--;
      triangles.erase(triangle.id);
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
