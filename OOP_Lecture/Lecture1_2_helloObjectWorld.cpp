#include<iostream>
using namespace std;

class Message {
private:
	//member variable
	int num1, num2;
public:
	//member method
	void dispaly() {
		num1 = 1;
		num2 = 2;
		cout << "Hello Object World" << endl;
		cout << num1 << "+" << num2 << "=" << num1 + num2;
	}
};
int main()
{
	Message t;
	t.dispaly();
	return 0;
}