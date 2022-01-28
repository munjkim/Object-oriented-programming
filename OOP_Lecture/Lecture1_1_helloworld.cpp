//Lecture 0

#include <iostream>
using namespace std;

class Idol {
public:
	string name;
	void dance()
	{
		cout << name + " is dancing" << "\n";
	}
};

int main()
{
	Idol bts;
	bts.name = "BTS";
	bts.dance();
	return 0;
}