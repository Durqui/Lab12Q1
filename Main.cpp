#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	double key;

	double vals[] = { 2.4,1.3,2.4,4.5,6.7,4.5,9.0 };
	vector<double> v(vals, vals + 7);

	ostream_iterator<double> out(cout, " ");
	cout << "values: ";
	copy(vals, vals + 7, out);
	cout << "doubleVector: " << endl;
	copy(v.begin(), v.end(), out);

	cout << endl << "Enter key value: ";
	cin >> key;
	cout << "Find " << key << " in vector " << endl;

	double* pt = find(vals, vals + 7, key);

	if (pt != vals + 7) {
		cout << "Found at position " << (pt - vals + 1) << endl;
	}
	else {
		cout << "Not found" << endl;
	}

	auto iter = find_if(v.begin(), v.end(), [](double x) {
		return (x < 2);
	});

	if (iter != v.end()) {
		cout << "Element less than 2 at positon " << (iter - v.begin() + 1) << endl;
	}
	else {
		cout << "No element less than 2 found " << endl;
	}

	vector<double> sequence{ 2.4,4.5 };
	auto iter_end = find_end(v.begin(), v.end(), sequence.begin(), sequence.end());

	if (iter_end != v.end()) {
		cout << "Sequence found at position " << (iter_end - v.begin() + 1) << endl;
	}
	else {
		cout << "Sequence not found" << endl;
	}

	vector<double> list{ 34, 55, 2.4, 4.5 };
	auto iter_first_of = find_first_of(v.begin(), v.end(), list.begin(), list.end());

	if (iter_first_of != v.end()) {
		cout << "First common element of list found at position " << (iter_first_of - v.begin() + 1) << endl;
	}
	else {
		cout << "No common element found" << endl;
	}

	return 0;
}