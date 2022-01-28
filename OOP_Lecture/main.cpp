#include <iostream>
#include"Student.h"
#include"Teacher.h"
#include"Lecture.h"
using namespace std;
int main() {
	student s1(201911999, "Alice");
	teacher t1(111111111, "Tom");
	lecture l1(222222222, "OOP");
	cout << s1.getname() << endl;
	cout << t1.GetName() << endl;
	cout << l1.getName() << endl;
	return 0;
}