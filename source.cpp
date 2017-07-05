// Name: Ali Bayati 
// Problem: Priority Queue
// Chapter # 8
// Lab # 10


#include<iostream>
#include<string>
#include"vpqueue.h"

using namespace std;

enum shipping
{
	ONE_DAY = 11,
	TWO_DAY = 8,
	STANDARD = 4,
	FREE = 1
};

class order
{
public:
	order(string i, shipping c) { itemName = i; shippingCode = c; }
	void print() const { cout << "Item: " << itemName << " Code: " << shippingCode << endl; }
	bool operator>(order rhs) const { return shippingCode > rhs.shippingCode; }
	int getshipping() { return shippingCode; };
	string name() { return itemName; };
private:
	string itemName;
	shipping shippingCode;
};


int main()
{
	
	vpriority_queue<order> q;		// empty queue - only version of the constructor

	order o1("Apple Air Pods", TWO_DAY);
	order o2("Nintendo Switch", ONE_DAY);
	order o3("Book", FREE);
	order o4("OLED TV", TWO_DAY);
	order o5("Detergent", STANDARD);

	q.push(o1);
	q.push(o2);
	q.push(o3);
	q.push(o4);
	q.push(o5);
	
	int choice;
	string itemName;
	shipping code;

	while (!q.empty())
	{
		cout << "Items in Queue : ";
		cout << q.size() << endl;
		cout << "Enter Code: 1 - Fill Order, 2 - Add Order: ";
		cin >> choice;
		
		if (choice == 1)
		{
			cout << "Filling Order" << endl;
			q.top().print();
			q.pop();
			cout << endl;
		}
		else if (choice == 2)
		{
			cout << "Enter Name: ";
			cin >> itemName;

		  
			code = FREE;

			order newO(itemName, code);

			q.push(newO);
		}
		
	}
	cout << "The Queue is empty !" << endl;

	

	return 0;
}
/*Output
Items in Queue : 5
Enter Code: 1 - Fill Order, 2 - Add Order: 2
Enter Name: Aladdin-Movie
Items in Queue : 6
Enter Code: 1 - Fill Order, 2 - Add Order: 2
Enter Name: ps3
Items in Queue : 7
Enter Code: 1 - Fill Order, 2 - Add Order: 1
Filling Order
Item: Nintendo Switch Code: 11

Items in Queue : 6
Enter Code: 1 - Fill Order, 2 - Add Order: 1
Filling Order
Item: Apple Air Pods Code: 8

Items in Queue : 5
Enter Code: 1 - Fill Order, 2 - Add Order: 1
Filling Order
Item: OLED TV Code: 8

Items in Queue : 4
Enter Code: 1 - Fill Order, 2 - Add Order: 1
Filling Order
Item: Detergent Code: 4

Items in Queue : 3
Enter Code: 1 - Fill Order, 2 - Add Order: 1
Filling Order
Item: Aladdin-Movie Code: 1

Items in Queue : 2
Enter Code: 1 - Fill Order, 2 - Add Order: 1
Filling Order
Item: Book Code: 1

Items in Queue : 1
Enter Code: 1 - Fill Order, 2 - Add Order: 1
Filling Order
Item: ps3 Code: 1

The Queue is empty !
Press any key to continue . . .*/