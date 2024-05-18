#include<iostream>
#include<climits>
#include<string>
using namespace std;


int climbStairs(int n){
    // Base case
    if(n == 0 || n == 1) return 1;

    //recursive case
    int ans = climbStairs(n-1) + climbStairs(n-2);
    return ans;
}
void print(int arr[],int n ,int i){
     //base case
     if(i >= n) return;

    // // 1 case solve krdia
    cout << arr[i] << " ";

    //baaki recursion sambhal lega
    print(arr,n,i+1);
     
    // 1 case solve krdia
    // cout << arr[i] << " ";
}

void findMax(int arr[],int n, int i,int& maxi){
    if(i >= n) return;

    if(arr[i] > maxi){
        maxi = arr[i];
    }

    findMax(arr,n,i+1,maxi);


}
void findMin(int arr[],int n, int i,int& mini){
    if(i >= n) return;

    if(arr[i] < mini){
        mini = arr[i];
    }

    findMin(arr,n,i+1,mini);

}

int CheckKeyStr(string& str,int i,int& n,char& key){
     //base case
     if(i >= n) return -1;

     //1 case solve kardo
     if(str[i] == key) return i;

     // baaki recursion smabhal lega
     return CheckKeyStr(str,i+1,n,key);
}

void printDigits(int n){
    //base case
    if(n == 0) return;

   
    int newValueOfN = n/10;
    printDigits(newValueOfN);

     // 1 case solve kardo
    int digit = n % 10;
    cout << digit << " ";

}


int main(){

    // 1️⃣ Find no. of ways to reach nth stair(1 stair at a time, 2 stair at a time)

    // int n;
    // cout << "Enter the stairs value of n: " << endl;
    // cin>>n;

    // int ans = climbStairs(n);
    // cout << "Answer: " << ans << endl;
// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// 2️⃣ print array

    // int arr[5] = {10,20,30,40,50};
    // int n = 5;
    // int i = 0;
    // print(arr,n,i);

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// 3️⃣ find max number of array

// int arr[] = {10,30,21,44,32,17,19,66};
// int n = 8;
// int i = 0;
// int maxi = INT_MIN;

// findMax(arr,n,i,maxi);
// cout << "maximum number is: " <<maxi <<endl;

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// 4️⃣ find minimum number of array

// int arr[] = {10,30,21,44,32,5,17,19,66};
// int n = 9;
// int i = 0;
// int mini = INT_MAX;

// findMin(arr,n,i,mini);
// cout << "minimum number is: " <<mini <<endl;

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// 5️⃣ find key into string

// string str = "Sumitkumar";
// char key = 'a';
// // char key = 'j';
// int i = 0;
// int n = str.length();
// int ans = CheckKeyStr(str,i,n,key);

// cout << "Answer: " << ans << endl;

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// 6️⃣ given a number with print digit into array

int n = 269;
printDigits(n);

    return 0;
}









