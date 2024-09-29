# Compiler and flags
CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Source file
SRC = main.cpp buffers.cpp renderer.cpp

# Output binary
TARGET = main

# Libraries to link
LIBS = -lglfw -lGLEW -lGL

# Includes (adjust these paths if your GLM headers are elsewhere)
INCLUDES = -I/usr/include

# Build the project
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRC) -o $(TARGET) $(LIBS)

# Clean the build
clean:
	rm -f $(TARGET)
