#include <iostream>
#include "list.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
	List<int> list, list2;

	list << 10 << 11 << 12 << 13 << 14 << 15 << 16;
	list2 << 11 << 100 << 101 << 102 << 103;

	cout << "Size: " << list.size() << endl;

	cout << list << endl;

	cout << "==================================" << endl;

	cout << "Pop last: " << list.pop_back() << endl;
	cout << "Pop index 2: " << list.pop(2) << endl;
	cout << "Compare with list2: " << ((list == list2) ? "true" : "false") << endl;

	try {
		list >> 14;
		cout << "Pop item 14: Succ" << endl;
	} catch (const std::invalid_argument& e) {
		cout << "Pop item 14: Fail" << endl;
	}

	cout << "Size: " << list.size() << endl;

	cout << "==================================" << endl;

	cout << "universe list2 to list1." << endl;
	list += list2;

	cout << "Size: " << list.size() << endl;

	cout << list << endl;

	cout << "==================================" << endl;

	List<int> tmp = list(1,5,2);
	cout << "tmp = list[1:5][::2]" << endl;

	cout << tmp << endl;

	cout << "union of list2 and tmp" << endl;

	list = tmp | list2;

	cout << list << endl;

	cout << "Intersection list2 with tmp" << endl;

	list = tmp & list2;

	cout << list << endl;

	cout << "==================================" << endl;

	cout << "all gte 50 in list: " << endl;

	List<int> sel = list[list >= 50];
	cout << sel << endl;

	cout << "==================================" << endl;

	cout << "all lte 50 in list: " << endl;

	sel = list[list <= 50];
	cout << sel << endl;

	cout << "==================================" << endl;

	cout << "all eq 11 in list: " << endl;

	sel = list[list == 11];
	cout << sel << endl;
	cout << sel.size() << endl;

	cout << "==================================" << endl;
	cout << "Calculation" << endl;

	cout << list << endl;

	list += 2;

	cout << "list += 2" << endl;

	cout << list << endl;

	list -= 2;

	cout << "list -= 2" << endl;

	cout << list << endl;

	list *= 2;

	cout << "list *= 2" << endl;

	cout << list << endl;

	list /= 2;

	cout << "list /= 2" << endl;

	cout << list << endl;


	cout << "list + 2" << endl;

	List<int> t = list+2;

	cout << t << endl;

	cout << "==================================" << endl;

	cout << "list2 DESC" << endl;

	list2.sort(1);

	cout << list2 << endl;

	cout << "list2 ASC" << endl;

	list2.sort(0);

	cout << list2 << endl;

	cout << "list2[0] = 0" << endl;

	list2[0] = 0;

	cout << list2 << endl;

	cout << "list2.insert(2, 4)" << endl;

	list2.insert(2, 4);

	cout << list2 << endl;

	return 0;
}