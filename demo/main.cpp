// Demo program entry point

#include <config.h>
#include <public/driver.h>
#include <public/point.h>
#include <public/triangle.h>
#include <public/util.h>
#include <public/world.h>

int main(int argc, char *argv[]) {
  // Configure program
  Config config;
  Config::processArguments(argc, argv, config);
  Util::logEnabled = config.debugMode;

  // Create world
  WorldEngine::World world;

  // Create and start state driver thread
  WorldEngine::Driver *driver = new WorldEngine::Driver(world);
  driver->play();

  // Populate world
  WorldEngine::Point &p0 = world.createPoint(),
  &p1 = world.createPoint(1, 0, 0, 0, 0, 0),
  &p2 = world.createPoint(0, 1, 0, 0, 0, 0),
  &p3 = world.createPoint(0, 0, 1, 0, 0, 0);
  WorldEngine::Triangle &t0 = world.createTriangle(p0, p1, p2),
  &t1 = world.createTriangle(p0, p1, p3),
  &t2 = world.createTriangle(p0, p2, p3),
  &t3 = world.createTriangle(p1, p2, p3);

  // Clean up
  delete driver;

  return 0;
}
