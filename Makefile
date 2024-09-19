# Compiler and flags
CXX = clang++
CXXFLAGS = -std=c++2a -I/usr/include -I/usr/local/include $(shell pkg-config --cflags glfw3)
LDFLAGS = $(shell pkg-config --libs glfw3)
LIBS = -lGLEW -lGL

# Source files and executable
SRC = main.cpp
EXEC = main

# Targets
all: $(EXEC)

$(EXEC):
	$(CXX) $(SRC) $(CXXFLAGS) $(LDFLAGS) $(LIBS) -o $(EXEC)

clean:
	rm -f $(EXEC)
