#include <iostream>

#define array_traverse(arr) \
		_array_traverse(arr, sizeof arr / sizeof *arr)
#define array_insert(arr, pos, value) \
		_array_insert(arr, pos, value, sizeof arr / sizeof *arr)
#define array_delete(arr, pos) \
		_array_delete(arr, pos, sizeof arr / sizeof *arr)
#define array_inverse(arr) \
		_array_inverse(arr, sizeof arr / sizeof *arr)

template <typename T>
void _array_traverse(T* a, size_t size) {
	std::cout << std::endl;
	for (size_t i=0; i<size; ++i) std::cout << *(a+i) << '\t';
	std::cout << std::endl;
}

template <typename T>
void _array_insert(T* a, size_t pos, T value, size_t size) {
	for (size_t i=size-1; i>pos; --i) *(a+i) = *(a+i-1);
	*(a+pos) = value;
}

template <typename T>
void _array_delete(T* a, size_t pos, size_t size) {
	for (size_t i=pos; i<size-1; ++i) *(a+i) = *(a+i+1);
	*(a+size-1) = 0x0;
}

template <typename T>
void _array_inverse(T* a, size_t size) {
	T temp;
	for (size_t i=size; i>size/2; --i) {
		temp = *(a+i-1);
		*(a+i-1) = *(a+(size-i));
		*(a+(size-i)) = temp;
	}
}

int main() {
	char a[] = {
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'
	};
	array_traverse(a);
	array_insert(a, 3, 'G');
	array_traverse(a);
	array_delete(a, 3);
	array_traverse(a);
	array_inverse(a);
	array_traverse(a);
	std::cout << std::endl;
	return 0;
}