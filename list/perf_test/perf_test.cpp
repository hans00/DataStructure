#include <platformstl/performance/performance_counter.hpp>
#include <sys/resource.h>
#include <iostream>
#include "../list.hpp"
#include "memory.hpp"

using namespace std;
int main(int argc, char const *argv[])
{
	size_t counter = 0;
	long mem0, mem1;
	platformstl::performance_counter c;

	cout << "Initlize (do 1000000 times)." << endl;

	mem0 = getPeakRSS();
	cout << "Mem before (KB):" << mem0/1024 << endl;

	c.start();
	while (++counter < 1000000) {
		delete new List<size_t>();
	}
	c.stop();
	counter = 0;

	mem1 = getPeakRSS();
	cout << "Mem after (KB):" << mem1/1024 << endl;
	cout << "Use mem (KB):" << (mem1 - mem0)/1024 << endl;
	cout << "time (s): " << c.get_seconds() << endl;
	cout << "time (ms): " << c.get_milliseconds() << endl;
	cout << "time (us): " << c.get_microseconds() << endl;

	List<size_t> list;

	cout << "==========================" << endl;

	cout << "Clean and insert 1000000 items (do 100 times)" << endl;
	mem0 = getPeakRSS();
	cout << "Mem before (KB):" << mem0/1024 << endl;

	c.start();
	while (++counter < 100) {
		list.clean();
		for (size_t i = 0; i < 1000000; ++i) {
			list << i;
		}
	}
	c.stop();
	counter = 0;

	mem1 = getPeakRSS();
	cout << "Mem after (MB):" << mem1/1024/1024 << endl;
	cout << "Use mem (MB):" << (mem1 - mem0)/1024/1024 << endl;
	cout << "time (s): " << c.get_seconds() << endl;
	cout << "time (ms): " << c.get_milliseconds() << endl;
	cout << "time (us): " << c.get_microseconds() << endl;

	cout << "==========================" << endl;

	cout << "list *= 2 (do 100 times)" << endl;
	mem0 = getPeakRSS();
	cout << "Mem before (MB):" << mem0/1024/1024 << endl;

	c.start();
	while (++counter < 100) {
		list *= 2;
	}
	c.stop();
	counter = 0;

	mem1 = getPeakRSS();
	cout << "Mem after (MB):" << mem1/1024/1024 << endl;
	cout << "Use mem (MB):" << (mem1 - mem0)/1024/1024 << endl;
	cout << "time (s): " << c.get_seconds() << endl;
	cout << "time (ms): " << c.get_milliseconds() << endl;
	cout << "time (us): " << c.get_microseconds() << endl;

	cout << "==========================" << endl;

	cout << "list <= 1000000/2 (do 100 times)" << endl;
	mem0 = getPeakRSS();
	cout << "Mem before (MB):" << mem0/1024/1024 << endl;

	c.start();
	while (++counter < 100) {
		list <= 1000000/2;
	}
	c.stop();
	counter = 0;

	mem1 = getPeakRSS();
	cout << "Mem after (MB):" << mem1/1024/1024 << endl;
	cout << "Use mem (MB):" << (mem1 - mem0)/1024/1024 << endl;
	cout << "time (s): " << c.get_seconds() << endl;
	cout << "time (ms): " << c.get_milliseconds() << endl;
	cout << "time (us): " << c.get_microseconds() << endl;

	cout << "==========================" << endl;

	cout << "list[list <= 1000000/2] (do 100 times)" << endl;
	mem0 = getPeakRSS();
	cout << "Mem before (MB):" << mem0/1024/1024 << endl;

	c.start();
	while (++counter < 100) {
		list[list <= 1000000/2];
	}
	c.stop();
	counter = 0;

	mem1 = getPeakRSS();
	cout << "Mem after (MB):" << mem1/1024/1024 << endl;
	cout << "Use mem (MB):" << (mem1 - mem0)/1024/1024 << endl;
	cout << "time (s): " << c.get_seconds() << endl;
	cout << "time (ms): " << c.get_milliseconds() << endl;
	cout << "time (us): " << c.get_microseconds() << endl;

	cout << "==========================" << endl;

	cout << "list(1,0,2) == list[1:][::2] (do 100 times)" << endl;
	mem0 = getPeakRSS();
	cout << "Mem before (MB):" << mem0/1024/1024 << endl;

	c.start();
	while (++counter < 100) {
		list(1,0,2);
	}
	c.stop();
	counter = 0;

	mem1 = getPeakRSS();
	cout << "Mem after (MB):" << mem1/1024/1024 << endl;
	cout << "Use mem (MB):" << (mem1 - mem0)/1024/1024 << endl;
	cout << "time (s): " << c.get_seconds() << endl;
	cout << "time (ms): " << c.get_milliseconds() << endl;
	cout << "time (us): " << c.get_microseconds() << endl;

	cout << "==========================" << endl;

	cout << "list.sort(counter % 2) (do 100 times)" << endl;
	mem0 = getPeakRSS();
	cout << "Mem before (MB):" << mem0/1024/1024 << endl;

	c.start();
	while (++counter < 100) {
		list.sort(counter % 2);
	}
	c.stop();
	counter = 0;

	mem1 = getPeakRSS();
	cout << "Mem after (MB):" << mem1/1024/1024 << endl;
	cout << "Use mem (B):" << (mem1 - mem0) << endl;
	cout << "time (s): " << c.get_seconds() << endl;
	cout << "time (ms): " << c.get_milliseconds() << endl;
	cout << "time (us): " << c.get_microseconds() << endl;

	cout << "==========================" << endl;

	cout << "list.in(ListItem<size_t>(counter)) (do 100 times)" << endl;
	mem0 = getPeakRSS();
	cout << "Mem before (MB):" << mem0/1024/1024 << endl;

	c.start();
	while (++counter < 100) {
		list.in(ListItem<size_t>(counter));
	}
	c.stop();
	counter = 0;

	mem1 = getPeakRSS();
	cout << "Mem after (MB):" << mem1/1024/1024 << endl;
	cout << "Use mem (B):" << (mem1 - mem0) << endl;
	cout << "time (s): " << c.get_seconds() << endl;
	cout << "time (ms): " << c.get_milliseconds() << endl;
	cout << "time (us): " << c.get_microseconds() << endl;

	return 0;
}
