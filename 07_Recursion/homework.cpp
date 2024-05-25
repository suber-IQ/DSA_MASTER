#include<iostream>
using namespace std;


void lastOccLTR(string& s,char x, int i,int& ans){
    //base case
    if(i >= s.size()) return;

    //ek case solution
    if(s[i] == x){
        ans = i;
    }
    lastOccLTR(s,x,i+1,ans);
      
}

void lastOccRTL(string& s,char x, int i,int& ans){
    //base case
    if(i < 0) return;

    //ek case solution
    if(s[i] == x){
        ans = i;
        return;
    }
    //RE
    lastOccRTL(s,x,i-1,ans);
      
}
void reverse(string& s,int start,int end){
    //base case
    if(start >= end) return;

    //ek case
    swap(s[start],s[end]);
  
  //baki recursion sambhal lega
    reverse(s,start+1,end-1);

}
void addRE(string& num1,int p1,string& num2,int p2,string& ans,int carry = 0){
        //base case
        if( p1 < 0 && p2  < 0){
            if(carry != 0){
                ans.push_back(carry + '0');
            }
            return;
        }

        //ek case solve
        int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';
        int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';
        int csum = n1 + n2 + carry;
        int digit = csum % 10;
        carry = csum /10;
        ans.push_back(digit + '0');

        //RE
          addRE(num1,p1 - 1,num2, p2 - 1,ans,carry);
}

string addStrings(string num1,string num2){
    string ans = "";
    addRE(num1,num1.size() - 1, num2, num2.size() - 1,ans);
   reverse(ans,0,ans.size() - 1);
   return ans;
}

bool isPalindrome(string& s,int start,int end){
    //base case
    if(start >= end) return true;

    //one case solution
    if(s[start] != s[end]){
        return false;
    }

    return isPalindrome(s,start+1,end-1);
}

int main(){

    //  1️⃣ Last Occurence of a char (RF)

    // string s = "abcddedg";
    // char x;
    // cout << "Enter a character: " << endl;
    // cin>>x;
    // int ans = -1;
    // int n = s.size();
    // int i = n - 1;
    // lastOccLTR(s,x,i,ans);
    // cout << "answer: " << ans << endl;
    // lastOccRTL(s,x,i,ans);
    // cout << "answer: " << ans << endl;

    // T.C = O(n)
    // S.C = O(n)

     //  2️⃣ Reverse a string RE
    //  string s = "sumit";
    //  int n = s.size();
    //  int start = 0;
    //  int end = n - 1;
    //  reverse(s,start,end);
    //  for(auto val:s){
    //     cout << val << " ";
    //  }

     // T.C = O(n)
    // S.C = O(n)

       //  3️⃣ *Add Strings R.E
    //    string num1 = "456";
    //    string num2 = "77";

    //    string result =  addStrings(num1,num2);
    //    cout << "Answer: " << result << endl;

        // T.C = O(n)
    // S.C = O(n)

       //  4️⃣ *Palindrome check (RE)
    //    string s = "racecar";
       string s = "sumit";

       cout << isPalindrome(s,0,s.size()-1) << endl;

    // T.C = O(n)
    // S.C = O(n)


    return 0;
}