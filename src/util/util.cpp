// Utilities implementations

#include <iostream>
#include <string>
#include <util/util.h>

namespace Util {

  bool logEnabled = false;

  void log(const std::string &message) {
    if (logEnabled) {
      std::cout << message + std::string("\n");
    }
  }

}
