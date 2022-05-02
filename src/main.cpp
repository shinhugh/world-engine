// Program entry point

#include <config.h>
#include <util/util.h>

int main(int argc, char *argv[]) {
  Config config;
  Config::processArguments(argc, argv, config);
  Util::logEnabled = config.debugMode;

  // TODO
}
