# Awesome Data Structure (List)

Like to use Python in C++

-----------------------------

## How to use?

### List

#### Initlize

```C++
#include "list.hpp"
// List<typename> list;
List<int> list;
```

#### Assign data

```C++
list << 1 << 2 << 3 << 4;
// [1, 2, 3, 4]
list << 1;
// [1, 2, 3, 4, 1]
list.append_back(1);
// [1, 2, 3, 4, 1, 1]
list.append_front(1);
// [1, 1, 2, 3, 4, 1, 1]
```

#### Print list on screen

```C++
cout << list;
// [1, 1, 2, 3, 4, 1, 1]
```

#### Size

```C++
cout << list.size();
// 7
```

#### Some operation for list

```C++
list.in(ListItem<int>(3)); // First equal item and return boolean
// 1
list.get(3);
// 3
list[3]; // equal to get
// 3
list.pop(0); // remove by index and return data
// 1
// [1, 2, 3, 4, 1, 1]
list.pop(ListItem<int>(1)); // First matched item
// [2, 3, 4, 1, 1]
list.sort(1); // Sort data sort(true) for DESC and false for ASC (default=false)
// [4, 3, 2, 1, 1]
list.clean();
// []
```

#### operator for list

```C++
list << 1 << 2 << 3 << 4 << 5 << 6 << 7;
// [1, 2, 3, 4, 5, 6, 7]
list >> 7; // Will remove Item(7)
// [1, 2, 3, 4, 5, 6]
list == 3; // available ==, !=, >, >=, <, <=
// [0, 0, 0, 1, 0, 0]
list > 1; // and output List<bool>
// [0, 1, 1, 1, 1, 1]
list[list > 1]; // so you can use it like python
// [2, 3, 4, 5, 6]
List<int> sel = list[list > 1];
cout << sel; // but you can't direct output
// [2, 3, 4, 5, 6]
list + sel; // universe
// [1, 2, 3, 4, 5, 6, 2, 3, 4, 5, 6]
list += sel; // It will faster than `list = list + sel`
// [1, 2, 3, 4, 5, 6, 2, 3, 4, 5, 6]
list - sel;
// [1]
list -= sel;
// [1]
list | sel; // union
// [1, 2, 3, 4, 5, 6]
list & sel; // and
// []
list + 2; // number calcuation (avaiable + - * /)
// [3]
list += 2; // same
// [3]
```

[Warrning] Use operator may use much memory.

Because C++ no garbage collection
