#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Beverage {
protected:
    string description = "Unknown Beverage";
public:
    string print_order;
    double print_cost = 0;
    virtual string getDescription() = 0;
    virtual double cost()
    {
        return 0;
    }
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
    friend istream& operator>>(istream& in, Order& t_o)
    {
        string t_o_orderID = t_o.getOrderID();

        int select_base;
        int select_deco;
        Beverage* obev;

        cout << "Enter your name for the order : ";
        in >> t_o.orderID;

        cout << "Select the Base Beverage: (1) Espresso ($1.99), (2) HouseBlend ($0.89) =>" << endl;
        in >> select_base;

        if (select_base == 1)
            obev = new Espresso();
        else
            obev = new HouseBlend();

        int temp = 1;
        while (true)
        {
            cout << "Select the Decorators. After selecting all deco, press (3): (1) Mocha ($0.20), (2) Whipped Cream ($0.45), (3) Done =>" << endl;
            in >> select_deco;

            if (select_deco == 3)
            {
                temp = 0;
                break;
            }
            else if (select_deco == 1)
                obev = new Mocha(obev);
            else if (select_deco == 2)
                obev = new Whip(obev);
        }

        cout << "Finalizing the Order..." << endl;

        t_o.orderCost = obev->cost();
        t_o.orderName = obev->getDescription();

        return in;
    }
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
    orderCost = obev->print_cost;
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
    //Order* orderQueue;
    vector<Order> orderQueue;
    //int front, rear;
    static int OrderCnt;
public:
    int addOrder(Order newOrder);
    int serveOrder();
    OrderProcessing(int maxOrder);
    ~OrderProcessing();
};
int OrderProcessing::OrderCnt = 0;
//Modified with vector
OrderProcessing::OrderProcessing(int maxOrder) {
    maxNumOrder = maxOrder;
    //front = rear = -1;
    orderQueue;
}
OrderProcessing::~OrderProcessing() {
    //delete[] orderQueue;
}
int OrderProcessing::addOrder(Order newOrder) {
    if (orderQueue.size() == maxNumOrder)
    {
        cout << "Queue is full, Total orders so far : " << OrderCnt << endl;
        return 0;
    }
    else
    {
        OrderCnt += 1;
        orderQueue.push_back(newOrder);
        cout << "[" << newOrder.getOrderInfo() << "] is ordered by [" << newOrder.getOrderID() << "] with cost $" << newOrder.getCost() << " Total orders so far : " << OrderCnt << endl;
        return 1;
    }
}
int OrderProcessing::serveOrder() {
    if (orderQueue.empty())
    {
        cout << "Queue is empty, Total orders so far : " << OrderCnt << endl;
        return 0;
    }
    else
    {
        Order data = orderQueue.front();
        orderQueue.erase(orderQueue.begin());
        cout << "[" << data.getOrderInfo() << "] is served to [" << data.getOrderID() << "], Total orders so far : " << OrderCnt << endl;
        return 1;
    }
}

//---------------------------------
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
    Beverage* beverage1;
    beverage1 = new Espresso(); //1.99
    beverage1 = new Mocha(beverage1); //0.20
    beverage1 = new Mocha(beverage1); //0.20
    cout << "Total cost: " << beverage1->cost() << endl;
    cout << beverage1->getDescription() << endl;
    Beverage* beverage2;
    beverage2 = new HouseBlend(); //0.89
    beverage2 = new Mocha(beverage2); //0.20
    beverage2 = new Whip(beverage2); //0.45
    cout << "Total cost: " << beverage2->cost() << endl;
    cout << beverage2->getDescription() << endl;
    CoffeeShop starbugs(5);
    Order o1("Alice", beverage1), o2("Bob", beverage2);
    starbugs.getOrderProcessingHandler()->addOrder(o1);
    starbugs.getOrderProcessingHandler()->addOrder(o2);
    starbugs.getOrderProcessingHandler()->serveOrder();
    starbugs.getOrderProcessingHandler()->serveOrder();
    starbugs.getOrderProcessingHandler()->serveOrder();
    return 0;
}