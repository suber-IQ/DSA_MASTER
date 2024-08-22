#include<iostream>
#include<stack>
#include<string>
using namespace std;

void printStack(stack<int> &st){
  while(!st.empty()){
    cout << st.top() << " ";
    st.pop();
   }
   cout << endl;
}


void insertAtBottom(stack<int> &s,int target){
     //base case
      if(s.empty()){
        s.push(target);
        return;
      }

      int topElement = s.top();
      s.pop();

      //rec call
      insertAtBottom(s,target);
      //B.T
      s.push(topElement);
}
void reverseStack(stack<int> &s){
    if(s.empty()){
        return;
    }

    //A step (top like topElement)
    int topElement = s.top();

    // B Step
    s.pop();

    // C step
    reverseStack(s);

    // D step
    insertAtBottom(s,topElement);
}


bool vaildParenth(string str){
   stack<char> st;
   
   for(int i = 0; i < str.length(); i++){
      char ch = str[i];
      if(ch == '{' || ch == '(' || ch == '['){
         st.push(ch);
      }else{
         if(!st.empty()){
                if(ch == '}' && '{' == st.top()){
                 st.pop();
            }else if(ch == ')' && '(' == st.top()){
                 st.pop();
            }else if(ch == ']' && '[' == st.top()){
                 st.pop();
            }else{
              return false;
            }
         }else{
          return false;
         }
          
      }
   }

  if(!st.empty()){
    return false;
  }else{
    return true;
  }
}

void insertSorted(stack<int>& st, int target){
    if(st.empty()){
      st.push(target);
      return;
    }

    if(target <= st.top()){
        st.push(target);
        return;
    }

    int topElement = st.top();
    st.pop();

    //Recursion
    insertSorted(st, target);

    // B.T
    st.push(topElement);
}

void sortStack(stack<int> &st){
      if(st.empty()){
        return;
      }

      int topElement = st.top();
      st.pop();
      
      // recursion
       sortStack(st);

       //B.T
       insertSorted(st,topElement);
}



int main(){

//  ❓ 7. Insert At bottom

// stack<int> st;
// st.push(10);
// st.push(20);
// st.push(30);
// st.push(40);
// st.push(50);

//  if(st.empty()){
//         cout << "Stack is empty, Can't insert at bottom" << endl;
//     }
//     int target = st.top();
//     st.pop();

// insertAtBottom(st,target);

// while(!st.empty()){
//     cout << st.top() << " ";
//     st.pop();
// }

// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

// ❓ 8. Reverse Stack 

// stack<int> st;
// st.push(10);
// st.push(20);
// st.push(30);
// st.push(40);
// st.push(50);


// reverseStack(st);

// printStack(st);

// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

// ❓ 9. Vaild Parentheses [Leetcode] 

// string str = "{()}";
// string str = "[";

// bool result = vaildParenth(str);

// if(result){
//   cout << "string is valid parenthese: " << endl;
// }else{
//   cout << "string is not valid parenthese: " << endl;

// }


// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

// ❓ 10. Sort a Stack


stack<int> st;
st.push(20);
st.push(30);
st.push(5);
st.push(80);
st.push(7);


sortStack(st);

printStack(st);


    return 0;
}