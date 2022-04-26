# World Engine

**This project is a work-in-progress.**

The world engine is a state machine that virtualizes a 3-dimensional space with
objects that respond to the flow of time. It is designed to support frequent
reads and writes by external clients, such as a graphics thread or a user input
handler thread.

This is not a physics engine. There is no built-in concept of acceleration,
Pauli exclusion principle (two things cannot occupy the same space at the same
time), etc. However, an external client can enforce such rules by consistently
checking and modifying the state.

Note that, although the provided demo presents a live graphical representation
of the world engine's state, this library itself does not provide graphical
capabilities. It is purely a state machine.

## Building

### World engine library

To build the world engine library for static linking, run:

```
make
```

This will create `build/libworldEngine.a`. Use this binary in conjunction with
the header files under `src/worldEngine/`.

### Demo executable

The OpenGL library is required in order to build the demo executable.
*TODO: Instructions on and requirements for getting OpenGL*

To build the demo executable, run:

```
make demo
```

This will create `build/demo.out`.

## Architecture

![Architecture diagram](https://github.com/shinhugh/world-engine/blob/master/architecture-diagram.png?raw=true)

As object-oriented design dictates, each material object in our virtual space
is represented by a runtime object in our program. Each runtime object holds
various data fields (e.g. x-, y-, and z-coordinates within our virtual space),
and these fields are repeatedly and rapidly updated by a driver thread. To
execute these updates, the thread must consider various other fields and
conditions (e.g. velocity and elapsed time since last update).

All of these state objects are collectively owned by the engine but openly
exposed to external clients, as it doesn't make much sense to build a state
engine that doesn't support representation.

The engine is responsible for managing all of the memory associated with the
state objects as well as the lifecycle of the thread driving the state updates.

Naturally, thread-safety is crucial in this architecture. As concurrency is
everywhere, it's critical that there are no race conditions between the driver
thread and any external client thread (e.g. a graphics thread). Mutexes
frequently come into play, so it's important to take special care to avoid
deadlocks as well. The provided implementation takes care of all this, so
there's no need for external clients to provide their own layer of thread-safety
if they're using the provided interface.

Refer to the demo code for an example setup.
