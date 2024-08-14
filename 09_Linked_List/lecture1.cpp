#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

      //TODO: Write a destrcutor to delete a node
        ~Node() {
                //write your code here
                cout << "Node with value: " << this->data << "deleted" << endl;
        }
};

void print(Node* &head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// 👉 want to insert a node left at the head of linked list
void insertAtHead(Node* &head,int data){
    // Step 1:
    Node* newNode = new Node(data);
    // Step 2:
    newNode->next = head;
    // Step 3:
    head = newNode;
}

// 👉 want to insert a node right at the head of linked list
void insertAtTail(Node* &head,Node* &tail,int data){

    // Step 1:
    Node* newNode = new Node(data);

   if(head == NULL){
    //   Node* newNode = new Node(data);
      head = newNode;
      tail = newNode;
   }else{

 // Step 1:
    // Node* newNode = new Node(data);
    // Step 2:
    tail->next = newNode;
    // Step 3:
    tail = newNode;
   }


}

// 👉 insertAtHead With tail(version 2 of insertAtHead method)
void insertAtHeadT(Node* &head,Node* &tail,int data){
    // Step 1:
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }else{
         // Step 2:
    newNode->next = head;
    // Step 3:
    head = newNode;
    }
   
}
int findLength(Node* &head){
    int len = 0;
    Node* temp = head;
    while(temp){
        temp = temp->next;
        len++;
    }
    // cout << "len: " << len << endl;
    return len;
}
// 👉 insertAtPostion
void insertAtPosition(int position,Node* &head, Node* &tail,int data){
   if(head ==NULL){
     Node* newNode = new Node(data);
     head = newNode;
     tail = newNode;
   }
  //step 1: find the position: prev & curr:
//   from here basic condition from beginning Node and after last Node
    if(position <= 0){
        insertAtHeadT(head,tail,data);
        return;
    }
    int len = findLength(head);
    if(position >= len){
        insertAtTail(head,tail,data);
        return;
    }
  // find the position: prev & curr start form here :
        int i = 1;
        Node* prev = head;
        while(i < position){
           prev = prev->next;
           i++;
        }
        Node* curr = prev->next;

        // step 2: create a new node
        Node* newNode = new Node(data);
        
        //step 3: 
         newNode->next = curr;

         // step 4:
         prev->next = newNode;
}

void deleteNode(int position,Node* &head,Node* &tail){
     if(head == NULL) {
                cout << "Cannot delete, LL is empty";
                return;
        }

        //deleting first node
        if(position == 1) {
                Node* temp = head;
                head = head -> next;
                temp -> next = NULL;
                delete temp;
                return;
        }
        int len  = findLength(head);

       if(position > len){
         cout << "Given correct position ";
         return;
       }
        //deleting last node
        if(position == len) {
                //find prev
                int i = 1;
                Node* prev = head;
                while(i < position - 1) {
                        prev = prev->next;
                        i++;
                }
                //step2:
                prev->next = NULL;
                //step3:
                Node* temp = tail;
                //step4:
                tail = prev;
                //step5:
                delete temp;
                return;
        }

        //deleting middle node

        //step  : find prev and curr
        int i =1;
        Node* prev = head;
        while( i < position-1) {
                prev= prev -> next;
                i++;
        }
        Node* curr = prev -> next;

        //step2:
        prev -> next = curr -> next;
        //step3:
        curr -> next = NULL;
        //step4:
        delete curr;

}

Node* reverse(Node* &prev,Node* &curr) {
    // base case
    if(curr == NULL){
        //LL reverse end on node (curr)
        return prev;
    }

    Node* Nex = curr -> next;
    curr -> next  = prev;

   return reverse(curr,Nex);
}
Node* reverseLoop(Node* &head){
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL){
        Node* temp = curr -> next;
        curr-> next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;

}

int main(){

//   Node* first = new Node(10);
//   Node* second = new Node(40);
//   Node* third = new Node(35);
//   Node* fourth = new Node(25);
//   Node* fifth = new Node(4);

//   first->next = second;
//   second->next = third;
//   third->next = fourth;
//   fourth->next = fifth;
//❓  Printing Linked List
//   print(first);

// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

//   ❓ Insert At Head

// Node* head = new Node(10);
// Node* head = NULL;

// for(int i = 2; i < 30; i += 4){  // give multiple data
//     int data = i * 2;
//     insertAtHead(head,data);
// }
// print(head);

// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

//   ❓ Insert At Tail

// Node* head = new Node(10);
// Node* head = NULL;
// Node* tail = NULL;

// for(int i = 2; i < 12; i += 2){  // give multiple data
//     int data = i * 10;
//     insertAtTail(head,tail,data);
// }
// print(head);

// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

//   ❓ Insert At Head (version 2 with tail parameter)

// Node* head = NULL;
// Node* tail = NULL;

// for(int i = 2; i < 12; i += 2){  // give multiple data
//     int data = i * 10;
//     insertAtHeadT(head,tail,data);
// }
// print(head);


// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

//   ❓ Insert At Position

// Node* head = NULL;
// Node* tail = NULL;

// insertAtTail(head,tail,20);
// insertAtTail(head,tail,40);
// insertAtTail(head,tail,60);
// insertAtTail(head,tail,70);
// insertAtTail(head,tail,80);
// insertAtTail(head,tail,100);
// int pos = 3;
// insertAtPosition(pos,head,tail,23);
// print(head);

// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

//   ❓ Delete Node

// Node* head = NULL;
// Node* tail = NULL;

// insertAtTail(head,tail,20);
// insertAtTail(head,tail,40);
// insertAtTail(head,tail,60);
// insertAtTail(head,tail,70);
// insertAtTail(head,tail,80);
// insertAtTail(head,tail,100);
// int pos = 6;
// deleteNode(pos,head,tail);
// print(head);

// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

//   ❓ Reverse Node using recursive L.L


// Node* head = NULL;
// Node* tail = NULL;

// for(int i = 2; i < 12; i += 2){  // give multiple data
//     int data = i * 10;
//     insertAtTail(head,tail,data);
// }

// cout << "Before print: " << endl;
// print(head);

// Node* prev = NULL;
// Node* curr = head;
// head = reverse(prev,curr);
// cout << endl;

// cout << "After print: " << endl;
// print(head);
// cout << endl;

// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

//   ❓ Reverse Node using Loop L.L


Node* head = NULL;
Node* tail = NULL;

for(int i = 2; i < 12; i += 2){  // give multiple data
    int data = i * 10;
    insertAtTail(head,tail,data);
}

cout << "Before print: " << endl;
print(head);

head = reverseLoop(head);


cout << "\nAfter print: " << endl;
print(head);
cout << endl;


    return 0;
}