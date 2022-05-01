// Driver thread definition

#ifndef DRIVER_H
#define DRIVER_H

namespace WorldEngine {

  class Driver {

  private:

    void *impl;

  public:

    Driver();
    Driver(const Driver &);
    ~Driver();
    Driver & operator=(const Driver &);
    // TODO

  };

}

#endif