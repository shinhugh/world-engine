// Driver thread implementation

#include <worldEngine/driver.h>

namespace WorldEngine {

  class DriverImpl {

  private:

    // TODO

  public:

    DriverImpl() {

    }

    DriverImpl(const DriverImpl &src) {

    }

    ~DriverImpl() {

    }

    DriverImpl & operator=(const DriverImpl &src) {
      return *this;
    }

    // TODO

  };

  // ----------------------------------------

  Driver::Driver() :
  impl(new DriverImpl()) { }

  Driver::Driver(const Driver &src) :
  impl(new DriverImpl(*(DriverImpl *)src.impl)) { }

  Driver::~Driver() {
    delete (DriverImpl *)impl;
  }

  Driver & Driver::operator=(const Driver &src) {
    DriverImpl &driverImpl = *(DriverImpl *)impl;
    driverImpl = *(DriverImpl *)src.impl;
    return *this;
  }

  // TODO

}