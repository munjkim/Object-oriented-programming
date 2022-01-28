#include<iostream>
using namespace std;


//기존에 구현되어 있는 operator들을 overloading해보자.
/*
예를 들어, +를 다른 의미로 사용하고 싶다.
Student s1, s2; s1+s2의 의미를 부여하고 싶은 것이다.
*/

//syntax
//@에 우리가 원하는 operator를 넣는 것이다.
/*
ex1 binary operator
	a.operator+(b)
	operator+(a, b)
ex2 postfix operator
	a.operator++(int) -> 무조건 int를 입력한다.
	operator++(a, int)
ex3 prefix operator
	a.operator++()
	operator++(a)
*/

//class Complex에 대한 + operator을 overloading할 것이다.
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

	//operator overloading +
	Complex operator+(const Complex& c2);
	//다른 type을 더해보기
	Complex operator+(int r);
	Complex operator+(double r);
	//double + Complex의 경우, double이 앞에 존재할 땐 friend를 이용해 global하게 접근한다.
	friend Complex operator+(double r, const Complex& c);

	//postfix의 경우
	Complex operator++(int dummy);
	//prefix의 경우
	Complex& operator++();
};
Complex::Complex(int r, int i) {
	m_r = new int(r);
	m_i = new int(i);
}
Complex::~Complex() {
	if (!m_r) delete m_r;
	if (!m_i) delete m_i;
	m_r = m_i = nullptr;
}
Complex::Complex() : Complex(0, 0) { }
Complex::Complex(int r)
	: m_r{ new int(r) }, m_i{ new int(0) } { }
Complex::Complex(const Complex& rhs) : Complex(*rhs.m_r,
	*rhs.m_i) { }
void Complex::print() const {
	cout << *m_r << (*m_i < 0 ? "" : "+") << *m_i << "j" << endl;
}

//operator overloading implementation
Complex Complex::operator+(const Complex& c2) {
	Complex result;
	*(result.m_r) = *(m_r)+*(c2.m_r);
	*(result.m_i) = *(m_i)+*(c2.m_i);
	return result;
}
Complex Complex::operator+(int r) {
	Complex result;
	*(result.m_r) = *(m_r)+r;
	*(result.m_i) = *(m_i);
	return result;
}
Complex Complex::operator+(double r) {
	//그대로 출력해볼 것이다.
	return Complex(((int)r) + *(m_r), *(m_i));
}
//'complex::'표현이 없음을 주의!!
Complex operator+(double r, const Complex& c) {
	Complex result((int)r + *(c.m_r), *c.m_i);
	return result;
}

//prefix의 경우
Complex& Complex::operator++() {
	(*m_r)++;
	return *this;
}
//postfix의 경우
Complex Complex::operator++(int dummy) {
	Complex ret(*this);
	(*m_r)++;
	return ret;
}
int main()
{
	Complex c1;
	Complex c2(34, 65);
	Complex c3(-3, 1);
	Complex c4;

	c1.print();
	c1 = c2 + c3;
	c1.print();

	c1 = c1 + 5.35;
	c1.print();

	c4 = 1.24 + c1;
	c4.print();

	Complex temp1;
	temp1 = ++c4;
	temp1.print();
	c4.print();

	Complex temp2;
	temp2 = c4++;
	temp2.print();
	c4.print();
	return 0;
} 