CXX=g++
CXXFLAGS=-Wall -Werror -pedantic -std=c++20 -Wextra

OBJ=hello_world.o
TARGET=target

all: $(TARGET)

$(TARGET): $(OBJ)
    $(CXX) $(CXXFLAGS) -o $@ $^


clean:
    $(RM) $(TARGET) $(OBJ)
