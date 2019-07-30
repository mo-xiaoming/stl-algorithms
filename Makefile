CXX_FILES=$(wildcard *.cpp)
OBJ_FILES=$(CXX_FILES:%.cpp=build/%.o)
BOOST_INCLUDE=/home/mx/boost/include
BOOST_LIBS=/home/mx/boost/lib

.PHONY: all clean
.DEFAULT: all

all: a.out

a.out: $(OBJ_FILES)
	g++ -o $@ $^

build:
	@mkdir -p build

build/%.o: %.cpp | build
	g++ -I$(BOOST_INCLUDE) -std=c++17 -Wall -Wextra -Wpedantic -c $< -o $@

clean:
	@-rm -rf build
