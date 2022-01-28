#include<iostream>
using namespace std;

//한 객체에서 다른 객체를 사용할 때

//먼저, class 심화과정 
/*
//static은 모든 class에서 공유를 함.
//const는 수정이 불가능한 상황을 의미.
//friend는 private영역의 변수들을 접근하기 위해 사용하는 것. main함수에서 접근하려고
*/

//polymorphism 다형성
/*
동일한 프로그램이지만, type에 따라서 다르게 구현해야 할 때
일일이 다른 프로그램을 만들지 않더라도 polymorphism을 이용하여 구현.

1. function overloading
	sum의 경우 int+int, double+int, char+char의 경우가 가능하다.
	c++에서는, 같은 이름의 함수 내input parameter의 변주는 가능하지만,
	return값이 다를 경우는 overloading을 할 수 없다.
*/

//잠깐, new int(r)을 하면 기본적으로 nullptr을 할당.

//복소수 관련 class함수
class Complex {
	int* m_r = nullptr; // real part
	int* m_i = nullptr; // imaginary part
public:
	Complex();
	Complex(int, int);
	Complex(int);
	~Complex();
	Complex(const Complex& rhs);
	void print() const;
};
Complex::Complex(int r, int i) {
m_r = new int(r);
m_i = new int(i);
}
Complex::~Complex() {
if (!m_r) delete m_r;
if (!m_i) delete m_i;
m_r=m_i=nullptr;
}
Complex::Complex() : Complex(0, 0) { }
Complex::Complex(int r) 
: m_r{ new int(r) }, m_i{ new int(0) } { }
Complex::Complex(const Complex& rhs) : Complex(*rhs.m_r, *rhs.m_i) { }
void Complex::print() const {
cout << *m_r << (*m_i < 0 ? "" : "+") << *m_i << "j" << endl;
}
int main()
{
	Complex c1;
	Complex c2(3);
	Complex c3(-3);
	Complex c4(c2);

	c1 = { 2, 3 };

	c1.print();
}
