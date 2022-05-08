# Makefile

# --------------------------------------------------

# Variables

PATH_ROOT := $(patsubst %/,%,$(dir $(abspath $(lastword $(MAKEFILE_LIST)))))
PATH_BUILD := $(PATH_ROOT)/build
PATH_SRC := $(PATH_ROOT)/src

EXE := \
$(PATH_BUILD)/demo.out
OBJ := \
$(PATH_BUILD)/config.o \
$(PATH_BUILD)/driver.o \
$(PATH_BUILD)/main.o \
$(PATH_BUILD)/point.o \
$(PATH_BUILD)/pointInternal.o \
$(PATH_BUILD)/triangle.o \
$(PATH_BUILD)/triangleInternal.o \
$(PATH_BUILD)/util.o \
$(PATH_BUILD)/world.o

# --------------------------------------------------

# Unconditional targets

.PHONY : default clean obj exe lib demo

# --------------------------------------------------

# Default target

default : demo

# --------------------------------------------------

# Clean

clean :
	@echo "Removing executable and object files"
	@rm $(EXE) $(OBJ) -f

# --------------------------------------------------

# Build all object files

obj : $(OBJ)

# --------------------------------------------------

# Build all executable files and remove object files

exe : $(EXE)
	@echo "Removing object files"
	@rm $(OBJ) -f

# --------------------------------------------------

# Build static library

lib :
	@echo "This target has not been set up yet."

# --------------------------------------------------

# Build demo executable

demo : $(PATH_BUILD)/demo.out

# --------------------------------------------------

# Create build directory

build :
	@echo "Creating build directory"
	@mkdir $(PATH_BUILD) -p

# --------------------------------------------------

# Build executable files

$(PATH_BUILD)/demo.out : \
$(PATH_BUILD)/config.o \
$(PATH_BUILD)/driver.o \
$(PATH_BUILD)/main.o \
$(PATH_BUILD)/point.o \
$(PATH_BUILD)/pointInternal.o \
$(PATH_BUILD)/triangle.o \
$(PATH_BUILD)/triangleInternal.o \
$(PATH_BUILD)/util.o \
$(PATH_BUILD)/world.o \
| build
	@echo "Building: demo.out"
	@g++ $^ -o $@ -lGL -lGLU -lglut

# --------------------------------------------------

# Build object files

$(PATH_BUILD)/config.o : \
$(PATH_SRC)/config.cpp \
$(PATH_SRC)/config.h \
| build
	@echo "Building: config.o"
	@g++ $< -c -Wall -Wextra -o $@ -I$(PATH_SRC)

$(PATH_BUILD)/driver.o : \
$(PATH_SRC)/worldEngine/driver.cpp \
$(PATH_SRC)/util/util.h \
$(PATH_SRC)/worldEngine/driver.h \
$(PATH_SRC)/worldEngine/world.h \
| build
	@echo "Building: driver.o"
	@g++ $< -c -Wall -Wextra -o $@ -I$(PATH_SRC)

$(PATH_BUILD)/main.o : \
$(PATH_SRC)/main.cpp \
$(PATH_SRC)/config.h \
$(PATH_SRC)/util/util.h \
$(PATH_SRC)/worldEngine/driver.h \
$(PATH_SRC)/worldEngine/point.h \
$(PATH_SRC)/worldEngine/triangle.h \
$(PATH_SRC)/worldEngine/world.h \
| build
	@echo "Building: main.o"
	@g++ $< -c -Wall -Wextra -o $@ -I$(PATH_SRC)

$(PATH_BUILD)/point.o : \
$(PATH_SRC)/worldEngine/point.cpp \
$(PATH_SRC)/worldEngine/point.h \
| build
	@echo "Building: point.o"
	@g++ $< -c -Wall -Wextra -o $@ -I$(PATH_SRC)

$(PATH_BUILD)/pointInternal.o : \
$(PATH_SRC)/worldEngine/pointInternal.cpp \
$(PATH_SRC)/worldEngine/point.h \
$(PATH_SRC)/worldEngine/pointInternal.h \
| build
	@echo "Building: pointInternal.o"
	@g++ $< -c -Wall -Wextra -o $@ -I$(PATH_SRC)

$(PATH_BUILD)/triangle.o : \
$(PATH_SRC)/worldEngine/triangle.cpp \
$(PATH_SRC)/worldEngine/point.h \
$(PATH_SRC)/worldEngine/triangle.h \
| build
	@echo "Building: triangle.o"
	@g++ $< -c -Wall -Wextra -o $@ -I$(PATH_SRC)

$(PATH_BUILD)/triangleInternal.o : \
$(PATH_SRC)/worldEngine/triangleInternal.cpp \
$(PATH_SRC)/worldEngine/point.h \
$(PATH_SRC)/worldEngine/triangle.h \
$(PATH_SRC)/worldEngine/triangleInternal.h \
| build
	@echo "Building: triangleInternal.o"
	@g++ $< -c -Wall -Wextra -o $@ -I$(PATH_SRC)

$(PATH_BUILD)/util.o : \
$(PATH_SRC)/util/util.cpp \
$(PATH_SRC)/util/util.h \
| build
	@echo "Building: util.o"
	@g++ $< -c -Wall -Wextra -o $@ -I$(PATH_SRC)

$(PATH_BUILD)/world.o : \
$(PATH_SRC)/worldEngine/world.cpp \
$(PATH_SRC)/util/util.h \
$(PATH_SRC)/worldEngine/point.h \
$(PATH_SRC)/worldEngine/pointInternal.h \
$(PATH_SRC)/worldEngine/triangle.h \
$(PATH_SRC)/worldEngine/triangleInternal.h \
$(PATH_SRC)/worldEngine/world.h \
| build
	@echo "Building: world.o"
	@g++ $< -c -Wall -Wextra -o $@ -I$(PATH_SRC)
