// 👉  doubly linked list
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
      //TODO: Write a destrcutor to delete a node
        ~Node() {
                //write your code here
                cout << "Node with value: " << this->data << " deleted" << endl;
        }
};

void print(Node* &head){
    Node* temp = head;
    while(temp){ // temp != NULL
        cout << temp->data << " ";
        temp = temp->next;
    }

}

int getLen(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp){ // temp != NULL
        temp = temp->next;
        len++;
    }
    return len;
}


void insertAtHead(Node* &head, Node* &tail, int data){
        //step 1
        Node* newNode = new Node(data);
     if(head == NULL){
        head = newNode;
        tail = newNode;
     }else{
        //step 2
        newNode->next = head;
        //step 3
        head->prev = newNode;
        //step 4
        head = newNode;
     }


}

void insertAtTail(Node* &head, Node* &tail, int data){
    // step 1
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }else{
        // step 2
        tail->next = newNode;
        // step 3
        newNode->prev = tail;
        // step 4
        tail = newNode;
    }
}

void insertAtPos(int pos, Node* &head, Node* &tail, int data){

    // step 1
    Node* newNode = new Node(data);

    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    if(pos <= 0){
        insertAtHead(head,tail,data);
        return;
    }
    int len = getLen(head);
    if(pos > len){
        insertAtTail(head,tail,data);
        return;
    }
    // step 2: 
    int i = 1;
    Node* prevs = head;
    while(i < pos - 1){
        prevs = prevs->next;
        i++;
    }
    Node* currs = prevs->next;
    // step 3: 
    prevs->next = newNode;
    // step 4: 
    newNode->prev = prevs;
    // step 5:
    newNode->next = currs;
    // step 6:
    currs->prev = newNode;
}


void deleteAtPos(int pos, Node* &head, Node* &tail){
     if(head == NULL){
        cout << "Linked list is empty" << endl;
        return;
     }
     if(head->next == NULL){
        //single node
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
     }
     int len = getLen(head);
     if(pos > len || pos < 1){
        cout << "Please enter valid position" << endl;
        return;
     }
    

     if(pos == 1){
        // want to delete the first node
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
     }
     if(pos == len){
        Node* temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        delete temp;
        return;
     }

     //delete from middle Node

     // step1: find left,curr,right
     int i = 1;
     Node* left = head;
     while(i < pos - 1){
        left = left->next;
        i++;
     }
     Node* curr = left->next;
     Node* right = left->next->next; //also use: curr->next;

    // step2:
     left->next = right;
    // step3:
    right->prev = left;
    curr->prev = NULL;
    curr->next = NULL;
    delete curr;


}

int main(){

    // Node* first = new Node(10);
    // Node* second = new Node(20);
    // Node* third = new Node(30);

    // first->next = second;
    // second->prev = first;

    // second->next = third;
    // third->prev = second;

    // print(first);

// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟
    // 👉 insert At Head

    // Node* head = NULL;
    // Node* tail = NULL;
    //  int data;
    // for(int i = 1; i <= 10; ++i){
    //    data = 10 * i;
    //    insertAtHead(head,tail,data);
    // }

    // print(head);

// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟
    // 👉 insert At Tail

    // Node* head = NULL;
    // Node* tail = NULL;
    //  int data;
    // for(int i = 1; i <= 5; ++i){
    //    data = 10 * i;
    //    insertAtTail(head,tail,data);
    // }

    // print(head);
// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟
    // 👉 insert At Tail

    // Node* head = NULL;
    // Node* tail = NULL;
   
    // insertAtTail(head,tail,10);
    // insertAtTail(head,tail,20);
    // insertAtTail(head,tail,30);
    // insertAtTail(head,tail,40);
    // insertAtTail(head,tail,50);

    // int pos = 5; 
    // insertAtPos(pos,head,tail,111);
    // print(head);
// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟
    // 👉 Delete at Position

    // Node* head = NULL;
    // Node* tail = NULL;
   
    // insertAtTail(head,tail,10);
    // insertAtTail(head,tail,20);
    // insertAtTail(head,tail,30);
    // insertAtTail(head,tail,40);
    // insertAtTail(head,tail,50);

    // int pos = 0; 
    // deleteAtPos(pos,head,tail);
    // print(head);

    // 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟
    // 👉 Reverse Node using recusive doubly linked list

    



    return 0;
}