// Program entry point

#include <config.h>
#include <util/util.h>
#include <worldEngine/driver.h>

int main(int argc, char *argv[]) {
  Config config;
  Config::processArguments(argc, argv, config);
  Util::logEnabled = config.debugMode;

  WorldEngine::Driver *driver = new WorldEngine::Driver();
  delete driver;
}
