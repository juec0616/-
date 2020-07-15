#include <iostream>

using namespace std;

class Node
{
private:
	int data;
	Node *left;
	Node *right;

public:
	Node(int data) : data(data), left(nullptr), right(nullptr) {}
	void setData(int data) { this->data = data; }
	void setLeft(Node *node) { this->left = node; }
	void setRight(Node *node) { this->right = node; }

	int getData() { return this->data; }
	Node *getLeft() { return this->left; }
	Node *getRight() { return this->right; }
};

class BinarySearchTree
{
private:
	Node * root;

public:
	BinarySearchTree() : root(nullptr) {}

	Node *getRoot() { return root; }
	void setRoot(Node *r) { root = r; }

	bool insert(int data);
	Node* _insert(Node* node, int data);
};

bool BinarySearchTree::insert(int data)
{
	root = _insert(root, data);
	return root != nullptr;
}

Node *BinarySearchTree::_insert(Node* node, int data)
{
	if (node == nullptr)
	{
		node = new Node(data);
	}
	else
	{
		if (node->getData() > data)
		{
			node->setLeft(_insert(node->getLeft(), data));
		}
		else
		{
			node->setRight(_insert(node->getRight(), data));
		}
	}
	return node;
}