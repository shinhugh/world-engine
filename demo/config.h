// Program config definitions

#ifndef CONFIG_H
#define CONFIG_H

struct Config {

  bool debugMode = false;

  static bool processArguments(int, const char * const *, Config &);

};

#endif
