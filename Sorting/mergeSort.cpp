#include<iostream>
#include<vector>
using namespace std;


void printArr(int *arr, int n){

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

 void merge(int arr[], int s, int m, int e)
    {
         // Your code here
         vector<int> temp (e - s + 1);
         int index = 0; int left = s; int right = m+1;
         
         // merge two array (like A & B)
         while(left <= m && right <= e){
             if(arr[left] <= arr[right]){
                 temp[index++] = arr[left++];
             }else{
                 temp[index++] = arr[right++];
             }
         }
         
         //remeaining more element of two array A & B
         while(left <= m){
             temp[index++] = arr[left++];
         }
         while(right <= e){
             temp[index++] = arr[right++];
         }
         
         //transfer temp element into arr
         index = 0;
         while(s <= e){
             arr[s++] = temp[index++];
         }
         
    }
    void mergeSort(int arr[], int s, int e)
    {
        //code here
        if(s == e) return;
        
        int m = s + (e - s)/2;
        
        //divide array of two part
        mergeSort(arr,s,m);
        mergeSort(arr,m+1,e);
        
        merge(arr,s,m,e);
    }


int main(){

    // 👉 Merge Sort 

    int arr[] = {8,2,5,6,2,1,9,4};
    int n = 8;
    int s = 0;
    int e = n - 1;


    mergeSort(arr,s,e);

    // 🎉 T.C :  O(nlogn)

    // 🎉 S.C :  O(n)


    printArr(arr,n);

    return 0;

}