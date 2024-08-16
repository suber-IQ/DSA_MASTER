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
    cout << endl;
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

Node* findMiddle(Node* &head){
    if(head == NULL){
        cout << "LL is Null" << endl;
        return head;
    }
    if(head->next == NULL){
        return head;
    }

    Node* slow = head;
    // Node* fast = head;
    Node* fast = head->next;

    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL){
          fast = fast->next;
          slow = slow->next;
        }
    }
    return slow;
}

Node* reverseKNode(Node* &head, int k){
    if(head == NULL){
        cout << "L.L is empty" << endl;
        return head;
    }
    int len = findLength(head);
    if(k>len){
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;


    int i = 0;
    while(i < k && curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        i++;
       
    }

    if(forward != NULL){
        head->next = reverseKNode(forward,k);
    }
    return prev;
}

// bool isCircularLL(Node* &temp){

// }

bool checkLoop(Node* &head){
    if(head == NULL){
        cout << "LL is empty" << endl;
        return false;
    }
  
    // slow & fast approach 
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        //loop present
        if(slow == fast){
             return true;
        }
    }
    //loop not present
    return false;

}
Node* startingPointLoop(Node* &head) {
        if(head == NULL) {
                cout << "LL is empty "<< endl;
                return NULL;
        }

        Node* slow = head;
        Node* fast = head;

        while(fast != NULL) {
                fast = fast -> next;
                if(fast != NULL) {
                        fast = fast -> next;
                        slow = slow -> next;
                }

                if(slow == fast ) {
                       slow = head;
                       break;
                }
        }

        while(slow != fast) {
                slow = slow -> next;
                fast =fast -> next;
        }

        return slow;
        

}
Node* removeLoop(Node* &head) {
        if(head == NULL) {
                cout << "LL is empty "<< endl;
                return NULL;
        }

        Node* slow = head;
        Node* fast = head;

        while(fast != NULL) {
                fast = fast -> next;
                if(fast != NULL) {
                        fast = fast -> next;
                        slow = slow -> next;
                }

                if(slow == fast ) {
                       slow = head;
                       break;
                }
        }

        Node* prev = fast;
        while(slow != fast) {
                prev = fast;
                slow = slow -> next;
                fast =fast -> next;
        }
        prev -> next = NULL;
        return slow;
}


int main(){



// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

//   ❓ 13. Find Middle of Linked List

// Node* head = new Node(10);
// Node* first = new Node(20);
// Node* second = new Node(30);
// Node* third = new Node(40);
// Node* fourth = new Node(50);
// Node* fifth = new Node(60);

// head->next = first;
// first->next = second;
// second->next = third;
// third->next = fourth;
// fourth->next = NULL;
// // fifth->next = NULL;

// print(head);

// cout << "After get Middle: " << endl;

// cout << findMiddle(head)->data << endl;
// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

//   ❓ 14. Reverse K node  

// Node* head = new Node(10);
// Node* first = new Node(20);
// Node* second = new Node(30);
// Node* third = new Node(40);
// Node* fourth = new Node(50);
// Node* fifth = new Node(60);

// // 👉 condition 1
// // head->next = NULL;
// // 👉 condition 2
// // head = NULL;

// // 👉 condition 3
// head->next = first;
// first->next = second;
// second->next = third;
// third->next = fourth;
// fourth->next = NULL;
// // fifth->next = NULL;

// print(head);

// int k = 4;
// head = reverseKNode(head,k);

// cout << "After result: " << endl;
// print(head);

// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

//   ❓ 15. Is Circular Linked List check true or false

//🎏 Method: 1 pointer approach, slow/fast approach, help with map 

// Node* head = new Node(10);
// Node* first = new Node(20);
// Node* second = new Node(30);
// Node* third = new Node(40);
// Node* fourth = new Node(50);
// Node* fifth = new Node(60);

// // 👉 condition 1
// // head->next = NULL;
// // 👉 condition 2
// // head = NULL;

// // 👉 condition 3
// head->next = first;
// first->next = second;
// second->next = third;
// third->next = fourth;
// fourth->next = fifth;
// fifth->next = head;


// bool result = isCircularLL(head);

// cout << "After result: " << result << endl;

// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

//   ❓1. check loop present or not on Linked List 
//  **Detect & Delete Loop (8 Method solve this approach )**

// Node* head = new Node(10);
// Node* first = new Node(20);
// Node* second = new Node(30);
// Node* third = new Node(40);
// Node* fourth = new Node(50);
// Node* fifth = new Node(60);
// Node* sixth = new Node(70);
// Node* seventh = new Node(80);
// Node* eighth = new Node(90);


// head->next = first;
// first->next = second;
// second->next = third;
// third->next = fourth;
// fourth->next = fifth;
// fifth->next = sixth;
// sixth->next = seventh;
// seventh->next = eighth;
// eighth->next = fifth;
// // eighth->next = NULL;


// bool result = checkLoop(head);

// cout << "After result: " << result << endl;


// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

// //   ❓2.  starting point Loop on Linked List

// Node* head = new Node(10);
// Node* first = new Node(20);
// Node* second = new Node(30);
// Node* third = new Node(40);
// Node* fourth = new Node(50);
// Node* fifth = new Node(60);
// Node* sixth = new Node(70);
// Node* seventh = new Node(80);
// Node* eighth = new Node(90);


// head->next = first;
// first->next = second;
// second->next = third;
// third->next = fourth;
// fourth->next = fifth;
// fifth->next = sixth;
// sixth->next = seventh;
// seventh->next = eighth;
// eighth->next = fifth;
// // eighth->next = NULL;

// cout << "Starting Point of LOOP is: " << startingPointLoop(head) -> data << endl;

// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

//   ❓3. Remove Loop on L.L

// Node* head = new Node(10);
// Node* first = new Node(20);
// Node* second = new Node(30);
// Node* third = new Node(40);
// Node* fourth = new Node(50);
// Node* fifth = new Node(60);
// Node* sixth = new Node(70);
// Node* seventh = new Node(80);
// Node* eighth = new Node(90);


// head->next = first;
// first->next = second;
// second->next = third;
// third->next = fourth;
// fourth->next = fifth;
// fifth->next = sixth;
// sixth->next = seventh;
// seventh->next = eighth;
// eighth->next = fifth;
// // eighth->next = NULL;

// removeLoop(head);
// print(head);

// cout << "Loop is Present or not " << checkLoop(head) << endl;



    return 0;
}