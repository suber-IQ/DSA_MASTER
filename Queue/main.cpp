#include<iostream>
using namespace std;


class Queue{
      public:
      int *arr;
      int size;
      int front;
      int rear;

      Queue(int size){
         this->size = size;
         arr = new int[size];
         front = 0;
         rear = 0;
      }
      void push(int data){
            if(rear == size){
                  cout << "Queue is full!" << endl;
            }else{
                  arr[rear] = data;
                  rear++;
            }
      }

      void pop(){
            if(front == rear){
                  cout << "Queue is Empty" << endl;
            }else{
                  arr[front] = -1;
                  front++;
                  if(front == rear){
                        front = 0;
                        rear= 0;
                  }
            }
      }
      int getFront(){
            if(front == rear){
                  cout << "Queue is Empty" << endl;
                  return -1;
            }else{
                  return arr[front];
            }
      }

      bool isEmpty(){
            if(front == rear){
                  return true;
            }else{
                  return false;
            }

      }
      int getSize(){
            return rear - front;
      }


};

int main(){
      Queue q(10);

      q.push(5);
      q.push(10);
      q.push(20);
      q.push(30);

      cout << "size of Queue is: " << q.getSize() << endl;
      q.pop();
      cout << "size of Queue is: " << q.getSize() << endl;
      cout << "Front element is: " << q.getFront() << endl;

      if(q.isEmpty()){
            cout << "Queue is empty" << endl;
      }else{
            cout << "Queue is not empty!" << endl;
      }


      return 0;
}