#include <iostream>
#include "Array_.h"
#include "linkedList.h"
using namespace std;
int main()
{
	linkedList list;
	if (list.isEmpty()) {
		cout << "\nThis list is empty ";
	}
	else {
		cout << "\nThe list contains " << list.Count();
	}
	int item;
	for (int i = 0; i < 4; i++)
	{
		cout << "\nEnter the "<< i+1 <<" item : ";
		cin >> item;
		list.insertLast(item);
		list.Display();

	}
	cout << "\nEnter the item you want to insert : ";
	cin >> item;
	cout << "\nEnter the item you want to insert before : ";
	int beforeI;
	cin >> beforeI;
	list.insertBefore(beforeI, item);
	list.Display();
	cout << "\n";
	list.Append(4);
	list.Display();
	cout << "\nnDelete : ";
	int d;
	cin >> d;
	list.Delete(d);
	cout << "\n";
	list.Display();
	cout << "\nThe list contains " << list.Count();
	return 0;
}
