#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;


int minimumBracketReversal(string s){
    // string ka size odd hai to 
    if(s.size() & 1){
        return -1;
    }

    // stack created
    stack<char> st;
    int ans = 0;

    // String operation
    for(auto ch:s){
        if(ch == '{'){
            st.push(ch);
        }else{
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }else{
                st.push(ch);
            }
        }
    }

    while(!st.empty()){
        char a = st.top(); st.pop();
        char b = st.top(); st.pop();
        if(a == b) ans += 1;
        else ans += 2;
    }
    return ans;
}

// ⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐

// 2️⃣ Remove All Adjacent Duplicates in String (Leetcode)

string removeAdjacentDuplicateString(string s){
    stack<char> st;
    for(auto ch:s){
        if(!st.empty() && st.top() == ch){
            st.pop();
        }else{
            st.push(ch);
        }
    }

    string ans;
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

   reverse(ans.begin(),ans.end());

   return ans;

}

int main(){

    
// 1️⃣ Minimum Bracket Reversal
// string s = "}{{}}{{{"; // output: 3
// string s = "{{}{{{}{{}}{{"; // size is odd output: -1
// string s = "{{}{{{}{{}}{{}"; // output: 2

// int result = minimumBracketReversal(s);
// cout << s << " : " << result << endl;

// ⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐

// 2️⃣ Remove All Adjacent Duplicates in String (Leetcode)
// string s = "asfddsa"; // output: asfsa
// string s = "abbaca"; // output: ca

// string result = removeAdjacentDuplicateString(s);

// cout << s << " : " << result << endl;

// ⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐

// 3️⃣ Celebrity Problem



}