// World state manager definition

#ifndef WORLD_H
#define WORLD_H

#include <worldEngine/point.h>
#include <worldEngine/triangle.h>

namespace WorldEngine {

  class World {

  private:

    void *impl;

  public:

    World();
    World(const World &);
    ~World();
    World & operator=(const World &);
    Point & createPoint();
    Point & createPoint(double, double, double, double, double, double);
    bool destroyPoint(Point &);
    Triangle & createTriangle(Point &, Point &, Point &);
    bool destroyTriangle(Triangle &);
    void update();

  };

}

#endif
