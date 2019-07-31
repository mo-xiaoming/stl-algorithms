CXX_FILES=$(wildcard *.cpp)
OBJ_FILES=$(CXX_FILES:%.cpp=build/%.o)
BOOST_INCLUDE=/home/mx/boost/include
BOOST_LIBS=/home/mx/boost/lib
CATCH_INCLUDE=/home/mx/catchorg

.PHONY: all clean
.DEFAULT: all

all: a.out

a.out: $(OBJ_FILES)
	g++ -o $@ $^

build:
	@mkdir -p build

build/%.o: %.cpp | build
	g++ -isystem $(BOOST_INCLUDE) -isystem $(CATCH_INCLUDE) -std=c++17 -Wall -Wextra -Wpedantic -c $< -o $@

clean:
	@-rm -rf build
