// 👉 Char Array and String
#include<iostream>
#include<string>
#include<climits>
#include<algorithm>
#include<map>
#include<array>
#include<vector>
using namespace std;


bool validAnagram(string s,string t){
      if(s.length() != t.length()) return false;
      sort(s.begin(),s.end());
      sort(t.begin(),t.end());
      return s == t;
}

bool validAnagram1(string s,string t){
    if(s.length() != t.length()) return false;
    int freqTable[256] = {0};
    for(int i=0;i<s.length();++i){
         freqTable[s[i]]++;
    }
    for(int i=0;i<t.length();++i){
         freqTable[t[i]]--;
    }

    for(int i = 0; i < 256; ++i){
      if(freqTable[i] != 0){
            return false;
      }
    }
    return true;
}

string reverseLetters(string s){
      int l = 0;
      int h = s.length() - 1;

      while(l<=h){
            if(isalpha(s[l]) && isalpha(s[h])){
                  swap(s[l],s[h]);
                  l++;
                  h--;
            }else if(!isalpha(s[l])){
                  l++;
            }else{
                  h--;
            }
      }
      return s;

}

bool isCharater(char ch){
      if((ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90)){
            return true;
      }
      return false;
}

string reverseLetters1(string s){
      int l = 0;
      int h = s.length() - 1;

      while(l<=h){
            if(isCharater(s[l]) && isCharater(s[h])){
                  swap(s[l],s[h]);
                  l++;
                  h--;
            }else if(!isCharater(s[l])){
                  l++;
            }else{
                  h--;
            }
      }
      return s;

}
string longestCommonPrefix(vector<string> str){
      string ans;
      int i = 0;
      while(true){
            char cur_ch = 0;
            for(auto s : str){
                  if(i >= s.size()){
                        cur_ch = 0;
                        break;
                  }
                  if(cur_ch == 0){
                        cur_ch = s[i];
                  }else if(s[i] != cur_ch){
                     cur_ch = 0;
                     break;
                  }
            }
            if(cur_ch == 0){
                  break;
            }
            ans.push_back(cur_ch);
            i++;
      }
      return ans;
}

