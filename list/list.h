#include <iostream>
#include <stdexcept>

template<typename T>
struct ListItem {
	ListItem() : prev(nullptr), next(nullptr) {}
	ListItem(T d) : data(d), prev(nullptr), next(nullptr) {}
	ListItem<T>* prev;
	T data;
	ListItem<T>* next;
	bool operator==(ListItem<T> rhs) const { return data == rhs.data; }
	bool operator!=(ListItem<T> rhs) const { return data != rhs.data; }
};

template<typename T>
class List
{
public:

	List() {
		cursor_item = first = last = nullptr;
		cursor = 0;
		count = 0;
	}

	void clean() {
		while (count) {
			pop_back();
		}
	}

	void append_back(T data) {
		if (count == 0) {
			first = last = new ListItem<T>;
			first->data = data;
		} else {
			last->next = new ListItem<T>;
			last->next->prev = last;
			last = last->next;
			last->data = data;
		}
		count++;
	}

	void append_front(T data) {
		if (count == 0) {
			first = last = new ListItem<T>;
			first->data = data;
		} else {
			first->prev = new ListItem<T>;
			first->prev->next = first;
			first = first->prev;
			first->data = data;
		}
		count++;
	}

	T pop_back() {
		if (count == 0) {
			throw std::invalid_argument( "Zero size." );
		}
		T tmp = last->data;
		last = last->prev;
		delete last->next;
		last->next = nullptr;
		count--;
		return tmp;
	}

	T pop(size_t index) {
		if (count == 0 || index >= count) {
			throw std::invalid_argument( "Out of index. (pop)" );
		}
		T tmp = get(index);
		if (cursor_item->prev != nullptr) cursor_item->prev->next = cursor_item->next;
		if (cursor_item->next != nullptr) cursor_item->next->prev = cursor_item->prev;
		cursor = 0;
		delete cursor_item;
		cursor_item = nullptr;
		count--;
		return tmp;
	}

	void pop(ListItem<T> item) {
		cursor = 0;
		cursor_item = first;
		while (cursor++ < count) {
			if (cursor_item->data == item.data) {
				if (cursor_item->prev != nullptr) cursor_item->prev->next = cursor_item->next;
				if (cursor_item->next != nullptr) cursor_item->next->prev = cursor_item->prev;
				cursor = 0;
				delete cursor_item;
				cursor_item = nullptr;
				count--;
				return;
			}
			cursor_item = cursor_item->next;
		}
		throw std::invalid_argument( "Not found." );
	}

	T get(size_t index) {
		if (count == 0 || index >= count) {
			throw std::invalid_argument( "Out of index. (get)" );
		}
		if (cursor > count || cursor_item == nullptr) {
			if (index >= count/2) {
				cursor = count-1;
				cursor_item = last;
			} else {
				cursor = 0;
				cursor_item = first;
			}
		}
		if (index > cursor) {
			for (size_t i=cursor; i < index; i++) {
				cursor_item = cursor_item->next;
			}
		} else if (index < cursor) {
			for (size_t i=cursor; i > index; i--) {
				cursor_item = cursor_item->prev;
			}
		}
		cursor = index;
		return cursor_item->data;
	}

	bool in(ListItem<T> item) {
		cursor = 0;
		cursor_item = first;
		while (cursor++ < count) {
			if (cursor_item->data == item.data) {
				return true;
			}
			cursor_item = cursor_item->next;
		}
		return false;
	}

