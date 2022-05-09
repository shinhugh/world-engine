# Makefile

# --------------------------------------------------

# Variables

PATH_ROOT := $(patsubst %/,%,$(dir $(abspath $(lastword $(MAKEFILE_LIST)))))
PATH_BUILD := $(PATH_ROOT)/build
PATH_SRC := $(PATH_ROOT)/src
PATH_DEMO := $(PATH_ROOT)/demo

OBJ := \
$(PATH_BUILD)/config.o \
$(PATH_BUILD)/driver.o \
$(PATH_BUILD)/main.o \
$(PATH_BUILD)/point.o \
$(PATH_BUILD)/pointInternal.o \
$(PATH_BUILD)/triangle.o \
$(PATH_BUILD)/triangleInternal.o \
$(PATH_BUILD)/utilInternal.o \
$(PATH_BUILD)/world.o
LIB := \
$(PATH_BUILD)/libworldEngine.a
EXE := \
$(PATH_BUILD)/demo.out

# --------------------------------------------------

# Unconditional targets

.PHONY : default clean obj lib demo

# --------------------------------------------------

# Default target

default : lib

# --------------------------------------------------

# Clean

clean :
	@echo "Removing executable and object files"
	@rm $(OBJ) $(LIB) $(EXE) -f

# --------------------------------------------------

# Build all object files

obj : $(OBJ)

# --------------------------------------------------

# Build static library

lib : $(PATH_BUILD)/libworldEngine.a
	@echo "Removing object files"
	@rm $(OBJ) -f

# --------------------------------------------------

# Build demo executable file

demo : $(PATH_BUILD)/demo.out
	@echo "Removing object files and libraries"
	@rm $(OBJ) $(LIB) -f

# --------------------------------------------------

# Create build directory

build :
	@echo "Creating build directory"
	@mkdir $(PATH_BUILD) -p

# --------------------------------------------------

# Build object files

$(PATH_BUILD)/config.o : \
$(PATH_DEMO)/config.cpp \
$(PATH_DEMO)/config.h \
| build
	@echo "Building: config.o"
	@g++ $< -c -Wall -Wextra -o $@ -I$(PATH_SRC) -I$(PATH_DEMO)

$(PATH_BUILD)/driver.o : \
$(PATH_SRC)/internal/driver.cpp \
$(PATH_SRC)/internal/utilInternal.h \
$(PATH_SRC)/public/driver.h \
$(PATH_SRC)/public/world.h \
| build
	@echo "Building: driver.o"
	@g++ $< -c -Wall -Wextra -o $@ -I$(PATH_SRC)

$(PATH_BUILD)/main.o : \
$(PATH_DEMO)/main.cpp \
$(PATH_DEMO)/config.h \
$(PATH_SRC)/public/driver.h \
$(PATH_SRC)/public/point.h \
$(PATH_SRC)/public/triangle.h \
$(PATH_SRC)/public/util.h \
$(PATH_SRC)/public/world.h \
| build
	@echo "Building: main.o"
	@g++ $< -c -Wall -Wextra -o $@ -I$(PATH_SRC) -I$(PATH_DEMO)

$(PATH_BUILD)/point.o : \
$(PATH_SRC)/internal/point.cpp \
$(PATH_SRC)/public/point.h \
| build
	@echo "Building: point.o"
	@g++ $< -c -Wall -Wextra -o $@ -I$(PATH_SRC)

$(PATH_BUILD)/pointInternal.o : \
$(PATH_SRC)/internal/pointInternal.cpp \
$(PATH_SRC)/internal/pointInternal.h \
$(PATH_SRC)/public/point.h \
| build
	@echo "Building: pointInternal.o"
	@g++ $< -c -Wall -Wextra -o $@ -I$(PATH_SRC)

$(PATH_BUILD)/triangle.o : \
$(PATH_SRC)/internal/triangle.cpp \
$(PATH_SRC)/public/point.h \
$(PATH_SRC)/public/triangle.h \
| build
	@echo "Building: triangle.o"
	@g++ $< -c -Wall -Wextra -o $@ -I$(PATH_SRC)

$(PATH_BUILD)/triangleInternal.o : \
$(PATH_SRC)/internal/triangleInternal.cpp \
$(PATH_SRC)/internal/triangleInternal.h \
$(PATH_SRC)/public/point.h \
$(PATH_SRC)/public/triangle.h \
| build
	@echo "Building: triangleInternal.o"
	@g++ $< -c -Wall -Wextra -o $@ -I$(PATH_SRC)

$(PATH_BUILD)/utilInternal.o : \
$(PATH_SRC)/internal/utilInternal.cpp \
$(PATH_SRC)/internal/utilInternal.h \
$(PATH_SRC)/public/util.h \
| build
	@echo "Building: utilInternal.o"
	@g++ $< -c -Wall -Wextra -o $@ -I$(PATH_SRC)

$(PATH_BUILD)/world.o : \
$(PATH_SRC)/internal/world.cpp \
$(PATH_SRC)/internal/pointInternal.h \
$(PATH_SRC)/internal/triangleInternal.h \
$(PATH_SRC)/internal/utilInternal.h \
$(PATH_SRC)/public/point.h \
$(PATH_SRC)/public/triangle.h \
$(PATH_SRC)/public/world.h \
| build
	@echo "Building: world.o"
	@g++ $< -c -Wall -Wextra -o $@ -I$(PATH_SRC)

# --------------------------------------------------

# Build static libraries

$(PATH_BUILD)/libworldEngine.a : \
$(PATH_BUILD)/driver.o \
$(PATH_BUILD)/point.o \
$(PATH_BUILD)/pointInternal.o \
$(PATH_BUILD)/triangle.o \
$(PATH_BUILD)/triangleInternal.o \
$(PATH_BUILD)/utilInternal.o \
$(PATH_BUILD)/world.o \
| build
	@echo "Building: libworldEngine.a"
	@ar rcs $@ $^

# --------------------------------------------------

# Build executable files

$(PATH_BUILD)/demo.out : \
$(PATH_BUILD)/config.o \
$(PATH_BUILD)/libworldEngine.a \
$(PATH_BUILD)/main.o \
| build
	@echo "Building: demo.out"
	@g++ $^ -o $@ -L$(PATH_BUILD) -lworldEngine
