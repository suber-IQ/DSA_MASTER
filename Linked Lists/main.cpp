#include<iostream>
using namespace std;

class Node {
    public:
      int data;
      Node* next;
      Node(){
        this->data = 0;
        this->next = NULL;
      }
      Node(int data){
        this->data=data;
        this->next= NULL;
      }


};


//👉 Printing Linked List
void print(Node* &head){
    // Node* temp = head;
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}


void insertAtHead(Node* &head,Node* &tail, int data){


    // step1
    Node* newNode = new Node(data);

    if(head == NULL){
       head = newNode;
       tail = newNode;
       return;
    }
    
    // step2
    newNode->next = head;
    
    // step3
     head = newNode;
}

void insertAtTail(Node* &head, Node* &tail, int data){
  // step1
  Node* newNode = new Node(data);

  if(tail == NULL){
    tail = newNode;
    head = newNode;
    return;
  }

  // step2
  tail->next = newNode;

  // step3
  tail = newNode;

}

int getLength(Node* &head){
  int len = 0;
  Node* temp = head;
  while(temp != NULL){
      temp = temp->next;
      len++;
  }
  return len;
}

void insertAtPosition(int data,int position, Node* &head, Node* &tail){
    // step 1

      if(head == NULL){
      Node* newNode = new Node(data);

         tail = newNode;
         head = newNode;
         return;
      }
 
     if(position == 0){
        insertAtHead(head,tail,data);
        return;
     }
       
    int len = getLength(head);

     if(position >= len){
        insertAtTail(head,tail,data);
        return;
     }
    // step 2
     int i = 1;
     Node* prev = head;
     while(i < position){
         prev = prev->next;
         i++; 
     }
     Node* curr = prev->next;

      Node* newNode = new Node(data);

     // step 3
     newNode->next = curr;

    //  step 4
     prev->next = newNode;
}

int main(){

//👉 Printing Linked List
 
//  Node* first = new Node(10);
//  Node* second = new Node(20);
//  Node* third = new Node(30);
//  Node* fourth = new Node(40);
//  Node* fifth = new Node(50);

//  first->next = second;
//  second->next = third;
//  third->next = fourth;
//  fourth->next = fifth;

//  print(first);

//👉 insert on head

// Node* head = NULL;
// Node* tail = NULL;


// insertAtHead(head,tail,20);
// insertAtHead(head,tail,30);
// insertAtHead(head,tail,40);
// insertAtHead(head,tail,50);
// insertAtTail(head,tail,100);

// print(head);

// 👉 insert at position


       Node* head = NULL;
        Node* tail = NULL;
        insertAtHead(head, tail,20);
        insertAtHead(head, tail,50);
        insertAtHead(head, tail,60);
        insertAtHead(head,tail, 90);
        insertAtTail(head, tail, 77);

print(head);

 cout << "head: " << head->data << endl;
//         cout << "tail: " << tail->data << endl;

//         insertAtPosition(101, 2, head, tail);
//         cout<< "Printing after insert at position call" << endl;
//         print(head);
//         cout << endl;
//         cout << "head: " << head -> data << endl;
//         cout << "tail: " << tail->data << endl;
return 0;
}