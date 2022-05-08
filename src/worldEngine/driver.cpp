// Driver thread implementation

#include <chrono>
#include <thread>
#include <util/util.h>
#include <worldEngine/driver.h>
#include <worldEngine/world.h>

namespace WorldEngine {

  class DriverImpl {

  private:

    std::thread *thread = 0;
    bool alive = false;
    bool playing = false;
    World *world;

    static void run(DriverImpl *driverImpl) {
      Util::log("Driver thread routine starting");
      while (driverImpl->alive) {
        if (driverImpl->playing) {
          // TODO: Pass in elapsed time, respecting pause time
          driverImpl->world->update();
        }
        else {
          std::this_thread::sleep_for(std::chrono::milliseconds(2));
        }
      }
      Util::log("Driver thread routine finishing");
    }

    void reset() {
      playing = false;
      alive = false;
      if (thread) {
        thread->join();
        delete thread;
      }
    }

    void copy(const DriverImpl &src) {
      world = src.world;
      if (src.alive) {
        alive = true;
        thread = new std::thread(run, this);
        if (src.playing) {
          playing = true;
        }
      }
    }

  public:

    DriverImpl(World &world) :
    world(&world) { }

    DriverImpl(const DriverImpl &src) {
      copy(src);
    }

    ~DriverImpl() {
      reset();
    }

    DriverImpl & operator=(const DriverImpl &src) {
      reset();
      copy(src);
      return *this;
    }

    bool isPlaying() {
      return playing;
    }

    void play() {
      alive = true;
      playing = true;
      if (!thread) {
        thread = new std::thread(run, this);
      }
    }

    void pause() {
      playing = false;
    }

  };

  // ----------------------------------------

  Driver::Driver(World &world) :
  impl(new DriverImpl(world)) { }

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

  bool Driver::isPlaying() {
    DriverImpl &driverImpl = *(DriverImpl *)impl;
    return driverImpl.isPlaying();
  }

  void Driver::play() {
    DriverImpl &driverImpl = *(DriverImpl *)impl;
    driverImpl.play();
  }

  void Driver::pause() {
    DriverImpl &driverImpl = *(DriverImpl *)impl;
    driverImpl.pause();
  }

}
