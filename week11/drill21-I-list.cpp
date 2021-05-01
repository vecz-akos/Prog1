#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>

// solved with list

using namespace std;

struct Item {
	string name;
	int iid;
	double value;

	Item(string c_name = "", int c_iid = -1, double c_value = 0):
		name(c_name),
		iid(c_iid),
		value(c_value)
		{};
};

istream& operator>>(istream& is, Item& item) {
	string nam;
	int id = 0;
	double val = 0.0;
	is >> nam >> id >> val;
	if (!is) return is;
	item = Item(nam, id, val);
	return is;
};

ostream& operator<<(ostream& os, const Item& item) {
	return os << item.name << '\t' << item.iid << '\t' << item.value;
};

struct sortByName {
	bool operator()(Item a, Item b) {
		return a.name < b.name;
	}
};

struct sortByIid {
	bool operator()(Item a, Item b) {
		return a.iid < b.iid;
	}
};

struct sortByValue {
	bool operator()(Item a, Item b) {
		return a.value > b.value;
	}
};

void removeFromListByName(const string& name, list<Item>& itemList) {
	auto removeByName = [name](const Item& item) ->bool {
		return name == item.name;
	};

	itemList.remove_if(removeByName);
};

void removeFromListByIid(const int& iid, list<Item>& itemList) {
	auto removeByIid = [iid](const Item& item) ->bool {
		return iid == item.iid;
	};

	itemList.remove_if(removeByIid);
};

int main() {

	// 1

	ifstream itemReader("input.txt");

	list<Item> itemList;

	Item input;
	itemReader >> input;

	while (itemReader) {
		itemList.push_back(input);
		itemReader >> input;
	}

	cout << "Input data:\n";
	for (const auto i : itemList)
		cout << i << endl;

	// 2

	cout << "\nSort by name:\n";
	itemList.sort(sortByName());

	for (const auto i : itemList)
		cout << i << endl;

	// 3

	cout << "\nSort by iid:\n";
	itemList.sort(sortByIid());

	for (const auto i : itemList)
		cout << i << endl;

	// 4

	cout << "\nSort by value:\n";
	itemList.sort(sortByValue());

	for (const auto i : itemList)
		cout << i << endl;

	// 5

	cout << "\nInsert two items:\n";
	itemList.push_back(Item("horse shoe", 99, 12.34));
	itemList.push_back(Item("Canon S400", 9988, 499.95));

	for (const auto i : itemList)
		cout << i << endl;

	// 6

	cout << "\nRemove two items by name:\n";
	removeFromListByName("orokmozgo", itemList);
	removeFromListByName("napelemes_zseblampa", itemList);

	for (const auto i : itemList)
		cout << i << endl;

	// 7

	cout << "\nRemove two items by iid:\n";
	removeFromListByIid(3, itemList);
	removeFromListByIid(4, itemList);

	for (const auto i : itemList)
		cout << i << endl;

	return 0;
}