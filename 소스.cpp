#include <iostream>

using namespace std;

typedef struct _Node
{
	int data;
	_Node * next;
} Node;

typedef struct _Head
{
	_Node * head;
	int size;
} Head;

bool nodeInsert(Head* &head, int data)
{
	try
	{
		Node *tmp = new Node;
		tmp->data = data;
		tmp->next = head->head;
		head->head = tmp;
		head->size++;
		return true;
	}
	catch (const exception &e)
	{
		return false;
	}
}

void deleteNode(Head *&head)
{
	Node *curr = head->head;
	while (curr != NULL)
	{
		Node *tmp = curr;
		curr = curr->next;
		delete tmp;
	}
	delete head;

}

int main()
{
	Head *head = new Head;
	head->head = NULL;
	head->size = 0;

	nodeInsert(head, 10);
	nodeInsert(head, 20);
	nodeInsert(head, 30);

	cout << head->head->data << "\n";
	cout << head->head->next->data << "\n";
	cout << head->head->next->next->data << "\n";

	deleteNode(head);

	return 0;
}