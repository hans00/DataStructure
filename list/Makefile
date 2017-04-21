CXX = g++
CXXFLAGS = -std=c++11
OBJS = list.o

all: list

list: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

list.o: list.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf list *.o
