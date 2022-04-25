# Makefile

# --------------------------------------------------

# Variables

PATH_ROOT := $(patsubst %/,%,$(dir $(abspath $(lastword $(MAKEFILE_LIST)))))
PATH_BUILD := $(PATH_ROOT)/build
PATH_SRC := $(PATH_ROOT)/src

EXE := \
$(PATH_BUILD)/build.out
OBJ := \
$(PATH_BUILD)/config.o \
$(PATH_BUILD)/main.o \
$(PATH_BUILD)/util.o

# --------------------------------------------------

# Unconditional targets

.PHONY : default clean exe obj

# --------------------------------------------------

# Default target

default : $(PATH_BUILD)/build.out

# --------------------------------------------------

# Clean

clean :
	@echo "Removing executable and object files"
	@rm $(EXE) $(OBJ) -f

# --------------------------------------------------

# Create build directory

build :
	@echo "Creating build directory"
	@mkdir $(PATH_BUILD) -p

# --------------------------------------------------

# Build all executable files

exe : $(EXE)
	@echo "Removing object files"
	@rm $(OBJ) -f

# --------------------------------------------------

# Build executable files

$(PATH_BUILD)/build.out : \
$(PATH_BUILD)/config.o \
$(PATH_BUILD)/main.o \
$(PATH_BUILD)/util.o \
| build
	@echo "Building: build.out"
	@g++ $^ -o $@

# --------------------------------------------------

# Build all object files

obj : $(OBJ)

# --------------------------------------------------

# Build object files

$(PATH_BUILD)/config.o : \
$(PATH_SRC)/config.cpp \
$(PATH_SRC)/config.h \
| build
	@echo "Building: config.o"
	@g++ $< -c -o $@ -I$(PATH_SRC)

$(PATH_BUILD)/main.o : \
$(PATH_SRC)/main.cpp \
$(PATH_SRC)/config.h \
$(PATH_SRC)/util/util.h \
| build
	@echo "Building: main.o"
	@g++ $< -c -o $@ -I$(PATH_SRC)

$(PATH_BUILD)/util.o : \
$(PATH_SRC)/util/util.cpp \
$(PATH_SRC)/util/util.h \
| build
	@echo "Building: util.o"
	@g++ $< -c -o $@ -I$(PATH_SRC)
