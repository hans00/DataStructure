#include <platformstl/performance/performance_counter.hpp>
#include <sys/resource.h>
#include <iostream>
#include "../list.hpp"
#include "memory.hpp"

using namespace std;

typedef void(*ReportFunc)();

struct Mem_Data
{
	Mem_Data(int m,string u): mem(m), unit(u) {};
	unsigned int mem;
	string unit;
};

Mem_Data parse_mem(long mem) {
	if (mem >= 1024*1024*1024)
		return Mem_Data(mem/1024/1024/1024, "GB");
	else if (mem >= 1024*1024)
		return Mem_Data(mem/1024/1024, "MB");
	else if (mem >= 1024)
		return Mem_Data(mem/1024, "KB");
	else
		return Mem_Data(mem, "B");
}

void report(ReportFunc func, size_t run) {
	static platformstl::performance_counter c;
	long mem0, mem1;
	mem0 = getPeakRSS();
	Mem_Data mem0_p = parse_mem(mem0);
	cout << "Mem before (" << mem0_p.unit << "):" << mem0_p.mem << endl;
	c.start();
	while (run--) func();
	c.stop();
	mem1 = getPeakRSS();
	Mem_Data mem1_p = parse_mem(mem1);
	cout << "Mem after (" << mem1_p.unit << "):" << mem1_p.mem << endl;
	Mem_Data memd_p = parse_mem(mem1 - mem0);
	cout << "Use mem (" << memd_p.unit << "):" << memd_p.mem << endl;
	cout << "time (s): " << c.get_seconds() << endl;
	cout << "time (ms): " << c.get_milliseconds() << endl;
	cout << "time (us): " << c.get_microseconds() << endl;
}

List<size_t> list;

int main(int argc, char const *argv[])
{
	long mem0, mem1;
	platformstl::performance_counter c;
	size_t counter = 0;

	cout << endl << "Initlize (do 1000000 times)." << endl;

	report( [] () {
		delete new List<size_t>();
	}, 1000000);

	cout << endl << "==========================" << endl << endl;

	cout << "Clean and insert 1000000 items (do 100 times)" << endl;
	
	report( [] () {
		list.clean();
		for (size_t i = 0; i < 1000000; ++i) {
			list << i;
		}
	}, 100);

	cout << endl << "==========================" << endl << endl;

	cout << "list *= 2 (do 100 times)" << endl;
	
	report( [] () {
		list *= 2;
	}, 100);

	cout << endl << "==========================" << endl << endl;

	cout << "list <= 1000000/2 (do 100 times)" << endl;

	report( [] () {
		list <= 1000000/2;
	}, 100);

	cout << endl << "==========================" << endl << endl;

	cout << "list[list <= 1000000/2] (do 100 times)" << endl;

	report( [] () {
		list[list <= 1000000/2];
	}, 100);

	cout << endl << "==========================" << endl << endl;

	cout << "list(1,0,2) same list[1:][::2] in py (do 100 times)" << endl;

	report( [] () {
		list(1,0,2);
	}, 100);

	cout << endl << "==========================" << endl << endl;

	cout << "list.sort(counter % 2) (do 100 times)" << endl;

	report( [] () {
		static bool x = 0;
		x = !x;
		list.sort(x);
	}, 100);

	cout << endl << "==========================" << endl << endl;

	cout << "list.in(ListItem<size_t>(counter)) (do 100 times)" << endl;
	mem0 = getPeakRSS();
	cout << "Mem before (MB):" << mem0/1024/1024 << endl;

	report( [] () {
		static size_t x = 0;
		list.in(ListItem<size_t>(x++));
	}, 100);

	return 0;
}
