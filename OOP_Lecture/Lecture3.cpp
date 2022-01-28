#include <iostream>
using namespace std;

int main()
{
	//conditional statement
	if (true) cout << "true" << endl;
	cout << endl;

	//3항 statement
	int max{ 0 };
	int x{ 10 }, y{ 20 };
	max = (x > y) ? x : y;
	cout << max << endl;
	cout << endl;

	//swith문
	int a = 10;
	switch (a)
	{
		case 5:
			cout << "a : " << 5 << endl;
			break;
		case 10:
			cout << "a : " << 10 << endl;
			break;
		default:
			cout << "not 5 or 10" << endl;
	}
	cout << endl;

	//for문 중에서 break, continue
	for (int i = 1; i < 11; i++)
	{
		if (i == 7)
			break; //가장 가까운 loop 탈출
		else if (i % 2 == 0)
			continue; //남은 loop 건너뜀
		cout << i << '\t';
	}
	cout << endl << endl;

	//!!!!!!!!!!!!
	//for Range-based for loop ;가 아니고 :임!!
	int arr[5] = { 1, 3, 5, 7, 9 };
	for (int element : arr)
		cout << element << " ";
	cout << endl;

	//goto lable - unefficient
	int j{ 0 }, sum{ 0 };
	Lable:
	sum += j;
	j++;
	if (j < 11)
		goto Lable;
	else
		cout << sum << endl;

	return 0;
}