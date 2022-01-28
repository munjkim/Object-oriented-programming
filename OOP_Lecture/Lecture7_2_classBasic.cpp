// object는 class의 instance이다
// class는 object를 표현하는 type이다.
#include<iostream>
#include<string.h>
using namespace std;

// class의 public - 외부에서 접근 가능한 정보.
// class의 privat - 내부적으로 기능하는 것.

class student {
private:
	string m_name;
	int* m_id; //여기 순서는 상관없다.

//constructor는 초기 선언을 위해!!!
public:
	student(); //constructor1 - self같은 느낌!
	student(int, string); //constructor2
	int get_id() { return *m_id; };
	string get_name();
	~student(); //destructor - 무조건 1개이다.
};
//선언한다. 아무 입력이 없을 때
student::student() {
	m_id = new int(201811020);
	m_name = "ABC";
	cout << "Constructor test1" << endl;
}
//선언한다. id와 name이 입력될 때
student::student(int id, string name) {
	m_id = new int(id);
	m_name = name;
	cout << "Constructor test2" << endl;
}
string student::get_name()
{
	return m_name;
}
student::~student() {
	delete m_id;
	cout << "Destructor called" << endl;
}

int main()
{
	student s1 = { 123, "Nonamed" };
	student* s2 = new student{ 201811020, "ABC" };
	cout << s1.get_id() << endl;
	cout << (*s2).get_id() << endl;
	cout << s1.get_name() << endl;
	delete s2;
	return 0;
}
