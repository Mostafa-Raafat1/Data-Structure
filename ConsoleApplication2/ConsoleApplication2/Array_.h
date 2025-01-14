#pragma once
#include <iostream>
using namespace std;
class Array_
{
	int size_;
	int* items;
	int length; // stroes current length of the array
public:
	// Array Creation
	Array_(int arraySize) {
		size_ = arraySize;
		items = new int(size_);
		length = 0;
	}
	void Fill() {
		int no_items; // stores no_items wish to add;
		cout << "Enter the number of the items u wish to add : ";
		cin >> no_items;
		if (no_items > size_) {
			cout << "\n You can't exceed array size";
			return;
		}
		else {
			for (int i = 0; i < no_items; i++)
			{
				cout << "Enter item no " << i + 1 << endl;
				cin >> items[i];
				length++;
			}
		}
	}
	void Display() {
		cout << "\n Array content : " << endl;
		for (int i = 0; i < length; i++)
		{
			cout << items[i] << "\t";
		}
		cout << endl;
	}
	int getSize() {
		return size_;
	}
	int getLength() {
		return length;
	}
	int Search(int key) {
		for (int i = 0; i < length; i++)
		{
			if (items[i] == key) {
				return i; // return index;
			}
		}
		return -1;
	}
	void Append(int newItem) {
		if (length >= size_) {
			cout << "The Array is full!!\n";
			return;
		}
		items[length] = newItem;
		length++;
	}
	void Insert(int index, int value) {
		if (index >= size_ && index < 0) {
			cout << "Invalid operating, Wrong index\n";
			return;
		}
		else if (length >= size_) {
			cout << "Invalid operating, Array is full\n";
			return;
		}
		for (int i = length; i > index; i--)
		{
			items[i] = items[i - 1];
		}
		items[index] = value;
		length++;
	}
	void Delete(int index) {
		if (index >= size_ && index < 0) {
			cout << "Invalid operating, Wrong index\n";
			return;
		}
		else if (index >= length) {
			cout << "Invalid opperating, index is already null\n";
			return;
		}
		for (int i = index; i < length - 1 ; i++)
		{
			items[i] = items[i + 1];

		}
		length--;

	}
	void Enlarge(int size__) {
		if (size__ < size_) {
			cout << "Invalid operating, new size must be larger than old size \n";
			return;
		}
		int* old = items;
		items = new int[size__];
		for (int i = 0; i < length; i++)
		{
			items[i] = old[i];
		}
		delete[] old;
		size_ = size__;
	}
	void Merge(Array_ other) {
		int new_size = size_ + other.getSize();
		size_ = new_size; // size after adding
		int* old = items;
		items = new int [size_];
		int i;
		for (i = 0; i < length; i++)
		{
			items[i] = old[i];
		}
		delete[] old;
		int j = i;
		for (int i = 0 ; i <  other.getLength() ;i++)
		{
			items[j++] = other.items[i];
			length++;
		}
	}
};

