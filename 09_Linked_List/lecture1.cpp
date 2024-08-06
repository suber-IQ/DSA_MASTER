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
};

void print(Node* &head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main(){

  Node* first = new Node();
  Node* second = new Node();
  Node* third = new Node();
  Node* fourth = new Node();
  Node* fifth = new Node();

  first->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  print(first);
 
    return 0;
}