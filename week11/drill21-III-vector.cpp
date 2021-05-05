#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>

using namespace std;

void pushFromDoubleToIntVector(vector<double>& from, vector<int>& to) {
	for (long unsigned int i = 0; i < from.size(); ++i)
		to.push_back((int)from[i]);
};

class LowerThan {
	double large;
public:
	LowerThan(double ll): large(ll) {};
	bool operator()(double val) {
		return val < large;
	}
};

int main() {

	// 1

	vector<double> vd;

	ifstream inputReader("double_input.txt");

	double input = 0;

	inputReader >> input;

	while(inputReader) {
		vd.push_back(input);
		inputReader >> input;
	}

	// 2

	for (const double& i : vd)
		cout << i << endl;

	cout << endl;

	// 3

	vector<int> vi;

	pushFromDoubleToIntVector(vd, vi);

	// 4

	cout << "vd\tvi\n"
		 << "--\t--\n";

	for (long unsigned int i = 0; i < vd.size(); ++i)
		cout << vd[i] << '\t' << vi[i] << endl;
	cout << endl;

	// 5

	cout << "Sum of vd:\t"
		 << accumulate(vd.begin(), vd.end(), 0.0)
		 << endl;

	// 6

	cout << "Sum diffenence between vd and vi:\t"
		 << abs(
		 		  accumulate(vd.begin(), vd.end(), 0.0)
		 		- accumulate(vi.begin(), vi.end(), 0.0)
		 	)
		 << endl;

	// 7

	cout << "\nReverse vd:\n";

	reverse(vd.begin(), vd.end());

	for (const double& i : vd)
		cout << i << endl;

	cout << endl;

	// 8

	double avg = accumulate(vd.begin(), vd.end(), 0.0) / (vd.size() + 1);

	cout << "Average of vd:\t" << avg << endl;

	// 9

	vector<double> vd2(vd.size() + 1);

	copy_if(vd.begin(), vd.end(), vd2.begin(), LowerThan(avg));

	// 10

	cout << "\nSorted vd:\n";

	sort(vd.begin(), vd.end());

	for (const double& i : vd)
		cout << i << endl;

	return 0;
}