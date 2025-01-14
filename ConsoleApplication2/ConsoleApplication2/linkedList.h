#pragma once
#include <iostream>
using namespace std;

class Node{
	int data;
	Node* next;
public:
	void setData(int d) {
		data = d;
	}
	void setNext(Node* n) {
		next = n;
	}
	int getData() {
		return data;
	}
	Node* getNext() {
		return next;
	}
};

class linkedList
{
	Node* head;
public:
	linkedList() {
		head = NULL;
	}
	// checks the head is pointed to null or not
	bool isEmpty() {
		return(head == NULL); // checks the head is pointed to null or not
	} 
	// inset value in the first
	void insertFirst(int value) {
		Node* newNode = new Node;
		newNode->setData(value);
		if (isEmpty()) {
			newNode->setNext(NULL);
			head = newNode;

		}
		else {
			newNode->setNext(head);
			head = newNode;
		}
	}
	// insert value in the last
	void insertLast(int value) {
		Node* newNode = new Node;
		newNode->setData(value);
		if (isEmpty()) {
			head = newNode;
			newNode->setNext(NULL);
		}
		else {
			Node* temp = head;
			while (temp != NULL) {
				if (temp->getNext() == NULL) {
					temp->setNext(newNode);
					newNode->setNext(NULL);
				}
				temp = temp->getNext();
			}
		}
	}
	//insert avalue before a value
	void insertBefore(int value, int newVal) {
		if (isEmpty()) {
			insertFirst(newVal);
		}
		if (isFound(value)) {
			Node* temp = head;
			Node* newNode = new Node;
			newNode->setData(newVal);
			if (head->getData() == value) {
				insertFirst(newVal);
				return;
			}
			while (temp != NULL && temp->getNext()->getData() != value)
			{
				temp = temp->getNext();
			}
			newNode->setNext(temp->getNext());
			temp->setNext(newNode);
		}
		else {
			cout << "\nValue is not found!!";
		}
	}
	// Display all list values
	void Display() {
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->getData() << " ";
			temp = temp->getNext();
		}
	}
	// count number of values
	int Count() {
		int counter = 0;
		Node* temp = head;
		while (temp != NULL) {
			counter++;
			temp = temp->getNext();
		}
		return counter;
	}
	// search for a value
	bool isFound(int value) {
		Node* temp = head;
		while (temp != NULL) {
			if (temp->getData() == value) {
				return true;
			}
			temp = temp->getNext();
		}
		return false;
	}
	// insert a value @ the end
	void Append(int value) {
		Node* temp = head;
		Node* newNode = new Node;
		newNode->setData(value);
		if (isEmpty()) {
			insertFirst(value);
		}
		else {
			while (temp->getNext() != NULL)
			{
				temp = temp->getNext();
			}
			temp->setNext(newNode);
			newNode->setNext(NULL);

		}
	}
	// Delete a specific value;
	void Delete(int value) {
		if (isEmpty()) {
			cout << "\n the list is empty";
			return;
		}
		if (isFound(value)) {
			Node* delptr;
			Node* temp = head;
			if (head->getData() == value) {
				delptr = head;
				head = head->getNext();
				delete delptr;
			}
			while (temp != NULL && temp->getNext()->getData() != value) {
				temp = temp->getNext();
			}
			delptr = temp->getNext();
			temp->setNext(temp->getNext()->getNext());
			delete delptr;
		}
		else {
			cout << "\nValue is not Found !!";
		}

	}

};

