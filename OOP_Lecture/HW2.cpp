#include<iostream>
using namespace std;

class Order {
private:
	string orderID;
	string orderName;
public:
	Order();
	Order(string id, string oname);
	~Order();
	string getOrderInfo();
	string getOrderID();
};
Order::Order() {}
Order::Order(string id, string oname) {
	orderID = id;
	orderName = oname;
}
Order::~Order() {}
string Order::getOrderInfo(){
	return orderName;
}
string Order::getOrderID() {
	return orderID;
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
	if ((front == 0 && rear == maxNumOrder - 1) ||	(rear == (front - 1) % (maxNumOrder - 1)))
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
			<< newOrder.getOrderID() << ']' << ", Total orders so far : " << OrderCnt << endl;
		return 1;
	}
	else if (rear == maxNumOrder - 1 && front != 0)
	{
		OrderCnt += 1;
		rear = 0;
		orderQueue[rear] = newOrder;
		cout << '[' << newOrder.getOrderInfo() << ']' << " is ordered by " << '['
			<< newOrder.getOrderID() << ']' << ", Total orders so far : " << OrderCnt << endl;
		return 1;
	}
	else
	{
		OrderCnt += 1;
		rear++;
		orderQueue[rear] = newOrder;
		cout << '[' << newOrder.getOrderInfo() << ']' << " is ordered by " << '['
			<< newOrder.getOrderID() << ']' << ", Total orders so far : " << OrderCnt << endl;
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

int main()
{
	CoffeeShop starbugs(5);
	Order o1("Alice", "Mocha"), o2("Bob", "Espresso"), o3("David", "Soy"), 
		o4("Brown", "Latte"), o5("Evans", "Whip"), o6("Wilson", "Milk");

	starbugs.getOrderProcessingHandler()->addOrder(o1);
	starbugs.getOrderProcessingHandler()->addOrder(o2);
	starbugs.getOrderProcessingHandler()->serveOrder();
	starbugs.getOrderProcessingHandler()->addOrder(o3);
	starbugs.getOrderProcessingHandler()->addOrder(o4);
	starbugs.getOrderProcessingHandler()->addOrder(o5);
	starbugs.getOrderProcessingHandler()->addOrder(o6);
	starbugs.getOrderProcessingHandler()->addOrder(o1);
	starbugs.getOrderProcessingHandler()->serveOrder();
	starbugs.getOrderProcessingHandler()->serveOrder();
	starbugs.getOrderProcessingHandler()->serveOrder();
	starbugs.getOrderProcessingHandler()->serveOrder();
	starbugs.getOrderProcessingHandler()->serveOrder();
	starbugs.getOrderProcessingHandler()->serveOrder();
	starbugs.getOrderProcessingHandler()->addOrder(o2);

	return 0;
}