// 👉 Char Array and String
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

int getLength(char name[]){
      int length = 0;
      int i = 0;
      while(name[i] != '\0'){
            length++;
            i++;
      }
      return length;
}

void reverseCharArray(char name[]){
      int i =0;
      int n = getLength(name);
      int j = n - 1;

      while(i<=j){
            swap(name[i], name[j]);
            i++;
            j--;
      }
}

void replaceSpaces(char sentence[]){
      int i = 0;
      int n = strlen(sentence);
      for(int i = 0; i < n; i++){
            if(sentence[i] == ' '){
                  sentence[i]= '@';
            }
      }
}

bool checkPalindrome(char word[]){
      int i =0;
      int n = strlen(word);
      int j =n - 1;
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

void convertUppercase(char arr[]){
      int n = strlen(arr);
      for(int i =0; i < n; ++i){
            arr[i] = arr[i] - 'a' + 'A';
      }
}
void convertLowercase(char arr[]){
      int n = strlen(arr);
      for(int i =0; i < n; ++i){
            arr[i] = arr[i] - 'A' + 'a';
      }
}

bool compareString(string a,string b){
      if (a.length() != b.length())
            return false;
      for(int i =0; i<a.length();++i){
            if(a[i] != b[i]){
                  return false;
            }
      }
      return true;
}

int main(){

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ Introduction

// char ch[100];
// cout << "Enter Your Name" << endl;
// cin >> ch;

// cout << "Aapka naam: " << ch << " hai" << endl;

// char ch[100];
// ch[0]='a';
// ch[1]='b';

// cin>>ch[2];

// cout << ch[0] << ch[1] << ch[2] << endl;


// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠
// 👉 verify last block of null(null ASCII value = 0)

// char name[100];
// cin>>name;

// for(int i = 0; i < 6; i++){
//       cout << "index: " << i << "Value: " << name[i] << endl;
// }

// int value = (int) name[6];
// cout << value << endl;

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠


// char name[100];

// cout << "Enter full name: " << endl;
// cin>>name;

// for(int i = 0; i < 100; i++){
//       cout << name[i];
// }

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// char arr[100];
//   cin.getline(arr,50);
  
//   cout << arr;

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// char arr[100];

// cin>> arr[2];
// cin>>arr[49];
// cin>>arr;

// cout << arr;;
// cout << arr[2];
// cout << arr[49];

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 1️⃣ Length of Sting

// char name[100];

// cout << "Enter name: " << endl;
// cin>>name;

// cout << "length: " << getLength(name) << endl;
// cout << "Length: " << strlen(name) << endl;

// 🎉 Space complexity: O(1)
// 🎉 Time complexity: O(n)


// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 2️⃣ Reverse of Sting

// char name[100];
// cout << "Reverse character name: " << endl;
// cin>>name;
//    reverseCharArray(name);
//    cout << name <<endl;

// 🎉 Space complexity: O(1)
// 🎉 Time complexity: O(n)


// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 3️⃣ Replace space with '@'

// char sentence[100];
// cin.getline(sentence, 100);

// replaceSpaces(sentence);

// cout << "printing sentence: " << sentence << endl;

// 🎉 Space complexity: O(1)
// 🎉 Time complexity: O(n)

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 4️⃣ Palindrome

// char word[100] = "race";
// char word[100] = "racecar";
// char word[100] = "lol";
// cout << "palindrome check: " << checkPalindrome(word) << endl;

// 🎉 Space complexity: O(1)
// 🎉 Time complexity: O(n)


// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 5️⃣ uppercase convert

// char arr[100] = "sumit";
// convertUppercase(arr);
// cout << arr << endl;

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 6️⃣ lowercase convert

// char arr[100] = "SUMIT";
// convertLowercase(arr);
// cout << arr << endl;

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ Intro string

// string str;
// // cin>>str;
// getline(cin,str);
// cout << str << endl;

// cout << "length: " << str.length() << endl;
// cout << "empty: " << str.empty() << endl;

// str.push_back('A');
// cout << str << endl;
// str.pop_back();
// cout << str<< endl;
// cout << str.substr(0,4) << endl;

// 👉 compare()


// string a = "Hand";
// string b = "Hand";
// // string b = "hand";
// // string b = "Handle";

// if(a.compare(b) == 0){
//       cout << "a and b are exactly same strings" << endl;
// }else{
//       cout << "a and b are not same strings" << endl;
// }

// 👉 find()
// string sentance = "hello world welcome to our channel";
// string target = "hello";
// string target = "world";
// string target = "cold"; // 🎉ouput:- 18446744073709551615(garbage valule if not match)

// cout << sentance.find(target) << endl;

// 👉 replace()

// string str = "This is my First Message";
// string word = "Sumit";

// str.replace(0,4,word); //🎉 output:- Sumit is my First Message
// cout << str << endl;

// 👉 erase()

string str = "This is an example sentence";

str.erase(10,8); //🎉 output:- This is an sentence

cout << str << endl;


//  🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 7️⃣ compare string function

// string a = "Hand";
// string b = "Hand";
// string b = "Handle";

// cout << "compare: " << compareString(a,b) << endl;

  return 0;
  
}