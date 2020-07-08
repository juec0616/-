#include <iostream>

using namespace std;

class Node
{
private:
	int data;
	Node *left;
	Node *right;

public:
	Node(int data, Node *left, Node *right)
		:data(data), left(left), right(right) {}
	void setData(int data) { this->data = data; }
	void setLeft(Node *node) { this->left = node; }
	void setRight(Node *node) { this->right = node;}
	
	int getData() { return this->data; }
	Node *getLeft() { return this->left; }
	Node *getRight() { return this->right; }
};

class DoublyLinkedList
{
private:
	Node * head;
	int size;
public:
	DoublyLinkedList() : head(nullptr), size(0) {}

	void setHead(Node *node) { head = node; }
	void addSize() { size++; }
	int getSize() { return size; }
	Node *getHead() { return head; }

	bool isEmpty() { return size == 0 ? true : false; }
	void push(int data)
	{
		if (isEmpty())
		{
			head = new Node(data, head, nullptr);
			head->setLeft(head);
		}
		else
		{
			Node *tmp = new Node(data, nullptr, head);
			head->setLeft(tmp);
			tmp->setLeft(tmp);
			setHead(tmp);
		}
		addSize();
	}
};

int main()
{
	DoublyLinkedList *list = new DoublyLinkedList();

	list->push(10);
	list->push(20);
	list->push(30);

	cout << list->getHead()->getData() << "\n";
	cout << list->getHead()->getRight()->getData() << "\n";

	return 0;
}
