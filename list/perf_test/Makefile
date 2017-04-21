CXX = g++
CXXFLAGS = -std=c++11 -I/usr/local/include/stlsoft
OBJS = perf_test.o

all: perf_test

perf_test: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

perf_test.o: perf_test.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf perf_test *.o
