// Utilities implementations

#include <iostream>
#include <sstream>
#include <string>
#include <util/util.h>

namespace Util {

  bool logEnabled = false;

  void log(const std::string &message) {
    if (logEnabled) {
      std::cout << message + std::string("\n");
    }
  }

  void logAddress(const void *pointer) {
    if (logEnabled) {
      std::ostringstream ss;
      ss << pointer;
      std::string address = ss.str();
      std::cout << address + std::string("\n");
    }
  }

}
