// 👉 Char Array and String
#include<iostream>
#include<string.h>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

string RemoveDuplicates(string str){
    int i = 0;
    string ans = "";
    while(i <= str.length() - 1){
       if(ans.length() > 0){
            if(ans[ans.length() - 1] == str[i]){
            ans.pop_back();
         }else{
            ans.push_back(str[i]);
         }
       }else{
            ans.push_back(str[i]);
       }
         i++;
    }
   return ans;
}

string removeOccurrences(string str,string part){
      // int pos = str.find(part);
      // while(pos != string::npos){
      //       str.erase(pos,part.length());
      //       pos = str.find(part);
      // }
      // return str;

      int pos;
      while((pos = str.find(part)) != string::npos){
            str.erase(pos,part.length());
      }
      return str;
}

bool checkPalindrome(string word,int i,int j){
      while(i <= j){
            if(word[i] != word[j]){
                  return false;
            }else{
                  i++;
                  j--;
            }
      }
      return true;

}

bool validPalindrome(string str){
      int i = 0;
      int j = str.length() - 1;

      while(i <= j){
            if(str[i] != str[j]){
                  return checkPalindrome(str,i+1,j) || checkPalindrome(str,i,j-1);
            }else{
                  i++;
                  j--;
            }
      }
      return true;
}


int minimumDiff(vector<string>& timePoints){
      vector<int> minutes;

     // step 1: convert into minutes      
      for(int i = 0; i < timePoints.size(); ++i){
            string cur = timePoints[i];
            
            int hour = stoi(cur.substr(0,2));
            int minu = stoi(cur.substr(3,2));
            int totalminutes = hour*60 + minu;
            minutes.push_back(totalminutes);
      }

      // step 2: sort
      sort(minutes.begin(),minutes.end());

      // step 3: min difference
      int n = minutes.size();
      int mini = INT_MAX;
      for(int i = 0; i < n - 1; ++i){
            int diff = minutes[i+1] - minutes[i];
            mini = min(mini, diff);
      }

      // One step more with (23:59- 00:00)(something missing)
       int lastDiff = (minutes[0] + 1440) - minutes[n-1];
       mini = min(mini,lastDiff);

      return mini;
}

int expandAroundIndex(string s,int i,int j){
      int count = 0;
   while(i >= 0 && j < s.length() && s[i] == s[j]){
      count++;
      i--;
      j++;
   }
   return count;
}

int palindromSubstrings(string str){
      int count = 0;
      int n = str.length();
      for(int i =0; i<n; ++i){
      // step 1: odd
             int oddKaAns = expandAroundIndex(str,i,i);
             count = count + oddKaAns;
      // step 1: even
             int evenKaAns = expandAroundIndex(str,i,i+1);

             count = count + evenKaAns;

      }
      return count;
}

int main(){

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 8️⃣ Remove All Adjacent duplicates in string

// string str = "abbaca"; 
// string str = "azxxzy";

// string result = RemoveDuplicates(str);
// cout << result << endl;

// 🎉 Space complexity: O(1)
// 🎉 Time complexity: O(n)

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 9️⃣ Remove all Occurrences of a Substring 

// string str = "daabcbaabcbc"; // 🎉output:- "dab"
// string part = "abc";


// string result = removeOccurrences(str,part);
// cout << result << endl;


// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 1️⃣0️⃣ Valid Palindrome II

// string str = "aba"
// string str = "abca";
// // string str = "abcak";

// if(validPalindrome(str)){
//       cout << "Valid Palindrome" << endl;
// }else{
//       cout << "Not Valid Palindrome" << endl;
// }

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 1️⃣1️⃣  Minimum Time Difference

// vector<string> str = {"23:59","00:00"};


// cout << "Min: " << minimumDiff(str) << endl;



// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 1️⃣2️⃣  Palindromic Substrings[leetcode]

// string str = "abc"; // 🎉 output:- 3
string str = "aaa"; // 🎉 output:- 6

cout << "count: " << palindromSubstrings(str) << endl;










  return 0;
  
}