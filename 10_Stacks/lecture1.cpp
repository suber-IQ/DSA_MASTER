#include<iostream>
#include<stack>
using namespace std;

// class Stack{
//     private:
//     int size;
//     int *arr;
//     int top;
//     public:
//     Stack(int size){
//         arr = new int[size];
//         this->size = size;
//         this->top = -1;
//     }
//     void push(int data){
//         if((size - top) > 1){
//             //space available
//             top++;
//             arr[top] = data;
//         }else{
//             // space not available
//             cout << "Stack is overflow!" << endl;
//         }
//     }
//     void pop(){
//         if(top == -1){
//             // stack is empty
//             cout << "Stack is underflow!" << endl;
//         }else{
//             // stack is not empty
//             top--;
//         }
//     }
//     int getTop(){
//         if(top == -1){
//             cout << "there is not element at top!" << endl;
//             return -1;
//         }else{
//             return arr[top];
//         }
//     }
//     // return number of valid elements present in stack:
//     int getSize(){
//         return top+1;
//     }

//     bool isEmpty(){
//         if(top == -1){
//             return true;
//         }else{
//             return false;
//         }
//     }
// };

class Stack{
    private:
    int size;
    int *arr;
    int top1;
    int top2;
    public:
    Stack(int size){
        arr = new int[size];
        this->size = size;
        this->top1 = -1;
        this->top2 = size;
    }
    void push1(int data){
        if((top2 - top1) == 1){
            cout << "Stack1 is overflow!" << endl;
        }else{
            top1++;
            arr[top1] = data;
        }
    }
    void pop1(){
        if(top1 == -1){
            // stack empty
            cout << "Stack1 is underflow!" << endl;
        }else{
            // stack is not empty
            arr[top1] = 0;
            top1--;
        }
    }
    void push2(int data){
        if((top2 - top1) == 1){
            cout << "Stack2 is overflow!" << endl;
        }else{
            top2--;
            arr[top2] = data;
        }
    }
    void pop2(){
        if(top2 == size){
            // stack empty
            cout << "Stack2 is underflow!" << endl;
        }else{
            // stack is not empty
            arr[top2] = 0;  
            top2++;
        }
    }

    // not write this print func
    void print(){
        cout << endl;
        cout << "Top1: " << top1 << endl;
        cout << "Top2: " << top2 << endl;
        for(int i = 0; i < size; i++){
            cout << arr[i] <<  " ";
        }
        cout << endl;
    }
    
};


void printMiddle(stack<int>& s, int &totalSize){
    if(s.size() == 0){
        cout << "there is no element in stack" << endl;
        return;
    }
    //base case
    if(s.size() == (totalSize/2 + 1)){
        cout << "Middle elements:  " << s.top() << endl;
        return;
    }

    int temp = s.top();
    s.pop();

  
    //recusive call
    printMiddle(s,totalSize);

    //backtrack
    s.push(temp);
}

int main(){


//❓ 1. Basic Operations (push,pop,top,empty,size)


//     stack<int> st;

//    st.push(10);
//    st.push(20);
//    st.push(30);
//    st.push(40);
//    st.push(50);

//    st.pop(); // remove 50 

//    // stack on top element
//    cout << "Top element of STack: " << st.top() << endl;

//    // size of stack
//    cout << "Now Stack size: " << st.size() << endl;

//    if(st.empty()){
//     cout << "Stack is empty!" << endl;
//    }else{
//     cout << "Stack is not empty!" << endl;
//    }

// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟
//❓ 2. Print stack elements

// stack<int> st;
// st.push(10);
// st.push(20);
// st.push(30);
// st.push(40);


// while(!st.empty()){
//     cout << st.top() << " ";
//     st.pop();
// }


// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

// ❓ 3. Create Stack from scratch with help(array or linked list)

// Stack st(10);

// st.push(20);
// st.push(30);
// st.push(40);
// st.push(50);
// st.push(60);


// while(!st.isEmpty()){
//     cout << st.getTop() << " ";
//     st.pop();
// }

// cout << "\nSize of stack elements: " << st.getSize() << endl;



// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

// ❓  4. Two stack in an Array(single array)

// Stack st(10);

// st.push1(10);
// st.print();
// st.push1(20);
// st.print();
// st.push1(30);
// st.print();
// st.push1(40);
// st.print();


// st.push2(500);
// st.print();
// st.push2(400);
// st.print();
// st.push2(300);
// st.print();
// st.push2(200);
// st.print();
// st.push2(100);
// st.print();
// st.push2(10000);
// st.print();

// // st.push2(999); // stack2 is overflow!
// st.push1(50);  // stack1 is overflow!

// st.pop2();
// st.print();
// st.pop2();
// st.print();
// st.pop2();
// st.print();
// st.pop2();
// st.print();
// st.pop2();
// st.print();
// st.pop2();
// st.print();


// st.pop2();  // Stack2 is underflow!
// st.print();


// st.pop1();  
// st.print();
// st.pop1();  
// st.print();
// st.pop1();  
// st.print();
// st.pop1();  
// st.print();

// st.pop1();  // stack1 is underflow!
// st.print();



// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

// ❓  5. Reverse String :- "tiger" 

//    string str = "tiger";
//  stack<char> st;

//    for(int i = 0; i < str.length(); i++){
//        st.push(str[i]);
//    }

//     //reverse
//     while(!st.empty()){
//         cout << st.top() << " ";
//         st.pop();
//     }
//     cout << endl;
// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

// ❓  6. Print Middle element on stack(without removing element)  {20,30,40,50,60} ↪️ Output:- 40 

   stack<int> st;
   st.push(10);
   st.push(20);
   st.push(30);
   st.push(40);  // middle element(40)
   st.push(50);
   st.push(60);
   st.push(70);

   int totalSize = st.size();

   printMiddle(st,totalSize);


    return 0;
}