bool isVowel(char ch) {
    ch = std::tolower(ch); // Convert character to lowercase for case insensitivity
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
string reverseVowels(string s){
      int l = 0;
      int h = s.length() - 1;

      while(l<=h){
            if(isVowel(s[l]) && isVowel(s[h])){
                  swap(s[l], s[h]);
                  l++;
                  h--;
            }else if(!isVowel(s[l])){
                  l++;
            }else{
                  h--;
            }
      }
      return s;
}

bool isomorphic(string s,string t){
      int hashSMap[256] = {0};
        bool hashTMap[256] = {0};

        for(int i = 0; i < s.length(); i++){
            if(hashSMap[s[i]] == 0 && hashTMap[t[i]] == 0){
                hashSMap[s[i]] = t[i];
                hashTMap[t[i]] = true;
            }
        }

        for(int i = 0; i < s.length(); i++){
            if(char(hashSMap[s[i]]) != t[i]){
                return false;
            }
        }
        return true;
}

string reorganizeString(string s){
      int hash[26] = {0};
      
      for(int i = 0; i < s.length(); ++i){
            hash[s[i] - 'a']++;
      }

      //find the most frequent char
      char max_freq_char;
      int max_freq = INT_MIN;

      for(int i = 0; i < 26; ++i){
            if(hash[i] > max_freq){
                  max_freq = hash[i];
                  max_freq_char = i + 'a';
            }
      }

      int index = 0;
      while(max_freq > 0 && index < s.size()){
            s[index] = max_freq_char;
            max_freq--;
            index += 2;
      }

      if(max_freq != 0){
            return "";
      }
      hash[max_freq_char - 'a'] = 0;

      // let's place the rest of the characters
      for(int i = 0; i < 26; ++i){
            while(hash[i] > 0){
                  index = index >= s.size() ? 1 : index;
                  s[index] = i + 'a';
                  hash[i]--;
                  index += 2;
            }
      }

      return s;

}

// vector<vector<string>> groupAnagrams(vector<string> &strs){

//      map<string,vector<string> >mp;

//      for(auto str : strs){
//            string s = str;
//            sort(s.begin(), s.end());
//            mp[s].push_back(str);
//      }

//      vector<vector<string>>ans;
//       for(auto it = mp.begin(); it != mp.end(); ++it){
//             ans.push_back(it->second);
//       }
//       return ans;
// }



std::array<int, 256> calculateHash(const std::string& s) {
    std::array<int, 256> hashe = {0};
for(int i = 0; i < s.length(); ++i){
      hashe[s[i]]++;
}
    return hashe;
}

std::vector<std::vector<std::string>> groupAnagrams1(std::vector<std::string>& strs) {
    std::map<std::array<int, 256>, std::vector<std::string>> mp;

    // Group anagrams
    for (auto& str : strs) {
        mp[calculateHash(str)].push_back(str);
    }

    // Prepare the result
    std::vector<std::vector<std::string>> ans;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        ans.push_back(it->second);
    }

    return ans;
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
string longestPalindromicSubstring(string s){
       string ans = "";
       for(int i = 0; i < s.length(); ++i){
            for(int j = i; j < s.length(); ++j){
                  if(checkPalindrome(s,i,j)){
                      string t = s.substr(i,j - i + 1);
                      ans = t.size() > ans.size() ? t : ans;
                  }
            }
       }
       return ans;
}

int firstOccurenceString(string haystack, string needle){
      int n = haystack.length();
      int m = needle.length();
      for(int i = 0; i <= n-m; ++i){
            for(int j = 0; j < m; ++j){
                  if(needle[j] != haystack[i+j]){
                        break;
                  }
                  if( j == m - 1){
                        return i;
                  }
            }
      }
      return -1;
}

int main(){


// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓1️⃣ Valid Anagram

// string s = "anagram";
// string t = "nagaram";

// string s = "rat";
// string t = "car";

// cout << validAnagram(s,t) << endl;
// cout << validAnagram1(s,t) << endl;

// 🎉 Space complexity: O(1)
// 🎉 Time complexity: O(n)

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓2️⃣ Reverse only letters

// string s = "a-bC-dEf-ghIj"; // 🎉 output:- j-Ih-gfE-dCba
// string s = "ab-cd"; // 🎉 output:- dc-ba
// string s = "Test1ng-Leet=code-Q!"; // 🎉 output:- Qedo1ct-eeLg=ntse-T!


// cout << reverseLetters(s)<< endl; // 🎉 Method 1
// cout << reverseLetters1(s)<< endl; // 🎉 Method 2

// 🎉 Space complexity: O(1)
// 🎉 Time complexity: O(n)



// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 3️⃣ Longest common Prefix

// vector<string> str{"flower","flow","flight"};

// cout << longestCommonPrefix(str) << endl;

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 4️⃣ Reverse Vowels of a String

// string s= "hello";


// cout << reverseVowels(s) << endl;


// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 5️⃣ Isomorphic Strings

// string s = "egg";
// string t = "add";

// string s= "foo";
// string t = "bar";

// string s= "badc";
// string t = "baba";

// cout << isomorphic(s,t) << endl;

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 6️⃣ Reorganize Strings

// string s = "aab";
// string s = "aaab";

// cout << reorganizeString(s) << endl;


// 🎉 Space complexity: O(n)
// 🎉 Time complexity: O(n)

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 7️⃣ Group Anagrams

// vector<string> strs = {"eat","tea","tan","ate","nat","bat"}; // 🎉 output:-  [["bat"],["nat","tan"],["ate","eat","tea"]]
// vector<string> strs{""}; // 🎉 output:- [[""]]
// vector<string> strs{"a"};// 🎉 output:- [["a"]]

// vector<vector<string> > results = groupAnagrams(strs);
// vector<vector<string> > results = groupAnagrams1(strs);

// for(auto group: results){
//       for(auto str: group){
//             cout << str << " ";
//       }
//       cout <<endl;
// }


// 🎉 Space complexity: O(nk)
// 🎉 Time complexity: O(nklogk)

// groupAnagrams1

// 🎉 Space complexity: O(nk)
// 🎉 Time complexity: O(nk)



// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 8️⃣ Longest Palindromic Substring

// string s = "babad"; // 🎉 output:- "bab"
// string s = "cbbd"; // 🎉 output:- "bb"

// cout << longestPalindromicSubstring(s) << endl;


// 🎉 Time complexity: O(n3)

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 9️⃣ Find The index of first Occurence in a string

// string h = "sadbutsad";
// string n = "sad";

// cout <<  firstOccurenceString(h,n) << endl;

// 🎉 Time complexity: O(mn)

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 1️⃣0️⃣ String to Integer(atoi)

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 1️⃣1️⃣ String compression


      return 0;
}