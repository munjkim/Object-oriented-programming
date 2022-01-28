#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	cout << "At 0: " << v1.at(0) << "\tAt 1: " << v1.at(1) << endl;
	cout << "Front" << v1.front() << "\tBack" << v1.back() << endl;
	vector<int> v2(v1);
	v1.push_back(3);
	v1.push_back(4);

	for (int& a : v1) {
		cout << a << " ";
	}
	cout << endl;

	cout << "V1 capacity " << v1.capacity() << "\tV1 Size : " << v1.size() << endl;

	v1.pop_back();
	cout << "V1 capacity " << v1.capacity() << "\tV1 Size : " << v1.size() << endl;
}