#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node(int value)
  {
    data = value;
    next = NULL;
  }
};

void print(Node *Head)
{
    Node *temp = Head;
    // while(temp != NULL){
    while(temp){
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
}

void insertBeginning(Node* &Head,int *arr){
  // Linked list doesn't exist
  for (int i = 0; i < 5; ++i)
  {
    if (Head == NULL)
    {
      Head = new Node(arr[i]);
    }
    else
    {
      // linked list exists
      Node *temp;
      temp = new Node(arr[i]);
      temp->next = Head;
      Head = temp;
    }
  }
}

void insertEnd(Node* &Head,Node* &Tail,int *arr){
    for(int i = 0; i < 5; ++i){
       if(Head == NULL){
           Head = new Node(arr[i]);
           Tail = Head;
       }else{
          Tail->next = new Node(arr[i]);
          Tail = Tail->next;
       }
    }
}

int main()
{

  // 👉 Part 1

  // // Node A1(4);

  // Node *Head;
  // Head = new Node(4);

  // cout << Head->data << endl;
  // cout << Head->next << endl;

  // 👉 Part 2 (Insert the Node at beginning)
  // int arr[] = {2, 4, 6, 8, 10};

  // Node *Head;
  // Head = NULL;

  // insertBeginning(Head,arr);
  

  // print(Head);

  // 👉 Part 2 (Insert the Node at end)

  int arr[] = {2, 4, 6, 8, 10};

  Node *Head;
  Node *Tail;
  Head = NULL;
  Tail = NULL;

  insertEnd(Head,Tail,arr);
  

  print(Head);


  return 0;
}