#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int getLength(Node* head){
    int len = 0;
    Node* temp = head;

    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

// ➡️ Section 02: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀
//    👉 Insert At Head doubly Linked List

void insertAtHead(Node* &head,Node* &tail,int data){
   if(head == NULL){
      Node* newNode = new Node(data);
      head = newNode;
      tail = newNode;
      return;
   }else{
      Node* newNode = new Node(data);
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
   }

}
// ➡️ Section 03: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀
//    👉 Insert At Tail doubly Linked List

void insertAtTail(Node* &head,Node* &tail,int data){
     if(head == NULL){
         Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
     }else{
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
     }
}

// ➡️ Section 04: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀
//    👉 Insert At Position Linked List

void insertAtPosition(Node* &head,Node* &tail,int position,int data){
     if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
     }
     if(position == 1){
        insertAtHead(head,tail,data);
        return;
     }
     int length  = getLength(head);
     if(position > length){
        insertAtTail(head,tail,data);
        return;
     }else{
         int i = 1;
    Node* left = head;
    while(i < position - 1){
        left = left->next;
        i++;
    }
    Node* right = left->next;
    Node* newNode = new Node(data);
    right->prev = newNode;
    newNode->next = right;
    left->next = newNode;
    newNode->prev = left;

     }
    
}

    // ➡️ Section 05: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀
//   👉 delete any Position Linked List


void deleteAtPosition(Node* &head,Node* tail,int position){
    if(head == NULL){
        cout << "Do not delete? Linked list is empty" << endl;
        return;
    }
    if(head->next == NULL){
        Node* temp = head;
           head = NULL;
           tail = NULL;
           delete temp;
          return;
    }
       int len = getLength(head);
        if(position > len) {
                cout << "please enter a valid position " << endl;
                return;
        }
         if(position == 1) {
                //want to delete the first node
                Node* temp = head;
                head = head ->next;
                head -> prev = NULL;
                temp ->next = NULL;
                delete temp;
                return;
        }
         if(position == len) {
                //delete last node
                Node* temp = tail;
                tail = tail -> prev;
                temp ->prev = NULL;
                tail ->next = NULL;
                delete temp;
                return;
        }

        //delete from middle of linked list

        //step1: find left, curr, right
        int i = 1;
        Node* left = head;
        while( i < position - 1) {
                left = left -> next;
                i++;
        }
        Node* curr = left -> next;
        Node* right = curr -> next;

        //step2:
        left -> next = right;
        //step3:
        right -> prev = left;
        //step4:
        curr -> next = NULL;
        curr ->prev = NULL;
        delete curr;
}

    // ➡️ Section 06: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀
//   👉 Reversed Linked List


Node* reverse(Node* &prev, Node* &curr) {
        //base case
        if(curr == NULL) {
                //LL reverse ho chuki
                return prev;
        }
        
        //1 case solve then recursion will take care
        Node* forward = curr -> next;
        curr -> next = prev;

        reverse(curr, forward);
}

Node* reverseusingLoop(Node* head ) {
        Node* prev = NULL;
        Node* curr = head;

        while(curr != NULL ) {
                Node* temp = curr ->next;
                curr ->next = prev;
                prev = curr;
                curr = temp;
        }
        return prev;
}

int main(){

// ➡️ Section 01: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀
//    👉 Print doubly Linked List
    // Node* first = new Node(10);
    // Node* second = new Node(30);
    // Node* third = new Node(40);

    // first->next = second;
    // second->prev = first;

    // second->next = third;
    // third->prev =  second; 
   

    // Node* head = first;
    // Node* tail = third;
    // print(head);


// ➡️ Section 02: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀
//    👉 Insert At Head doubly Linked List

//    Node* first = new Node(10);
//     Node* second = new Node(30);
//     Node* third = new Node(40);

//     first->next = second;
//     second->prev = first;

//     second->next = third;
//     third->prev =  second; 

    // 🌟 After check this head equal to NULL Ho to
   // Node* first = NULL;
    // Node* third = NULL;

//     Node* head = first;
//     Node* tail = third;

//   insertAtHead(head,tail,22); // output:- 22 10 30 40 
//    print(head);


// ➡️ Section 03: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀
//    👉 Insert At Tail doubly Linked List
//        Node* first = new Node(10);
//       Node* second = new Node(30);
//      Node* third = new Node(40);

//     first->next = second;
//     second->prev = first;

//     second->next = third;
//     third->prev =  second; 

//      // 🌟 After check this head equal to NULL Ho to
// //    Node* first = NULL;
// //     Node* third = NULL;

//     Node* head = first;
//     Node* tail = third;

//    insertAtTail(head,tail,55);  // output:- 10 30 40 55
//    print(head);

   
// ➡️ Section 04: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀
//    👉 Insert At Position Linked List

    //    Node* first = new Node(10);
    //   Node* second = new Node(30);
    //  Node* third = new Node(40);

    // first->next = second;
    // second->prev = first;

    // second->next = third;
    // third->prev =  second; 

    //     Node* head = first;
    //    Node* tail = third;

    // print(head);
    // cout << endl;
    // insertAtPosition(head,tail,5,22);

    // print(head);

    // ➡️ Section 05: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀
//   👉 delete any Position Linked List

    // Node* first = new Node(10);
    //   Node* second = new Node(30);
    //  Node* third = new Node(40);

    // first->next = second;
    // second->prev = first;

    // second->next = third;
    // third->prev =  second; 

    //     Node* head = first;
    //    Node* tail = third;

    // print(head);
    // cout << endl;
    // deleteAtPosition(head,tail,1);

    // print(head);

        // ➡️ Section 06: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀
//   👉 Reverse Linked List

      Node* first = new Node(10);
      Node* second = new Node(30);
     Node* third = new Node(40);

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev =  second; 

        Node* head = first;
       Node* tail = third;
       

        // Node* prev = NULL;
        // Node* curr = head;
        print(head);
        cout << endl;
    // head = reverse(prev,curr); // output: - 40 30 10
    head = reverseusingLoop(head); // output: - 40 30 10
    print(head);
    
    return 0;
}