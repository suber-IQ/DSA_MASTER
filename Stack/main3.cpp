#include<iostream>
#include<stack>
#include<vector>
#include<limits.h>
using namespace std;


class MinStack {
public:
    vector<pair<int,int>> st;
    
    void push(int val) {
        if(st.empty()){
            pair<int,int> p;
            p.first = val;
            p.second = val;
            st.push_back(p);
        }else{
            pair<int,int> p;
            p.first = val;
            p.second = min(val,st.back().second);
            st.push_back(p);
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
         return st.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int vaildParentheses(string s){
    stack<int> st;
    st.push(-1);
    int maxLen = 0;

    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        if(ch == '('){
            st.push(i);
        }else{
            st.pop();
            if(st.empty()){
               st.push(i);
            }else{
                int len = i - st.top();
                maxLen = max(len,maxLen);
            }

        }
    }
    return maxLen;
}


// 5️⃣ Question: Largest Rectangular Area in Histogram

vector<int> prevSmallerElement(vector<int>& input) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(input.size());

        //left to right -> prev smaller
        for(int i=0; i<input.size(); i++) {
                int curr = input[i];

                //apka answer stack me 
                while(s.top() != -1 && input[s.top()] >= curr) {
                        s.pop();
                }

                //chotta element mil chuka h -> ans store
                ans[i] = s.top();

                //push krdo curr element ko
                s.push(i);
        }
        return ans;
}

vector<int> nextSmaller(vector<int> &input) {
  stack<int> s;
  s.push(-1);
  
  vector<int> ans(input.size());

  for(int i=input.size()-1; i>=0; i--) {
          int curr = input[i];

          //apka answer stack me 
          while(s.top() != -1 && input[s.top()] >= curr) {
                  s.pop();
          }

          //chotta element mil chuka h -> ans store
          ans[i] = s.top();

          //push krdo curr element ko
          s.push(i);
  }
  return ans;
}

int getRectangularAreaHistogram(vector<int> &height) {

        //step1: prevSmaller output
        vector<int> prev = prevSmallerElement(height);

        //step2: nextSmaller call
        vector<int> next = nextSmaller(height);

        int maxArea = INT_MIN;
        int size = height.size();

        for(int i=0; i<height.size(); i++) {
                int length = height[i];
                
                if(next[i] == -1) {
                        next[i] = size;
                }

                int width = next[i] - prev[i] - 1;

                int area = length * width;
                maxArea = max(maxArea, area);
        }

        return maxArea;
}


int main(){

      // ➡️ Section 01: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀

// 1️⃣ Question:  Min Stack


    // MinStack s;
    // s.push(4);
    // s.push(1);
    // s.push(5);
    // s.push(3);
    // s.push(400);

    // cout << "min value of Stack s " << s.getMin() << endl;

// ➡️ Section 02: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀

// 2️⃣ Question:  Longest Valid Parentheses

// string s = "))))))))))";
// string s = "))))()";

// cout << s << " is MaxLength: " << vaildParentheses(s) << endl;

// ➡️ Section 03: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀

// 3️⃣ Question:Next Smaller Element


// vector<int> s;

// s.push_back(1);
// s.push_back(3);
// s.push_back(4);
// s.push_back(2);

// stack<int> st;
// st.push(-1);

// vector<int> ans(s.size());

// for(int i = s.size() - 1; i >= 0; i--){
//     int curr = s[i];
//     while(st.top() >= curr){
//         st.pop();
//     }
//     ans[i] = st.top();
//     st.push(curr);

// }

// cout << "printing " << endl;
// for(int i = 0; i < ans.size(); i++){
//     cout << ans[i] << " ";
// }

// ➡️ Section 04: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀

// 4️⃣ Question:Prev Smaller Element

// vector<int> prev;
// prev.push_back(2);
// prev.push_back(1);
// prev.push_back(4);
// prev.push_back(3);

// stack<int> st;
// st.push(-1);

// vector<int> ans(prev.size());
// for(int i = 0; i < prev.size(); i++){
//     int curr = prev[i];
//     while(st.top() >= curr){
//         st.pop();
//     }
//     ans[i] = st.top();
//     st.push(curr);
// }

// cout << "printing " << endl;
// for(int i = 0; i < ans.size(); i++){
//     cout << ans[i] << " ";
// }



// ➡️ Section 05: 🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀🧀

// 5️⃣ Question: Largest Rectangular Area in Histogram

vector<int> s;

s.push_back(2);
s.push_back(1);
s.push_back(5);
s.push_back(6);
s.push_back(2);
s.push_back(3);

cout << getRectangularAreaHistogram(s) << endl;


    return 0;
}