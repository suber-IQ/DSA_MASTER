#include<iostream>
using namespace std;
class Node{
   public:
   int data;
   Node* next;

   Node(int d){
      data = d;
      next = NULL;
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
int getLength(Node* &head){
      Node* temp = head;
      int count = 0;
      while(temp!=NULL){
         count++;
         temp = temp->next;
      }
      return count;
}

Node* reverseKNode(Node* &head, int k){
     if(head==NULL){
      return head;
     }
     int len = getLength(head);
     if(k > len){
        return head;
     }

      // reverse k node 
      Node* prev = NULL;
      Node* curr = head;
      Node* forward = head->next;
      int count = 0;
      
      // stepB
      while(count < k){
            forward = curr->next;
            curr->next = prev;
           prev = curr;
           curr = forward;
           count++;
      }

      // recursive call
      if(forward != NULL){
            head->next = reverseKNode(forward, k);
      }

      return prev;

}

int main(){
      // Reverse K Node
      Node* head = new Node(10);
Node* second = new Node(20);
Node* third = new Node(30);
Node* fourth = new Node(40);
Node* fifth = new Node(50);
Node* sixth = new Node(60);

head->next = second;
second->next = third;
third->next = fourth;
fourth->next = fifth;
fifth->next = sixth;
sixth->next = NULL;

// print(head);

// head = reverseKNode(head,2);
// print(head);

// testing another question
// int a = 5;
// int b = 5;

// cout << a + "5" - b << endl;

      return 0;
}