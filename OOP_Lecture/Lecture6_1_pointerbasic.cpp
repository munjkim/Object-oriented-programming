#include<iostream>
using namespace std;

int main()
{
	char c = 'A';
	char* ptr_c = &c;
	cout << "ptr_c : " << ptr_c << endl;
	//주소는 상황에 따라서 컴파일러 내에서 알아서 설정함.

	//pointer 와 array 간의 관계;
	char str[] = "Hello";
	char* ptr_str = str;
	cout << "ptr_str : " << ptr_str << endl; //주소가 아닌 문자열
	cout << "*ptr_str : " << *ptr_str << endl; //배열의 첫번재 element
	cout << endl;

	int studentID[][3] = { {1 }, {4, 5, 6} };
	cout << studentID[0][0] << endl;
	cout << studentID[0][1] << endl;
	cout << studentID[0][2] << endl;
	cout << studentID[1][0] << endl;
	cout << studentID[1][1] << endl;
	cout << studentID[1][2] << endl;
	//char = 1byte, int = 4byte
	cout << sizeof(studentID) << endl;
	cout << sizeof(studentID[0]) << endl;
	cout << endl;

	//!!!!!!!!!!!!!!!!!
	//array이름이 포인터로 사용될 수 있다.
	int iNum = 0;
	int iNums[3] = { 1, 2, 3 };
	
	int* pNum = &iNum;
	int* pNums1 = &iNums[0];
	int* pNums2 = iNums; //이렇게 배열의 이름이 포인터로 사용될 수 있다.
	cout << pNums1 << endl << pNums2 << endl;
	cout << *pNums1 << endl << *pNums2 << endl;
	cout << iNums[1] << endl << pNums1[1] << endl << pNums2[1] << endl;
	//pNums1과 pNums2는 포인터인데, 이를 *쓰지않고 값을 가져올 수 있다.
	cout << endl;
	//!!!!!!!!!!!!!!!!!!!
	//포인터의 연산
	cout << pNums2 << endl; //&iNums[0]
	cout << pNums2 + 1 << endl; //&iNums[1]
	cout << pNums2 + 2 << endl; //&iNums[2]
	//메모리 사이즈는 int 4byte씩 차이남.

	//밑의 두 식은 같다는 점!!!!!!!!!!!!!!!!!!!
	cout << *pNums2 << " " << * (pNums2 + 1) << endl; //iNums[0] iNums[1]
	cout << pNums2[0] << " " << pNums2[1] << endl;
	cout << endl;

	// row: 2, col : 3
	cout << "****2-dim array and pointer****" << endl;
	cout << "포인터의 경우, 배열로 치환하면 쉽다!" << endl;
	int n[2][3] = { 1, 2, 3, 4, 5, 6 };
	cout << n << endl;
	cout << *n << endl;
	cout << n[0] << endl;
	cout << &n[0][0] << endl << endl;

	cout << n + 1 << endl; // 시작점 주소 + 1은 시작row + 1 이다.
	cout << n[1] << endl << endl;

	cout << *n + 1 << endl; //n[0][0]의 주소 + 1 = n[0][1]
	cout << &(n[0][1]) << endl << endl;

	cout << **n << endl;
	cout << n[0][0] << endl << endl;

	cout << **(n + 1) << endl;
	cout << n[1][0] << endl << endl;

	cout << *((*n) + 1) << endl;
	cout << n[0][1] << endl << endl;

	cout << *((*(n + 1)) + 1) << endl;
	cout << n[1][1] << endl << endl;

	return 0;
}