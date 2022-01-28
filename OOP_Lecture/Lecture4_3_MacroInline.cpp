//Macro and Inline Function은 메모리를 따로 할당하지 않는다.
//stack의 매크로를 잡아먹지 않는다.

#include <iostream>
using namespace std;

#define PI 3.14
#define Multi(x, y) x * y

inline int Multifly(int, int = 1);

int main()
{
	int a = Multi(3, 2);
	cout << a << endl;

	return 0;
}

int Multiply(int iNum1, int iNum2) {
	return iNum1 * iNum2;
}