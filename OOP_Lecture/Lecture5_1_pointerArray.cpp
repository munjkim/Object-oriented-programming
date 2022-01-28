//메모리 영역에 직접 접근할 것이다.
//데이터와 변수는 각각의 주소(adress)를 가진다.

//variable 변수는 데이터를 저장하는 박스
//pointer 포인터는 변수인데, 메모리 주소를 저장하는 박스이다.

#include<iostream>
using namespace std;

int main()
{
	//&는 변수의 '주소'를 가져옴
	//*은 그 주소의 '값'을 가져옴
	int studentID = 201811020;
	cout << "adress of ID : " << &studentID << endl;
	cout << "value at " << &studentID << " : " << *(&studentID) << endl;
	cout << endl;

	//포인터는 주소를 저장하는 '변수'이다.
	//!!!!!!!!!!null pointer 선언!!!!!!!!!!!!!!!!! nullptr
	char* name{ 0 }; //char타입의 주소를 가르키는 포인터 변수이며, null상태이다.
	//null pointer를  출력하면 error
	int iNum1 = 10;
	int* pNum1 = &iNum1;

	cout << "value:" << iNum1 << endl;
	cout << "its address : " << pNum1 << endl;
	*pNum1 = 20; //pNum1의 주소의 '값' 즉, iNum1을 20으로 바꾸겠다.
	cout << "Pointer Value : " << *pNum1 << endl;
	cout << "Pointer Value : " << iNum1 << endl;
	cout << "adress of Pnum1 : " << &pNum1 << endl;
	//포인터 또한 변수이며, 이 변수를 가르키는 '주소'가 있다!
	cout << endl;

	//char형 포인터는, 'char 변수'의 주소만을 저장할 수 있다.,
	char a = 'A';
	name = &a;
	cout << "adress of name : " << name << endl;
	cout << "value of name : " << *name << endl;
	cout << endl;

	//array
	//char타입의 경우, 가장 마지막에 "\0"이 있어야 끝났다고 인식.
	char n[10];
	n[0] = 'J';
	n[1] = 'o';
	n[2] = 'h';
	n[3] = 'n';
	cout << n << endl;
	//방법 1
	n[4] = '\0';
	cout << n << endl;
	cout << endl;

	//방법 2 : 선언할 때 element수를 선언하지 않으면, 마지막에 \0할당. 
	//End Of String
	char m[] = "John";
	cout << m[3] << endl;
	cout << m << endl;
	//그렇기 때문에 이 배열의 사이즈 = 5
	cout << sizeof(m) << endl;

	return 0;
}

//Swap Operation
//위의 경우는, 각num1num2의 카피만 함수 내에서 바뀌고 끝.
void intSwap1(int num1, int num2)
{
	int temp{ num1 };
	num1 = num2;
	num2 = temp;
}
//그러나 밑의 경우는 값의 주소를 넘겨주었기 때문에, 주소 내 값을 바꾸므로 실제 inum1inum2의 값이 바뀜
//포인터도 변수이다. 변수에 주소가 저장되는 것이다.!!!!!1
void intSwap2(int* num1, int* num2)
{
	int temp{ *num1 };
	*num1 = *num2;
	*num2 = temp;
}