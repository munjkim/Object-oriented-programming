#include<iostream>
using namespace std;

//프로그래밍 수행 중에 동적으로 메모리를 할당하는 방법을 알아본다.

//stack은 compile time에 할당 - 함수의 호출
//heap은 run-time에 할당 - 동적으로 할당할 때

int foo()
{
	return 5; 
}
double goo()
{
	return 60.1;
}
int hoo(int n)
{
	return n;
}

int main()
{
	int* ptr;
	ptr = new int; //new를 이용해 할당
	//즉 4byte가 heap에 할당되고, 그 할당된 곳에 123을 저장.
	*ptr = 123;
	cout << "value of *ptr : " << *ptr << endl;
	delete ptr; //delete를 이용해 제거

	/*
	int x;
	int* ptr1 = &x;
	delete ptr1; 
	compile time에는 오류X, runtime에 오류 발생
	*/

	int* ptr2;
	ptr2 = new int[10];
	//ptr2[0] = 0;
	for (int i = 0; i < 10; i++)
		*(ptr2 + i) = i;
	for (int i = 0; i < 10; i++)
		cout << ptr2[i] << " ";
	//delete ptr2;
	delete[] ptr2;
	cout << endl;

	//memory leaking
	//만약 제거하지 않으면, 사용하지 않는 memory를 잡아먹는다.
	//Dangling pointer
	//제거한 후에 포인터를 불러오면, run time 오류가 발생한다.
	int* ptr3 = new int{ 40 };
	delete ptr3;
	// *ptr3 = 10;
	// 즉, 중요한 것은 할당을 했으면 제거를 해야 한다!!!!!!!
	cout << endl;
	//---------pointer 끝--------------
	
	//Reference Type
	//어떤 변수를 선언하면, 다른 별명을 가진 변수를 선언할 수 있다.
	int iNum = 10;
	int& rNum = iNum; //포인터와 비슷한 역할, 그러나 사용법이 다름.
	int* pNum = &iNum;
	cout << "value:" << iNum << " address:" << &iNum << endl;
	cout << "value:" << rNum << " address:" << &rNum << endl;
	cout << "value:" << *pNum << " address:" << pNum << endl;
	cout << endl;

	//Function Pointer - 함수 포인터. 함수의 주소를 가져온다.
	int(*ifcnPtr)() { &foo }; // function pointer to foo
	double(*dfcnPtr)() { &goo };
	int(*pfcnPtr)(int);
	pfcnPtr = &hoo;
	cout << ifcnPtr() << endl;
	cout << dfcnPtr() << endl;
	cout << pfcnPtr(8) << endl;
	//과연 어디에 쓰일까? 시스템에서 이벤트에 대한 루틴을 수행할 때.


	//포인터 변수에는 무조건 주소가 들어가야 한다!! &A
	//const를 사용할 때는, 변수나 포인터 변수나 주의한다.
	//r side가 변하지 않는 const char* s = ('dkd')는 가능
	return 0;
}