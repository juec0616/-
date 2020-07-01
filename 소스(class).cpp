#include <iostream>

using namespace std;

class Node
{
private:
	int data;
	Node *next;

	
public:
	Node()
	{
		this->data = 0;
		this->next = nullptr;
	}
	Node(int data)
	{
		this->data = data;
		this->next = nullptr;
	}
	void setData(int data)
	{
		/*
		if (data < 0)
		{
			this->data = 0;
		}
		else
		{
			this->data = data;
		}
		*/
		this->data = data < 0 ? 0 : data;
	}
	
	void setNext(Node *next)
	{
		this->next = next;
	}

	int getData()
	{
		return this->data;
	}
	Node *getNext()
	{
		return this->next;
	}
};

;

class LinkedList
{
private:
	Node *head;
	int size;
public:
	LinkedList()
	{
		this->head = new Node();
		this->size = 0;
	}

	~LinkedList()
	{
		Node *curr = head;
		while (curr != NULL)
		{
			Node *tmp = curr;
			curr = curr->getNext();
			delete tmp;
		}
		delete head;
	}

	void addSize() { this->size++; }

	void subSize() { this->size--; }
	
	void setHead(Node *target) { this->head = target; }

	Node *getHead() { return head; }
	
	void nodePush(int data); // 프로토타입
	void nodePrint();
	int nodePop();
};

void LinkedList::nodePush(int data)
{
    Node *tmp = new Node(data);
    tmp->setNext(head->getNext());
	setHead(tmp);
	addSize();
}

void LinkedList::nodePrint()
{
  Node *tmp = head;
  cout << "LinkedList :";
  while (tmp != NULL)
  {
    cout << tmp->getData() << " ";
    tmp = tmp->getNext();
  }
  cout << "\n";
}

int LinkedList::nodePop()
{
  if (size == 0)
  {
    return -1;
  }
  Node *tmp = head;
  head = head->getNext();

  int data = tmp->getData();
  delete tmp;

  return data;
}

int main()
{
	LinkedList *list = new LinkedList();

	list->nodePush(10);
	list->nodePush(20);
	list->nodePush(30);
	list->nodePrint();

	cout << "pop : " << list->nodePop() << "\n";
	list->nodePrint();

	delete list;

	return 0;
}