#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2) {
	while (f1 != e1) {
		*f2 = *f1;
		++f1;
		++f2;
	}
	return f2;
};

int main() {

	constexpr int size = 10;

	std::array<int, size> arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::list<int> list = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	// 4

	std::array<int, size> arr2 = arr;
	std::vector<int> vec2 = vec;
	std::list<int> list2 = list;

	std::cout << "array\tvector\tlist\n";
	auto listelem = list2.begin();
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr2[i] << '\t' << vec2[i]  << '\t'  << *listelem << std::endl;
		listelem++;
	}
	std::cout << std::endl;

	// 5

	std::iota(arr.begin(), arr.end(), 2);
	std::iota(vec.begin(), vec.end(), 3);
	std::iota(list.begin(), list.end(), 5);

	std::cout << "Increased values:\n";
	std::cout << "array\tvector\tlist\n";
	listelem = list.begin();
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << '\t' << vec[i]  << '\t'  << *listelem << std::endl;
		listelem++;
	}
	std::cout << std::endl;

	// 7

	my_copy(vec2.begin(), vec2.end(), vec.begin());
	my_copy(arr.begin(), arr.end(), vec.begin());
	my_copy(list.begin(), list.end(), arr.begin());

	// 8

	int index3 = distance(vec.begin(), find(vec.begin(), vec.end(), 3));
	std::cout << "Index of 3 in vector:\t";
	std::cout << (index3 == size ? "not found this value" : std::to_string(index3)) << std::endl;

	int index27 = distance(list.begin(), find(list.begin(), list.end(), 27));
	std::cout << "Index of 27 in list:\t";
	std::cout << (index27 == size ? "not found this value" : std::to_string(index27)) << std::endl;
	

	return 0;
}