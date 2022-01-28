/*
Local Variable : 함수 내
Global Variable : 모든 함수 / 끝날 때 까지
Static Variable : 함수 내 / 끝날 때 까지 정보가 남아있음
*/

#include <iostream>
using namespace std;

double g_count = 0;

//void는 return값이 필요하지 않을 때 사용
void counter() {
	static int iCount = 0;
	//질문!!!!!!!!!!!!!!!!!
	//int iCount = 0;과 다른점은 무엇인가?
	//Answer : iCount의 역사가 살아있음!!!!!!
	//즉, global 하게 선언하지 않아도 static의 경우, global의 성격을 띈다.

	iCount++;
	g_count = iCount;
	cout << iCount << endl;
}
int main()
{
	counter();
	counter();
	counter();
	cout << g_count << endl;
	//cout << iCount << endl;
	return 0;
}

//전처리자, namespace 다시 복습 필요!!!!!!!!