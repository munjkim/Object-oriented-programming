//hw3

#include <iostream>
using namespace std;

class Beverage {
protected:
	string description = "Unknown Beverage";
public:
	string print_order;
	double print_cost = 0;
	virtual string getDescription() = 0;
	virtual double cost() = 0;
};

class Espresso : public Beverage {
public:
	Espresso() {}
	string getDescription()
	{
		return "Espresso";
	}
	double cost()
	{
		return 1.99;
	}
};

class HouseBlend : public Beverage {
public:
	HouseBlend() {}
	string getDescription()
	{
		return "House Blend Coffee";
	}
	double cost()
	{
		return 0.89;
	}
};

class Decorator : public Beverage {
protected:
	Beverage* beverage;
};

class Mocha : public Decorator {
public:
	Mocha(Beverage* t_beverage)
	{
		print_cost = t_beverage->cost();
		print_order = t_beverage->getDescription();
	}
	string getDescription()
	{
		return print_order + ", Mocha";
	}
	double cost()
	{
		print_cost += 0.2;
		return print_cost;
	}
};

class Whip : public Decorator {
public:
	Whip(Beverage* t_beverage)
	{
		print_cost = t_beverage->cost();
		print_order = t_beverage->getDescription();
	}
	string getDescription()
	{
		return print_order + ", Whip";
	}
	double cost()
	{
		print_cost += 0.45;
		return print_cost;
	}
};
//----------------------------------

class Order {
private:
	string orderID;
	string orderName;
	double orderCost;
public:
	Order();
	Order(string id, string oname);
	Order(string id, Beverage* obev);
	~Order();
	string getOrderInfo();
	string getOrderID();
	double getCost();
};
Order::Order() {
}
Order::Order(string id, string oname) {
	orderID = id;
	orderName = oname;
}
Order::Order(string id, Beverage* obev) {
	orderID = id;
	orderName = obev->getDescription();
	orderCost = obev->cost();
}
Order::~Order() {}
string Order::getOrderInfo() {
	return orderName;
}
string Order::getOrderID() {
	return orderID;
}
double Order::getCost() {
	return orderCost;
}

class OrderProcessing {
private:
	int maxNumOrder;
	Order* orderQueue;
	int front, rear;
	static int OrderCnt;
public:
	int addOrder(Order newOrder);
	int serveOrder();
	OrderProcessing(int maxOrder);
	~OrderProcessing();
};
int OrderProcessing::OrderCnt = 0;
OrderProcessing::OrderProcessing(int maxOrder) {
	maxNumOrder = maxOrder;
	front = rear = -1;
	orderQueue = new Order[maxOrder];
}
OrderProcessing::~OrderProcessing() {
	delete[] orderQueue;
}
int OrderProcessing::addOrder(Order newOrder) {
	if ((front == 0 && rear == maxNumOrder - 1) || (rear == (front - 1) % (maxNumOrder - 1)))
	{
		cout << "Queue is full, Total orders so far : " << OrderCnt << endl;
		return 0;
	}
	else if (front == -1) /* Insert First Element */
	{
		OrderCnt += 1;
		front = rear = 0;
		orderQueue[rear] = newOrder;
		cout << '[' << newOrder.getOrderInfo() << ']' << " is ordered by " << '['
			<< newOrder.getOrderID() << ']' << " with cost $" << newOrder.getCost()
			<< " Total orders so far : " << OrderCnt << endl;
		return 1;
	}
	else if (rear == maxNumOrder - 1 && front != 0)
	{
		OrderCnt += 1;
		rear = 0;
		orderQueue[rear] = newOrder;
		cout << '[' << newOrder.getOrderInfo() << ']' << " is ordered by " << '['
			<< newOrder.getOrderID() << ']' << " with cost $" << newOrder.getCost()
			<< " Total orders so far : " << OrderCnt << endl;
		return 1;
	}
	else
	{
		OrderCnt += 1;
		rear++;
		orderQueue[rear] = newOrder;
		cout << '[' << newOrder.getOrderInfo() << ']' << " is ordered by " << '['
			<< newOrder.getOrderID() << ']' << " with cost $" << newOrder.getCost()
			<< " Total orders so far : " << OrderCnt << endl;
		return 1;
	}
}
int OrderProcessing::serveOrder() {
	if (front == -1)
	{
		cout << "Queue is empty, Total Orders so far : " << OrderCnt << endl;
		return 0;
	}

	Order data = orderQueue[front];

	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if (front == maxNumOrder - 1)
		front = 0;
	else
		front++;

	cout << "[" << data.getOrderInfo() << "]" << " is served to [" << data.getOrderID()
		<< "], Total orders so far : " << OrderCnt << endl;
	return 1;
}
class CoffeeShop {
private:
	int numOfTables;
	string name;
	OrderProcessing* myOrderProcessing;
public:
	CoffeeShop();
	CoffeeShop(int numTable);
	CoffeeShop(int numTable, string shop_name);
	~CoffeeShop();
	OrderProcessing* getOrderProcessingHandler();
};
CoffeeShop::CoffeeShop() {
	numOfTables = 20;
	name = "Pandorothy";
	myOrderProcessing = new OrderProcessing(numOfTables);
}
CoffeeShop::CoffeeShop(int numTable) {
	numOfTables = numTable;
	name = "Pandorothy";
	myOrderProcessing = new OrderProcessing(numOfTables);
}
CoffeeShop::CoffeeShop(int numTable, string shop_name) {
	numOfTables = numTable;
	name = shop_name;
	myOrderProcessing = new OrderProcessing(numOfTables);
}
CoffeeShop::~CoffeeShop() {
	delete myOrderProcessing;
}
OrderProcessing* CoffeeShop::getOrderProcessingHandler() {
	return myOrderProcessing;
}

int main() {
	Beverage* beverage1;
	beverage1 = new Espresso();
	beverage1 = new Mocha(beverage1);
	beverage1 = new Mocha(beverage1);
	beverage1 = new Whip(beverage1);
	beverage1 = new Whip(beverage1);

	Beverage* beverage2;
	beverage2 = new HouseBlend();
	beverage2 = new Mocha(beverage2);
	beverage2 = new Whip(beverage2);

	Beverage* beverage3;
	beverage3 = new Espresso();

	CoffeeShop starbugs(5);
	Order o1("Alice", beverage1), o2("Bob", beverage2), o3("Moon", beverage3);
	starbugs.getOrderProcessingHandler()->addOrder(o1);
	starbugs.getOrderProcessingHandler()->addOrder(o2);
	starbugs.getOrderProcessingHandler()->serveOrder();
	starbugs.getOrderProcessingHandler()->addOrder(o3);
	starbugs.getOrderProcessingHandler()->serveOrder();
	starbugs.getOrderProcessingHandler()->serveOrder();
	starbugs.getOrderProcessingHandler()->serveOrder();

	delete beverage1, beverage2, beverage3;
	return 0;
}