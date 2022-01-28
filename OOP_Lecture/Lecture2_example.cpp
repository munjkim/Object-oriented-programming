#include <iostream>
#define PI 3.14
using namespace std;
int main()
{
	int iValue(2);
	double circum{ 0 };
	for (;;) {
		cout << "Enter the radius? ";
		cin >> iValue;
		if (iValue == 0)
			break; circum = iValue * 2 * PI;
		cout << "circumference with a radius of " << iValue << " : ";
		cout << circum << "(" << typeid(circum).name() << ")" << endl;
	}
	return 0;
}