#include<iostream>
#include<stack>
#include<vector>
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

// ⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐

// 3️⃣ Celebrity Problem

int celebrity(vector<vector<int> > M, int n){
     
    //step1: create a stack and put in person n
    stack<int> st;
    for(int i = 0; i < n; i++){
          st.push(i);
    }
    
    //step2: check take a and b into stack on top a know b or b know a
    while(st.size() != 1){
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();
        if(M[a][b]){
            // discard a and push b
            st.push(b);
        }else{
            st.push(a);
        }
    }

    // step3: celebrity hai or nahi check st.top() 1 person
    int celebrity = st.top(); st.pop();

// check row is 0, 0, 0, hai or nahi
    for(int i = 0; i < n; i++){
        if(M[celebrity][i] != 0){  // row is 0 ,  0 , 0 nahi hai to woh celebrity nahi hai 
            return -1;
        }
    }
// check col is 1,1,1 expect diagonal is 0 0 0 then middle is (1,1-> 0,1) 0 ko chod kar
    for(int i = 0; i < n; i++){
        // one condition is  M[1][1] == 0 and  1 != 1 , 0 != 1 is i != celebrity, 1 !=1
        if(M[i][celebrity] == 0 && i != celebrity){
           return -1;
        }
    }

  return celebrity;
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

// int celebrity(vector<vector<int> >& M, int n) 

// vector<vector<int> > M{
//     {0, 1, 0},
//     {0, 0, 0},
//     {0, 1, 0}
// };  // output: 1
// int n = 3;
// // vector<vector<int> > M{
// //     {0, 1},
// //     {1, 0},
// // };  // output: -1
// // int n = 2;

// int result = celebrity(M, n);

// cout << result << endl;

// ⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐

// 5️⃣ Next greater element in Linked List [https://leetcode.com/problems/next-greater-node-in-linked-list/description/]

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     vector<int> nextLargerNodes(ListNode* head) {
//         vector<int> ll;
//         while(head){
//            ll.push_back(head->val);
//            head=head->next;
//         }

//         stack<int> st;
//         vector<int> ans(ll.size());
//         for(int i = 0;i < ll.size(); i++){
//             while(!st.empty() && ll[i] > ll[st.top()]){
//                 int kids = st.top(); st.pop();
//                 ans[kids] = ll[i]; 
//             }
//             st.push(i);
//         }
//         return ans;
//     }
// };

// ⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐

// 6️⃣ N Stacks in an Array







}