// Driver thread definition

#ifndef DRIVER_H
#define DRIVER_H

#include <worldEngine/world.h>

namespace WorldEngine {

  class Driver {

  private:

    void *impl;

  public:

    Driver(World &);
    Driver(const Driver &);
    ~Driver();
    Driver & operator=(const Driver &);
    bool isPlaying();
    void play();
    void pause();

  };

}

#endif
