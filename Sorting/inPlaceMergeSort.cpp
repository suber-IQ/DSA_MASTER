// 👉  in-place merge sort
#include<iostream>
using namespace std;


void printArr(int *arr, int n){

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

void merge(int *arr,int s, int e, int n){
    int gap = (n / 2) + (n % 2);
    while(gap > 0){
     int i = s, j = s + gap;
       while(j <= e){
         if(arr[i] > arr[j]){
           swap(arr[i],arr[j]);
         }
         i++, j++;
       }
       gap = gap <= 1 ? 0 : (gap / 2) + (gap % 2);
    }
}

void inPlaceMergeSort(int *arr,int s,int e,int n){
    if(s >= e) return;

    int mid = (s + e) >> 1;
    // int mid = s - (e - s)/2;
    inPlaceMergeSort(arr,s,mid,n);
    inPlaceMergeSort(arr,mid+1,e,n);

    merge(arr,s,e,n);

}


int main(){

     int arr[] = {8,2,5,6,2,1,9,4};
    int n = 8;
    int s = 0;
    int e = n - 1;

    inPlaceMergeSort(arr,s,e,n); //output: 1 2 2 4 5 6 8 9

      // 🎉 T.C :  O(nlogn)

    // 🎉 S.C :  O(1)


    printArr(arr,n);



    return 0;
}