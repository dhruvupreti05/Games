SRCDIR     = ./src
OBJDIR     = ./build
INCDIR     = $(SRCDIR)/include

PROJECT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
ROOT_DIR    := $(abspath $(PROJECT_DIR)/..)

GLAD_INC   = $(ROOT_DIR)/glad/include
GLAD_SRC   = $(ROOT_DIR)/glad.c

CXX        = g++
CC         = gcc

CXXFLAGS   = -std=c++17 \
             -I$(INCDIR) \
             -I$(GLAD_INC) \
             -I/opt/homebrew/include \
             -I/opt/homebrew/opt/glfw/include \
             -I/opt/homebrew/opt/glew/include

LDFLAGS    = -L/opt/homebrew/opt/glfw/lib \
             -L/opt/homebrew/opt/glew/lib \
             -lglfw -lGLEW -framework OpenGL \
             -framework Cocoa -framework IOKit -framework CoreVideo

APPNAME    = run_opengl

SOURCES    = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS    = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES)) $(OBJDIR)/glad.o

$(shell mkdir -p $(OBJDIR))

all: $(APPNAME)

$(APPNAME): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -c $< $(CXXFLAGS) -o $@

$(OBJDIR)/glad.o: $(GLAD_SRC)
	$(CC) -c $< -I$(GLAD_INC) -o $@

clean:
	rm -f $(OBJDIR)/*.o $(APPNAME)

.PHONY: all clean
