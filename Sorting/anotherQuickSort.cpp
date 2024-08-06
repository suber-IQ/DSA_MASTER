#include<iostream>
using namespace std;
void printArr(int *arr, int n){

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}


void quickSort(int *arr,int start,int end){
    if(start >= end) return;


    int pivot = end;
    int i = start - 1;
    int j = start;


    while(j < pivot){
        if(arr[j] < arr[pivot]){
            ++i;
            swap(arr[i],arr[j]);
        }
        ++j;
    }
    ++i;
    swap(arr[i],arr[pivot]);
    quickSort(arr,start,i-1);
    quickSort(arr,i+1,end);
}


int main(){

     int arr[] = {8,2,5,6,2,1,9,4};
    int n = 8;
    int s = 0;
    int e = n - 1;


    quickSort(arr,s,e);


    printArr(arr,n);


    return 0;
}
