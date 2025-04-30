# compiler 
CXX := g++ 

# compiler flags -Wall warning all, -I include
CXXFLAGS := -Wall -std=c++20 -Iinclude

# target output
TARGET := textquery

# source files wildcard: all *.cpps with space among them
SRCS := $(wildcard src/*.cpp)

# object files patsubst: pattern substitute
OBJS := $(patsubst src/%.cpp, build/%.o, $(SRCS))

# default target
all: $(TARGET) 

# link and output
$(TARGET): $(OBJS) 
	$(CXX) $(CXXFLAGS) $^ -o build/$@
# build .cpp to .o, % means all possible
build/%.o: src/%.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@

# run
run: $(TARGET)
	cd build && ./$(TARGET) && cd ..
clean:
	rm -rf build $(TARGET)

.PHONY: all clean run
