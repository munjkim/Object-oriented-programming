#include <iostream>
#include <vector>
using namespace std;

class Animal {
protected:
	int numOfLegs;
public:
	virtual int getNumberOfLegs() = 0;
};

class Owner {
private:
	string name;
	vector<Animal*> myPets;
public:
	Owner(string n) {
		name = n;
	}
	void registerPet(Animal* a) {
		// Associate an animal with owner
		myPets.push_back(a);
		return;
	}
	int getTotalNumOflegs() {
		// Return the total number of legs of pets that are owned
		int sum = 0;
		for (int i = 0; i < myPets.size(); i++)
			sum += myPets[i]->getNumberOfLegs();
		return sum;
	}
	string getOwnerName() {
		// Return owner name
		return name;
	}
};

class Dog :public Animal {
public:
	Dog(Owner* o) {
		// Complete Contructor of Dog
		numOfLegs = 4;
		o->registerPet(this);
	}
	int getNumberOfLegs() {
		// Return the number of legs of Dog
		return numOfLegs;
	}
};

class Chicken : public Animal {
public:
	Chicken(Owner* o) {
		// Complete Constructor of Chicken
		numOfLegs = 2;
		o->registerPet(this);
	}
	int getNumberOfLegs() {
		// Return the number of legs of Chicken
		return numOfLegs;
	}
};
int main()
{
	Owner* p_o1 = new Owner("David");
	Animal* p_d1 = new Dog(p_o1);
	Animal* p_c1 = new Chicken(p_o1);
	cout << p_o1->getOwnerName() << " : " << p_o1->getTotalNumOflegs() << endl;

	Owner* p_o2 = new Owner("Kelly");
	Animal* p_d2 = new Dog(p_o2);
	Animal* p_c2 = new Chicken(p_o2);
	Animal* p_c3 = new Chicken(p_o2);
	cout << p_o2->getOwnerName() << " : " << p_o2->getTotalNumOflegs() << endl;

	return 0;
}