// Utilities definitions

#ifndef UTIL_H
#define UTIL_H

#include <string>

namespace Util {

  extern bool logEnabled;

  void log(const std::string &);
  void logAddress(const void *);

}

#endif
