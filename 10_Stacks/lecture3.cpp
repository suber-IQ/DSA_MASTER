#include<iostream>
#include<stack>
#include<vector>
using namespace std;


// 👉 12. Min Stack [leetcode]
class MinStack{
    public:
     vector<pair<int,int>> st;
     
    void push(int val){
        if(st.empty()){
            pair<int,int> p = make_pair(val,val);
            st.push_back(p);
        }else{
            pair<int,int> p;
            p.first = val;
            p.second = min(val,st.back().second);
            st.push_back(p);
        }
    }

    void pop(){
        st.pop_back();
    }

    int top(){
        return st.back().first;
    }
    int getMin(){
      return st.back().second;
    }

};

int longestValidParentheses(string s) {
      
        int maxLen = 0;
        stack<int> st;
        st.push(-1);

        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    int len = i - st.top();
                    maxLen = max(maxLen,len);
                }
            }
        }
        return maxLen;
    }





int main(){
//  ❓ 13. Longest Vaild Parentheses [leetcode]
string str = "()()())(";

 int result = longestValidParentheses(str);
cout << "longest valid parentheses: " << result << endl;

// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟


    return 0;
}