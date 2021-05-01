#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

// solved with vector

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

void removeFromVecByName(const string& name, vector<Item>& vi) {
	auto removeByName = [name](const Item& item) ->bool {
		return name == item.name;
	};

	vi.erase(remove_if(vi.begin(), vi.end(), removeByName), vi.end());
};

void removeFromVecByIid(const int& iid, vector<Item>& vi) {
	auto removeByIid = [iid](const Item& item) ->bool {
		return iid == item.iid;
	};

	vi.erase(remove_if(vi.begin(), vi.end(), removeByIid), vi.end());
};

int main() {

	// 1

	ifstream itemReader("input.txt");

	vector<Item> vi;

	Item input;
	itemReader >> input;

	while (itemReader) {
		vi.push_back(input);
		itemReader >> input;
	}

	cout << "Input data:\n";
	for (const Item& a : vi)
		cout << a << endl;

	// 2

	cout << "\nSort by name:\n";
	sort(vi.begin(), vi.end(), sortByName());

	for (const Item& a : vi)
		cout << a << endl;

	// 3

	cout << "\nSort by iid:\n";
	sort(vi.begin(), vi.end(), sortByIid());

	for (const Item& a : vi)
		cout << a << endl;

	// 4

	cout << "\nSort by value:\n";
	sort(vi.begin(), vi.end(), sortByValue());

	for (const Item& a : vi)
		cout << a << endl;

	// 5

	cout << "\nInsert two items:\n";
	vi.push_back(Item("horse shoe", 99, 12.34));
	vi.push_back(Item("Canon S400", 9988, 499.95));

	for (const Item& a : vi)
		cout << a << endl;

	// 6

	cout << "\nRemove two items by name:\n";
	removeFromVecByName("orokmozgo", vi);
	removeFromVecByName("napelemes_zseblampa", vi);

	for (const Item& a : vi)
		cout << a << endl;

	// 7

	cout << "\nRemove two items by iid:\n";
	removeFromVecByIid(3, vi);
	removeFromVecByIid(4, vi);

	for (const Item& a : vi)
		cout << a << endl;


	return 0;
}