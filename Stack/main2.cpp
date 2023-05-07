#include<iostream>
#include<stack>
using namespace std;

// 👉 Section 01 (Insert At bottom)

void save(stack<int> &s, int &targetElement){
  // base case
    if(s.empty()){
        s.push(targetElement);
        return;
    }

  // step 2:
    int tempElement = s.top();
    s.pop();

    // recursive call 
    save(s,targetElement);

    // backtracing
    s.push(tempElement);

}

void insertBottom(stack<int> &s){
  if(s.empty()){
   cout << "Stack on no element, can't insert element on bottom" << endl;
  }

  int topElement = s.top();
  s.pop();

  save(s,topElement);
}

// 👉Section 02 (Reverse Stack)

void reverseStack(stack<int> &s){
  //  Base case
  if(s.empty()){
    return;
  }

  // target element
  int targetElement = s.top();
  s.pop();

  // reverse stack
  reverseStack(s);

  // insert at bottom (save function is a insertbottom ka function hai )
   save(s,targetElement);
}


// 3️⃣ Question: Section 3 ( Vaild Parentheses)


bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i <s.length(); i++){
            char ch = s[i];
              // 👉 opening bracket
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }else{
              // 👉  closing bracket
                if(!st.empty()){
                    char topCh = st.top();
                    if(ch == ')' && topCh == '('){
                      // 👉 matching brackets
                        st.pop();
                    }
                    else if(ch == '}' && topCh == '{'){
                        st.pop();

                    }
                    else if(ch == ']' && topCh == '['){
                         st.pop();
                    }else{
                     // 👉 bracket not matching
                        return false;
                    }

                }else{
                    return false;
                }
            }
        }

           // 👉Check Stack is empty hai to return true kar dena
      return st.empty();

    }


// 4️⃣ Question:  Seaction 4(Sort Stack)

    void insertSorted(stack<int> &s, int &targetElement){
      if(s.empty()){
        s.push(targetElement);
        return;
      }

      if(s.top() >= targetElement){
        s.push(targetElement);
        return;
      }
      
      int targetTop = s.top();
      s.pop();

      insertSorted(s,targetElement);

    // BT
      s.push(targetTop);

    }

    void sortStack(stack<int> &s){
      // Base case
       if(s.empty()){
        return;
       }
      
      int targetTop = s.top();
      s.pop();

      sortStack(s);

     insertSorted(s,targetTop);
    }


int main(){

  // ➡️ Section 01: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀

// 1️⃣ Question:  Insert At bottom

//   stack<int> s;

//   s.push(10);
//   s.push(20);
//   s.push(30);
//   s.push(40);
//   s.push(50);

  
//  insertBottom(s);  


//  cout << "Printing " << endl;
//  while(!s.empty()){
//     cout << s.top() << " ";
//     s.pop();
//  }

  // ➡️ Section 02: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀

// 2️⃣ Question:  Reverse Stack

// stack<int> s;

// s.push(10);
// s.push(20);
// s.push(30);
// s.push(40);
// s.push(50);

// reverseStack(s);

// while(!s.empty()){
//    cout << s.top() << " ";
//    s.pop();
// }

  // ➡️ Section 03: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀

// 3️⃣ Question:  Vaild Parentheses

    // string s = "()"; //output: true
    // string s = "{}";  //output: true
    // string s = "[]"; //output: true
    // string s = "[{}]";//output: true
    // string s = "[{)]"; //output: false
    // string s = "[}";  // output : false
    // string s = "({)}";  // output : false


//  if(isValid(s)){
//   cout << s << " true" << endl;
//  }else {
//   cout<< s << " false" << endl;
//  }

// ➡️ Section 04: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀

// 4️⃣ Question:  Sort Stack

// stack<int> s;

// s.push(100);
// s.push(10);
// s.push(40);
// s.push(220);
// s.push(60);
// s.push(20);
// s.push(30);

// sortStack(s);

// while(!s.empty()){
//   cout << s.top() << " ";
//   s.pop();
// }
// cout << endl;


// ➡️ Section 05: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀

// 5️⃣ Question: Remove Redundant Brackets

}