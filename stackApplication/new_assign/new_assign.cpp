#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

template<class T>
class Node {
    T data;
    Node* next;
    Node* prev;
public:
    Node(T d, Node* n, Node* p) {
        data = d;
        next = n;
        prev = p;
    }
    // setters
    void setData(T d) {
        data = d;
    }
    void setNext(Node* n) {
        next = n;
    }
    void setPrev(Node* p) {
        prev = p;
    }
    // getters
    T getData() {
        return data;
    }
    Node* getNext() {
        return next;
    }
    Node* getPrev() {
        return prev;
    }
};

template<class T>
class LinkedList {
    Node<T>* head;
public:
    LinkedList() {
        head = NULL;
    }
    void pushFront(T data) {
        Node<T>* newNode = new Node<T>(data, head, NULL);
        head = newNode;
    }
    T pop() {
        if (head == NULL)
        {
            cout << "List is empty !!\n";
            return "";
        }
        Node<T>* temp = head;
        head = head->getNext();
        T data = temp->getData();
        delete temp;
        return data;

    }
    T top() {
        if (head == NULL)
        {
            cout << "List is empty !!\n";
        }
        return head->getData();
    }
};

template<class T>
class Stack {
    LinkedList<T>* list;
    int size;
public:
    Stack() {
        list = new LinkedList<T>();
        size = 0;
    }
    bool isEmpty() {
        if (size == 0) {
            return true;
        }
        return false;
    }
    void push(T data) {
        list->pushFront(data);
        size++;
    }
    T pop() {
        size--;
        return list->pop();
    }
    T top() {
        return list->top();
    }
    void pushByFile(ifstream file) {
        string text;
        int c = 0;
    }
    int getSize() {
        return size;
    }

};
int main()
{
    Stack<string> stack; // store all pages and backward pages
    Stack<string> stackForward; // store forward pages
    string s;
    int i, size;
    ifstream file("URLs.txt");
    ofstream Ofile("Print.txt");
    i = 0; // counter to track each line

    // get URLs size
    while (getline(file, s) && i < 1)
    {
        size = stoi(s);
        i++;
    }

    // push URLs in the stack and break at the last line
    while (getline(file, s) && i < size + 1) {
        if (s != "") {
            stack.push(s);
            i++;
        }
    }

    // last line instructions
    getline(file, s);
    string word;
    istringstream stream(s); // get a stream on the string to slice each instruction
    string currentPage = stack.pop(); // last page is the current user page


    Ofile << "current page is :  " << endl << currentPage << endl;
    Ofile << endl;
    // checking on every instruction
    while (stream >> word)
    {
        if (word == "Forward")
        {
            if (!stackForward.isEmpty()) {
                stack.push(currentPage);
                currentPage = stackForward.pop();
            }
            else {
                cout << "No available forward pages\n";
            }
        }
        else if (word == "Backward")
        {
            if (!stack.isEmpty()) {
                stackForward.push(currentPage);
                currentPage = stack.pop();
            }
            else {
                cout << "No available back pages\n";
            }

        }
        else {
            cout << "Invalid instruction\n";
        }
        Ofile << "Instrunction : " << word << endl;
        Ofile << "The current page is : \n" << currentPage << endl;
        Ofile << "The next one is : \n" << stackForward.top() << endl;
        Ofile << "The previous one is :\n " << stack.top() << endl;
        Ofile << endl;
        Ofile << endl;
        Ofile << endl;
    }
    return 0;
}