	void sort(bool desc=false) {
		bool inv = 0;
		size_t limit = 0;
		ListItem<T>* comp;
		T tmp;
		cursor = 0;
		cursor_item = first;
		T lmax = cursor_item->data,
		max = cursor_item->data;
		T lmin = cursor_item->data,
		min = cursor_item->data;
		for (;;) {
			if (!inv) {
				cursor += 1;
				if (cursor < count - limit){
					cursor_item = cursor_item->next;
				} else {
					cursor -= 2;
					cursor_item = cursor_item->prev;
					inv = 1;
					if (desc && (lmin < min || lmax < max)) {
						limit++;
						min = max = cursor_item->data;
					} else if (lmin > min || lmax > max) {
						limit++;
						min = max = cursor_item->data;
					}
					lmin = min;
					lmax = max;
				}
			} else {
				cursor -= 1;
				if (cursor > limit) {
					cursor_item = cursor_item->prev;
				} else {
					cursor += 2;
					cursor_item = cursor_item->next;
					inv = 0;
					if (desc && (lmin < min || lmax < max)) {
						limit++;
						min = max = cursor_item->data;
					} else if (lmin > min || lmax > max) {
						limit++;
						min = max = cursor_item->data;
					}
					lmin = min;
					lmax = max;
				}
			}
			comp = cursor_item->prev;
			if (comp->data > max) max = comp->data;
			if (comp->data < min) min = comp->data;
			if (desc && cursor_item->data > comp->data) {
				tmp = cursor_item->data;
				cursor_item->data = comp->data;
				comp->data = tmp;
			} else if (!desc && cursor_item->data < comp->data) {
				tmp = cursor_item->data;
				cursor_item->data = comp->data;
				comp->data = tmp;
			}
			if (count/2 == limit) break;
		}
	}

	size_t size() {
		return this->count;
	}

	const T operator[] (size_t n) {
		return get(n);
	}

	List<T> operator[] (List<bool> blist) {
		List<T> tmp;
		cursor = 0;
		cursor_item = first;
		for (size_t i=0; i < count; i++) {
			if (blist[i]) {
				tmp.append_back(cursor_item->data);
			}
			cursor_item = cursor_item->next;
		}
		cursor_item = nullptr;
		return tmp;
	}

	List<T>& operator<< (T d) {
		append_back(d);
		return *this;
	}

	List<T>& operator>> (T d) {
		pop(ListItem<T>(d));
		return *this;
	}

	// number calculation
	List<T> operator+ (T n) {
		List<T> tmp;
		for (size_t i=0; i < count; i++) {
			tmp.append_back(get(i) + n);
		}
		return tmp;
	}

	void operator+= (T n) {
		cursor = 0;
		cursor_item = first;
		for (size_t i=0; i < count; i++) {
			cursor_item->data += n;
			cursor_item = cursor_item->next;
		}
		cursor_item = nullptr;
	}

	List<T> operator- (T n) {
		List<T> tmp;
		for (size_t i=0; i < count; i++) {
			tmp.append_back(get(i) - n);
		}
		return tmp;
	}

	void operator-= (T n) {
		cursor = 0;
		cursor_item = first;
		for (size_t i=0; i < count; i++) {
			cursor_item->data -= n;
			cursor_item = cursor_item->next;
		}
		cursor_item = nullptr;
	}

	List<T> operator* (T n) {
		List<T> tmp;
		for (size_t i=0; i < count; i++) {
			tmp.append_back(get(i) * n);
		}
		return tmp;
	}

	void operator*= (T n) {
		cursor = 0;
		cursor_item = first;
		for (size_t i=0; i < count; i++) {
			cursor_item->data *= n;
			cursor_item = cursor_item->next;
		}
		cursor_item = nullptr;
	}

	List<T> operator/ (T n) {
		List<T> tmp;
		for (size_t i=0; i < count; i++) {
			tmp.append_back(get(i) / n);
		}
		return tmp;
	}

	void operator/= (T n) {
		cursor = 0;
		cursor_item = first;
		for (size_t i=0; i < count; i++) {
			cursor_item->data /= n;
			cursor_item = cursor_item->next;
		}
		cursor_item = nullptr;
	}

	// remove same
	List<T> operator- (List<T>& another) {
		List<T> tmp;
		for (size_t i=0; i < count; i++) {
			tmp.append_back(get(i));
		}
		for (size_t i=0; i < another.size(); i++) {
			if ( tmp.in( ListItem<T>(another.get(i)) ) ) {
				tmp.pop(ListItem<T>(another.get(i)));
			}
		}
		return tmp;
	}

	// remove same to this
	void operator-= (List<T>& another) {
		for (size_t i=0; i < another.size(); i++) {
			if ( in( ListItem<T>(another.get(i)) ) )
				pop(ListItem<T>(another.get(i)));
		}
	}

	// universe
	List<T> operator+ (List<T>& another) {
		List<T> tmp;
		for (size_t i=0; i < count; i++) {
			tmp.append_back(get(i));
		}
		for (size_t i=0; i < another.size(); i++) {
			tmp.append_back(another.get(i));
		}
		return tmp;
	}

