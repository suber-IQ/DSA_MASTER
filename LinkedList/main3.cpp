#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int d){
            this->data = d;
            this->next = NULL;
    }

};


void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* getMiddle(Node* &head){
    if(head==NULL){
         cout<<"LL is empty"<<endl;
         return head;
    }
    if(head->next == NULL){
        return head;
    }

    // LL have > 1 Node
    Node* slow = head;
    Node* fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int getLength(Node* &head){
    Node* temp = head;
    int len = 0;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

Node* reverseKNode(Node* &head, int k){
    if(head==NULL){
        return head;
    }
    int len = getLength(head);
    if(k > len){
        return head;
    }

    // reverse k Node

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = head->next;
    int count = 0;

    while(count < k){
       forward = curr->next;
       curr->next = prev;
       prev = curr;
       curr = forward;
       count++;
    }
    // recursively call
    if(forward != NULL){
     head->next = reverseKNode(curr, k);
    }
 
    // step C:
    return prev;
}


bool checkLoopPresentOrNot(Node* &head){
    if(head==NULL){
        cout << "LL is empty" << endl;
        return false;
    }
    Node* slow = head;
    Node* fast = head;
    
    while(fast->next!=NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}

int startingPointLoop(Node* &head){
    if(head==NULL){
        cout << "LL is empty" << endl;
        return -1;
    }
    Node* slow = head;
    Node* fast = head;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = head;
            break;
        }
    }
    // slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
}
// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟
//4️⃣ Remove Loop on L.L

Node* removeLoop(Node* &head){
     if(head == NULL){
        return head;
        cout << "LL is empty" << endl;
     }
     Node* slow = head;
     Node* fast = head;

     while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = head;
            break;
        }
     }

    Node* prev = fast;
    while (slow != fast)
    {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }
    prev->next = NULL;
    return slow;
    
}





int main() {
//     🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟
//   1️⃣ Find Middle of Linked List // :- Time Complexity O(n/2);


// Node* head = new Node(10);
// Node* second = new Node(20);
// Node* third = new Node(30);
// Node* fourth = new Node(40);    
// Node* fifth = new Node(50);
// Node* sixth = new Node(60);


// head->next = second;
// second->next = third;
// third->next = fourth;
// fourth->next = fifth;
// fifth->next = sixth;
// sixth->next = NULL;

// print(head);

// cout << "Middle Node is: " << getMiddle(head)->data << endl;

// head = getMiddle(head);

// cout << head->data << endl;

//🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟
//2️⃣ Reverse K node // :- Time Complexity O(n/2);


// Node* head = new Node(10);
// Node* second = new Node(20);
// Node* third = new Node(30);
// Node* fourth = new Node(40);
// Node* fifth = new Node(50);
// Node* sixth = new Node(60);

// head->next = second;
// second->next = third;
// third->next = fourth;
// fourth->next = fifth;
// fifth->next = sixth;
// sixth->next = NULL;

// print(head);

// head = reverseKNode(head,3);

// print(head);

//🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟
//3️⃣ check loop present or not on Linked List 

// Node* head = new Node(10);
// Node* second = new Node(20);
// Node* third = new Node(30);
// Node* fourth = new Node(40);
// Node* fifth = new Node(50);
// Node* sixth = new Node(60);
// Node* seventh = new Node(70);
// Node* eigth = new Node(80);
// Node* ninth = new Node(90);
// Node* tenth = new Node(100);
// Node* eleventh = new Node(110);

// head->next = second;
// second->next = third;
// third->next = fourth;
// fourth->next = fifth;
// fifth->next = sixth;
// sixth->next = seventh;
// seventh->next = eigth;
// eigth->next = ninth;
// ninth->next = tenth;
// tenth->next = eleventh;
// eleventh->next = sixth;

// // cout << checkLoopPresentOrNot(head) << endl;
// if(checkLoopPresentOrNot(head)){
//     cout << "Loop present on L.L" << endl;
// }else{
//     cout << "Loop not present on L.L" << endl;
// }

//🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟
//4️⃣ starting point Loop on Linked List 
// Node* head = new Node(10);
// Node* second = new Node(20);
// Node* third = new Node(30);
// Node* fourth = new Node(40);
// Node* fifth = new Node(50);
// Node* sixth = new Node(60);
// Node* seventh = new Node(70);
// Node* eigth = new Node(80);
// Node* ninth = new Node(90);
// Node* tenth = new Node(100);
// Node* eleventh = new Node(110);

// head->next = second;
// second->next = third;
// third->next = fourth;
// fourth->next = fifth;
// fifth->next = sixth;
// sixth->next = seventh;
// seventh->next = eigth;
// eigth->next = ninth;
// ninth->next = tenth;
// tenth->next = eleventh;
// eleventh->next = fifth;

// cout << "starting point Loop on L.L: " << startingPointLoop(head) << endl;

//🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟
//5️⃣Remove Loop on L.L
Node* head = new Node(10);
Node* second = new Node(20);
Node* third = new Node(30);
Node* fourth = new Node(40);
Node* fifth = new Node(50);
Node* sixth = new Node(60);
Node* seventh = new Node(70);
Node* eigth = new Node(80);
Node* ninth = new Node(90);
Node* tenth = new Node(100);
Node* eleventh = new Node(110);

head->next = second;
second->next = third;
third->next = fourth;
fourth->next = fifth;
fifth->next = sixth;
sixth->next = seventh;
seventh->next = eigth;
eigth->next = ninth;
ninth->next = tenth;
tenth->next = eleventh;
eleventh->next = fifth;

removeLoop(head);
print(head);



    return 0;
}