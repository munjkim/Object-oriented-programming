//Lecture 4

#include<iostream>
using namespace std;

//함수를 선언한다면, 밑에 써도 무방하다.
double calArea(int = 0); 
//변수 이름 안써도 무방.
//parameter를 미리 선언할 수 있다.

int main() {
	int iVal(0); double dVal{ 0 };
	cout << "Enter the radius? ";
	cin >> iVal;
	dVal = calArea(iVal);
	cout << dVal << endl;
	return 0;
}

double calArea(int radius)
{
	double dVal;
	dVal = radius * radius * 3.14;
	return dVal;
}