	// universe to this
	void operator+= (List<T>& another) {
		for (size_t i=0; i < another.size(); i++) {
			append_back(another[i]);
		}
	}

	// union
	List<T> operator| (List<T>& another) {
		List<T> tmp;
		for (size_t i=0; i < count; i++) {
			tmp.append_back(get(i));
		}
		for (size_t i=0; i < another.size(); i++) {
			if (!in( ListItem<T>(another.get(i)) ))
				tmp.append_front(another.get(i));
		}
		return tmp;
	}

	// and
	List<T> operator& (List<T>& another) {
		List<T> tmp;
		for (size_t i=0; i < count; i++) {
			if (another.in( ListItem<T>(get(i)) ))
				tmp.append_back(get(i));
		}
		return tmp;
	}

	// split
	List<T> operator() (size_t start=0, size_t size=0, size_t d=1) {
		if (size == 0) size = this->count;
		List<T> list;
		for (int i = start; i < start+size; i+=d)
		{
			list.append_back(get(i));
		}
		return list;
	}

	// compare list
	bool operator== (List<T> comp) {
		if (count != comp.size()) return false;
		cursor = 0;
		cursor_item = first;
		for (size_t i=0; i < count; i++) {
			if (cursor_item->data != comp[i]) return false;
			cursor_item = cursor_item->next;
		}
		cursor_item = nullptr;
		return true;
	}

	// compare item
	List<bool> operator== (T comp) {
		List<bool> list;
		cursor = 0;
		cursor_item = first;
		for (size_t i=0; i < count; i++) {
			if (cursor_item->data == comp) {
				list.append_back(true);
			} else {
				list.append_back(false);
			}
			cursor_item = cursor_item->next;
		}
		cursor_item = nullptr;
		return list;
	}

	// compare item
	List<bool> operator!= (T comp) {
		List<bool> list;
		cursor = 0;
		cursor_item = first;
		for (size_t i=0; i < count; i++) {
			if (cursor_item->data != comp) {
				list.append_back(true);
			} else {
				list.append_back(false);
			}
			cursor_item = cursor_item->next;
		}
		cursor_item = nullptr;
		return list;
	}

	// compare item
	List<bool> operator< (T comp) {
		List<bool> list;
		cursor = 0;
		cursor_item = first;
		for (size_t i=0; i < count; i++) {
			if (cursor_item->data < comp) {
				list.append_back(true);
			} else {
				list.append_back(false);
			}
			cursor_item = cursor_item->next;
		}
		cursor_item = nullptr;
		return list;
	}

	// compare item
	List<bool> operator<= (T comp) {
		List<bool> list;
		cursor = 0;
		cursor_item = first;
		for (size_t i=0; i < count; i++) {
			if (cursor_item->data <= comp) {
				list.append_back(true);
			} else {
				list.append_back(false);
			}
			cursor_item = cursor_item->next;
		}
		cursor_item = nullptr;
		return list;
	}

	// compare item
	List<bool> operator> (T comp) {
		List<bool> list;
		cursor = 0;
		cursor_item = first;
		for (size_t i=0; i < count; i++) {
			if (cursor_item->data > comp) {
				list.append_back(true);
			} else {
				list.append_back(false);
			}
			cursor_item = cursor_item->next;
		}
		cursor_item = nullptr;
		return list;
	}

	// compare item
	List<bool> operator>= (T comp) {
		List<bool> list;
		cursor = 0;
		cursor_item = first;
		for (size_t i=0; i < count; i++) {
			if (cursor_item->data >= comp) {
				list.append_back(true);
			} else {
				list.append_back(false);
			}
			cursor_item = cursor_item->next;
		}
		cursor_item = nullptr;
		return list;
	}

	friend std::ostream& operator<< (std::ostream& os, List<T>& list) {
		size_t size = list.size();
		os << "[";
		for (int i=0; i<size; i++) {
			os << list[i];
			if (i != size-1) {
				os << ", ";
			}
		}
		return os << "]";
	}

protected:

	ListItem<T>* first;
	ListItem<T>* last;
	ListItem<T>* cursor_item;
	size_t cursor;
	size_t count;
};