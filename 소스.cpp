#include <iostream>

using namespace std;

typedef struct _Node
{
  int data;
  _Node *next;
} Node;

typedef struct _Head
{
  _Node *head;
  int size;
} Head;

bool nodePush(Head *&head, int data)
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

void nodePrint(Head *&head)
{
  Node *tmp = head->head;
  while (tmp != NULL)
  {
    cout << tmp->data << " ";
    tmp = tmp->next;
  }
  cout << "\n";
}

int nodePop(Head *&head)
{
  if (head->size == 0)
  {
    return -1;
  }
  Node *tmp = head->head;
  head->head = head->head->next;

  int data = tmp->data;
  delete tmp;

  return data;
}

void nodeDestroy(Head *&head)
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

  cout << "pop : " << nodePop(head) << "\n";

  nodePush(head, 10);
  nodePrint(head);
  cout << "pop : " << nodePop(head) << "\n";
  nodePrint(head);

  nodePush(head, 20);
  // nodePrint(head);
  nodePush(head, 30);
  nodePrint(head);
  cout << "pop : " << nodePop(head) << "\n";
  nodePrint(head);

  nodeDestroy(head);

  return 0;
}