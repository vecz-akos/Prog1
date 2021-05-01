#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {

	// 1

	map<string, int> msi;

	// 2
	// source:
	// https://en.wikipedia.org/wiki/List_of_European_cities_by_population_within_city_limits

	msi["Istambul"] = 15462452;
	msi["Moscow"] = 12195221;
	msi["London"] = 9126366;
	msi["Saint Petersburg"] = 5383890;
	msi["Berlin"] = 3748148;
	msi["Madrid"] = 3223334;
	msi["Kyiv"] = 2950800;
	msi["Rome"] = 2844750;
	msi["Bucharest"] = 2155240;
	msi["Paris"] = 2140526;

	// 3

	cout << "Input data in msi:\n";
	for (auto i : msi)
		cout << "Population of " << i.first << " is " << i.second << ".\n";

	// 4

	cout << "\nClear msi\n";
	msi.clear();

	// 5

	auto insertIntoMsi = [&msi]() {
		pair<string, int> input;
		cin >> input.first >> input.second;
		msi.insert(input);
	};

	// 6

	cout <<	"\nInsert new pairs from cin:\n<town>\t<population>\n";
	int cityNum = 10;

	for (int i = 0; i < cityNum; ++i) {
		insertIntoMsi();
	}

	// 7

	cout << endl;

	for (auto i : msi)
		cout << "Population of " << i.first << " is " << i.second << ".\n";

	// 8

	long int sum = 0;

	for (auto i : msi) {
		sum += i.second;
	}

	cout << "\nTotal population: " << sum << endl;

	// 9

	map<int, string> mis;

	// 10

	for (auto i : msi)
		mis.insert(pair<int, string>(i.second, i.first));

	// 11

	cout << "\nData in mis:\n";
	for (auto i : mis)
		cout << "Population of " << i.second << " is " << i.first << ".\n";

	return 0;
}
