/*Example*/
#include<iostream>
//입출력을 위해 iostream이라는 헤더파일을 사용할 것임.

using namespace std;
//c++ standard library

int main()
{
	/*
		함수의 일종이며, 시작이다.
		항상 어떤 값을 return을 해야한다.
		또한 함수의 scope를 설정해야 한다.
	*/

	// variable은 어떤 상자.
	// 각각의 type은 다른 size를 가진다.
	// 어떤 range이냐에 따라 다른 type을 가진다.

	// short, int, long, long long, float, double, long double
	// long long 8byte double 8byte

	// precison은 얼마나 많은 유효숫자를 표현해줄 수 있는가이고,
	// cout의 경우는 precision=6 6자리만 출력 가능하다.
	// 1byte = 8bit

	cout << 5.0 << '\n';
	cout << 6.7f << '\n';
	cout << 9876543.21 << '\n'; // 9.8765e+06
	cout << endl;

	char a = 65, b = 66, c = 67, myGrade = 'B';
	cout << a; //ASCII Table 65 = A
	cout << b; //ASCII Table 66 = B
	cout << c; //ASCII Table 67 = C
	cout << myGrade << endl;
	cout << endl;

	// sizeof() 함수는, type의 메모리 byte를 출력한다.
	cout << "char type: " << sizeof(char) << endl;
	cout << "int type: " << sizeof(int) << endl;
	cout << "short type: " << sizeof(short) << endl;
	cout << "long type: " << sizeof(long) << endl;
	cout << "long long type: " << sizeof(long long) << endl;
	cout << "float type: " << sizeof(float) << endl;
	cout << "double type: " << sizeof(double) << endl;
	cout << endl;

	// 'auto' type은 명시하지 않아도 컴파일러에서 정해줌
	int i = 20;
	//auto a = i;
	//auto b = 10.5;

	// String literals
	// 알 필요 없고, 아스키코드만 알면 됨

	auto s0 = "hello"; // const char*
	auto s1 = u8"hello"; // const char*, encoded as UTF-8
	auto s2 = L"hello"; // const wchar_t*
	auto s3 = u"hello"; // const char16_t*, encoded as UTF-16
	auto s4 = U"hello"; // const char32_t*, encoded as UTF-32
	cout << "s0 : " << s0 << endl;
	cout << "s1 : " << s1 << endl;
	cout << "s2 : " << s2 << endl;
	wcout << "s2 : " << s2 << endl;
	cout << "s3 : " << s3 << endl;
	cout << "s4 : " << s4 << endl;
	cout << endl;

	int inum1 = 10.5;
	int inum2(10.5);
	int inum3{ 20 }; // 이 경우 improper conversion 방지, 에러 발생시킴
	// int inum3{ 20.5 }; - error

	//중요!!!
	//Implicit Type Conversion - 내부적으로 바뀜
	int x = 10;
	char y = 'a';
	x = x + y; //오류일까???
	//y는 아스키코드에 따라 int로 바뀜. 'a' = 97
	float z = x + 1.0;
	//x는 float로 바뀜.
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "z = " << z << endl;
	cout << endl;

	//Explicit Type Conversion
	//syntax : (type)expression
	double x1 = 1.2;
	int sum = (int)x1 + 1;
	cout << "Sum = " << sum << endl;
	cout << endl;

	//costant 상수
	const double gravity{ 9.8 };
	// gravity = 10; - error
	//right side 변화 없음.

	//Bitwise Operator - 이진수 이동.
	//넘어가면 0됨.
	int iVal = 4;
	cout << iVal << (iVal >> 3) << endl;
	cout << endl;

	// 질문!!!!!!!!!!!!!!!
	int x2 = 1, y2 = 2;
	cout << (++x2 > 2 && ++y2 > 2) << endl; // 0
	cout << "x=" << x2 << ", y=" << y2 << endl; //2 2
	cout << (++x2 > 2 || ++y2 > 2) << endl; // 1
	cout << "x=" << x2 << ", y=" << y2 << endl; //3 2

	int x3 = 1, y3 = 2;
	cout << (++x3 > 2 & ++y3 > 2) << endl; // 0
	cout << "x=" << x3 << ", y=" << y3 << endl; //2 3
	cout << (++x3 > 2 | ++y3 > 2) << endl; // 1
	cout << "x=" << x3 << ", y=" << y3 << endl; //3 4

	return 0;
	
}