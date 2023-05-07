#include<iostream>
#include<stack>
using namespace std;

// ➡️ Section 03: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀
//  🏗️ Build own Stack or create stack


// class Stack{
//   private:
//   int top;
//   int *arr;
//   int size;
//   public:
//      Stack(int size){
//         arr = new int[size];
//         this->size = size;
//         top = -1;
//      }
//  void push(int data){
//     // 👉 space available ho (insert)
//       if(size - top > 1){
//          top++;
//          arr[top] = data;
//       }else {
//            // 👉 space not available
//            cout << "Stack Overflow" << endl;
//       }
//   }
//   void pop(){
//     if(top == -1){
//         // 👉 stack is empty
//         cout << "Stack underflow, can't delete element" << endl;
//     }else{
//         // 👉 stack is not empty
//         top--;
//     }
//   }
//   int getTop(){
//      if(top == -1){
//         cout << "There is not Element in Stack" << endl;
//      }else{
//         return arr[top];
//      }
//   }

// // 👉 return number of valid elements present in stack
// int getSize(){
//    return top + 1;
// }

// bool isEmpty(){
//     if(top == -1){
//         return true;
//     }else {
//         return false;
//     }
// }

// };


// ➡️ Section 04: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀

//  🏗️ Build own Stack with two Array

class Stack{
   private:
     int *arr;
     int top1;
     int top2;
     int size;

   public:
     Stack(int size){
      arr = new int[size];
      this->size = size;
      top1 = -1;
      top2 = size;
     }
   
   void push1(int data){

      if(top2 - top1 == 1){
       // 👉 space not available
         cout << "Stack1 is Overflow" << endl;
      }else{
         top1++;
         arr[top1] = data;

      }
   }

   void push2(int data){
      if(top2 - top1 == 1){
         cout << "Stack2 is Overflow" << endl;
      }else{
         top2--;
         arr[top2] = data;
      }
   }

   void pop1(){
      if(top1 == -1){
            // 👉 stack empty
            cout << "Stack1 is UnderFlow" << endl;
         
      }else{
         arr[top1] = 0;
         top1--;
      }
   }

   void pop2(){
      if(top2 == size){
            // 👉 Stack 2 is empty
            cout << "UnderFlow in Stack 2" << endl;
      }else{
         arr[top2] = 0;
         top2++;
      }
   }

   void print(){
      cout << endl;
      cout << "top1: " << top1 << endl;
      cout << "top2: " << top2 << endl;
      for(int i = 0; i < size; i++){
         cout << arr[i] << " ";
      }
      cout << endl;
   }


};

// ➡️ Section 06: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀

// 1️⃣ Question: Print Middle element on stack

void printMiddleElement(stack<int> &s,int &totalsize){
   if(s.size() == 0){
      cout << "There is no element on stack" << endl;
      return;
   }

// base case
   if((totalsize/2) + 1 == s.size()){
      cout<<"Middle element is: "<<  s.top() << endl;
      return;
   }

   int temp = s.top();
   s.pop();

//   recuirsive call
 printMiddleElement(s,totalsize);

//  backtracing
s.push(temp);

}






int main(){

// // 👉 creation
//   stack<int> st;

// // 👉 insertion
//   st.push(10);
//   st.push(20);
//   st.push(30);
//   st.push(40);

// // 👉 remove 
// st.pop();  // output:- remove last element is 40

// // 👉 check Element on top
// cout << "Element on top is: " << st.top() << endl; //output:-30

// // 👉 size
// cout << "Stack size is: " << st.size() << endl; //output:- 3

// 👉 Check empty hai or nahi
// if(st.empty()){
//     cout << "Stack is Empty!" << endl;
// }else{
//     cout << "Stack is not Empty!" << endl; // output:- not empty
// }

// ➡️ Section 02: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀

// stack<int> s;

// s.push(10);
// s.push(20);
// s.push(30);
// s.push(40);
// s.push(50);


// // 👉 printing stack

// while(!s.empty()){
//     cout << s.top() << " "; // output:-50 40 30 20 10 
//     s.pop();
// }
// cout << endl;

// ➡️ Section 03: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀

//  🏗️ Build own Stack or create stack

// Stack s(10);

// s.push(10);
// s.push(20);
// s.push(30);
// s.push(40);
// s.push(50);
// s.push(60);

// s.pop(); // 60 ishme se remove ho jaye ga yani top-- prev = 50 position hogo current = 60 toh left side ko gisaka jayega


// while(!s.isEmpty()){   //output:- 50 40 30 20 10 
//    cout << s.getTop() << " ";
//    s.pop();
// }

// cout << endl;


// cout << "Size of Stack " << s.getSize() << endl; // output:-Size of Stack 0


// s.pop(); //output:- Stack underflow, can't delete element


// ➡️ Section 04: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀

//  🏗️ Build own Stack with two Array

// Stack s(10);

// s.push1(10);
// s.push1(20);
// s.push1(30);
// s.push1(40);
// // s.pop1();
// // s.pop1();
// // s.pop1();
// // s.pop1();
// // s.pop1();
// // s.print();

// s.push2(100);
// s.push2(200);
// s.push2(300);
// s.push2(400);
// s.push2(500);
// // s.pop2();
// // s.pop2();
// // s.pop2();
// // s.pop2();
// // s.pop2();
// // s.pop2();
// s.print();

// ➡️ Section 05: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀

// 1️⃣ Question: Reverse String :- "tiger" 

//👉 Example take :- "sumitkumar" , "elephant" , "apple"
// string str = "tiger";
// // string str = "elephant";
// // string str = "sumitkumar";
// stack<char> s;

// for(int i = 0; i < str.size(); i++){
//     s.push(str[i]);
// }

// while(!s.empty()){
//    cout << s.top() << "";
//    s.pop();
// }
// cout<< endl;


// ➡️ Section 06: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀

// 1️⃣ Question: Print Middle element on stack

stack<int> s;



s.push(10);
s.push(20);
s.push(30);
s.push(40);
s.push(50);
s.push(60);
s.push(70);

int totalSize = s.size();

printMiddleElement(s,totalSize);






}