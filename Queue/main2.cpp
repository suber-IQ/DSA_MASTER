#include<iostream>
using namespace std;

class CirQueue{
      public:
      int size;
      int *arr;
      int front;
      int rear;

      CirQueue(int size){
            this->size = size;
            arr = new int[size];
            front = -1;
            rear = -1;
      }
      void push(int data){
          // Queue full  
          if(front == 0 && rear == size - 1 && front -  1 == rear){
             cout << "Queue full, cannot insert" << endl;
      //     single element case -> first element 
          }else if(front == -1){
            front = rear = 0;
            arr[rear] = data;
      // circular nature 
          }else if(rear == size - 1 && front != 0){
            rear = 0;
            arr[rear] = data;
      // normal flow 
          }else{
              rear++;
              arr[rear] = data;
          }
      }

      void pop(){
            // empty check 
            if(front == -1){
                  cout << "Empty queue, cannot pop" << endl;
                  // single
            }else if(front == rear){
                     arr[front] = -1;
                     front = -1;
                    rear = -1;
                  //   circular nature
            }else if(front == size - 1){
                  front = 0;
            }else {
                  front++;
            }
      }
};

int main(){



      return 0;
}