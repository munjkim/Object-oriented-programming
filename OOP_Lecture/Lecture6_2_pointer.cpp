#include<iostream>
using namespace std;

//근데 사이즈는 왜??

void fun(int arr[], unsigned int n) // SAME AS void fun(int *arr)
{
	cout << "Array size inside fun() is :" << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << arr[0] << endl;
	arr[0] = 9;
}

int main()
{
	//double의 경우 8byte를 차지함
	double arr[3];
	double* ptr;
	ptr = arr;
	cout << &arr[0] << endl;
	cout << arr << endl;
	cout << ptr << endl;
	cout << endl;

	int arr2[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	unsigned int n = sizeof(arr2) / sizeof(arr2[0]);
	cout << "Array size inside main() is :" << n << endl;

	//넘겨줄 때 포인터로 넘긴다는 건 이해됨
	//받을 때 arr[]인데 어떻게 포인터를 받는다는 건지????
	//A. 내 생각은 포인터 자체가 배열을 가리키고, 그 정보를 배열에 입력하면 배열 전체가 옮겨지는 듯.
	fun(arr2, n);
	cout << arr2[0] << endl;

	return 0;
}