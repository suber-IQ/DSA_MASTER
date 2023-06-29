#include<iostream>
#include<queue>
#include<stack>

using namespace std;

void reverse(queue<int>& q){
      stack<int> st;

      while(!q.empty()){
            int element = q.front();
            q.pop();
            st.push(element);
      }

      while(!st.empty()){
            int element = st.top();
            st.pop();

            q.push(element);

      }
}

void reverseRecursive(queue<int>& q){
      // base case 
      while (q.empty())
      {
           return;
      }

      // step 1
      int temp = q.front();
      q.pop();
      
      // step 2
      reverseRecursive(q);

      // step 3
      q.push(temp);
}

void reverseKelement(queue<int>& q,int& k){
     
      stack<int> st;
      int n = q.size();
      int count = 0;
       if(k <= 0 || k > n){
            return;
      }

while(!q.empty()){
      int element = q.front();
      q.pop();
      st.push(element);
      count++;

      if(count == k){
            break;
      }
}
    
      
      // step 2
      while(!st.empty()){
            int element = st.top();
            st.pop();
            q.push(element);
      }


      // step 3 
      count = 0;
     while(!q.empty() && n - k != 0){
       int element = q.front();
       q.pop();
       q.push(element);
       count++;
      if(count == n - k){
       break;
      }
     }


}


int main(){
//       queue<int> q;
//       q.push(5);
//       q.push(6);
//       q.push(2);
//       q.push(1);
//       q.push(8);

// reverse(q);
// cout << "reverse Queue with help of stack" << endl;
//      while(!q.empty()){
//       cout << q.front() << " ";
//       q.pop();
//      }
//      cout << endl;

// //🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀
// //  🏗️ Reverse queue with recusively
//      queue<int> qt;
//       qt.push(5);
//       qt.push(6);
//       qt.push(2);
//       qt.push(1);
//       qt.push(8);

// reverseRecursive(qt);
// cout << "reverse Queue with help of Recursive" << endl;
//      while(!qt.empty()){
//       cout << qt.front() << " ";
//       qt.pop();
//      }
//      cout << endl;

//🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀
//  🏗️ Reverse First k element of Queue
      queue<int> q;
      q.push(5);
      q.push(6);
      q.push(2);
      q.push(1);
      q.push(8);

      // 5, 6 ,2 ,1,8 :- k = 3  output:- 2 6 5 1 8
int k = 3;
reverseKelement(q,k);
cout << "reverse First k element of Queue" << endl;
     while(!q.empty()){
      cout << q.front() << " ";
      q.pop();
     }
     cout << endl;



      return 0;
}