#include<iostream>
#include<vector>
using namespace std;

bool isSorted(int arr[],int i,int& n){
    //   base case 
    if(i == n - 1 || n == 0) return true;

    if(arr[i] <= arr[i + 1]){
        return isSorted(arr,i+1,n);
    }else {
        return false;
    }
}
int binarySearch(vector<int>& arr,int s,int e,int key){
    int mid = s + (e - s)/2;
    //base case
    //case 1 -> key not found
    if(s > e) return -1;
    //case 2-> key found
    if(arr[mid] == key){
        return mid;
    }

    // arr[mid] < key -> right me search
    // if(arr[mid] < key){
    //     return binarySearch(arr,mid+1,e,key);
    // }else{
    // // arr[mid] > key -> left me search
    //     return binarySearch(arr,s,mid-1,key);

    // }

    // use with ternary operator 
    return (arr[mid] < key) ? binarySearch(arr,mid+1,e,key) : binarySearch(arr,s,mid-1,key);

}



void printSubsequences(string str,string output,int i,vector<string>& v){
    // base case
    if(i == str.length()){
        v.push_back(output);
        return;
    }



        // exclude
        printSubsequences(str,output,i+1,v);

        //include
        output.push_back(str[i]);
        printSubsequences(str,output,i+1,v);
        // printSubsequences(str,output+str[i],i+1,v);
    
}
int main(){

// 1️⃣ check if array is sorted or not sorted
    //  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    //  int arr[] = {10,20,30,40,50,60};
    //  int arr[] = {10,20,40,30,60,50};
    //  int arr[] = {10};
    //  int arr[] = {};

    // int n = sizeof(arr) / sizeof(arr[0]);  // Correct way to get the array length
    // int i = 0;
    // cout << (isSorted(arr, i, n) ? "Sorted" : "Not Sorted") << endl;

// 2️⃣ Binary Search

// vector<int> arr{10,20,30,40,50,60,70,80,99};
// int target = 40;
// int n = arr.size();
// int s = 0;
// int e = n - 1;
// int ans = binarySearch(arr,s,e,target);

// cout << "Answer is: " << ans << endl;

// 3️⃣ Subsequences of a string

string str = "xyz";
string output = "";
int i = 0;
vector<string> v;

printSubsequences(str,output,i,v);


// print all vector string
for(auto val: v){
    cout << val << " ";
}

cout << endl;

// length of vector string
cout <<"size of string vector: " << v.size() << endl;



    return 0;
}