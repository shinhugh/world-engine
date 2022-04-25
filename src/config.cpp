// Program config implementations

#include <cstring>
#include <iostream>
#include <config.h>

bool Config::processArguments(int argc, const char * const *argv,
Config &config) {
  Config parsed = {
    .debugMode = false
  };

  for (int i = 1; i < argc; i++) {
    if (!strcmp(argv[i], "--debug") || !strcmp(argv[i], "-d")) {
      if (parsed.debugMode) {
        std::cout << "Duplicate argument: " << argv[i] << std::endl;
        return false;
      }
      parsed.debugMode = true;
    }

    else {
      std::cout << "Unrecognized argument: " << argv[i] << std::endl;
      return false;
    }
  }

  config = parsed;
  return true;
}
