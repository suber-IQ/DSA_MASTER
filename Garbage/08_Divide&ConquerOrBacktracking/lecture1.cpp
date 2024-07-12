#include<iostream>
using namespace std;


void merge(int* arr,int s, int e){
    
    int mid = s + (e - s)/2;
    int leftLen = mid - s + 1;
    int rightLen = e - mid;

    // create new array of left and right
    int* leftArr = new int[leftLen];
    int* rightArr = new int[rightLen];

    // copy left and right
    int k = s;
    for(int i = 0; i < leftLen; ++i){
        leftArr[i] = arr[k++];
    }

    k = mid+1;
    for(int i = 0; i < rightLen; ++i){
        rightArr[i] = arr[k++];
    }

    // left and right sorted
    int leftIndex = 0;
    int rightIndex = 0;
    int mainIndex = s;
    while(leftIndex < leftLen && rightIndex < rightLen){
        if(leftArr[leftIndex] < rightArr[rightIndex]){
            arr[mainIndex++] = leftArr[leftIndex++];
        }else{
            arr[mainIndex++] = rightArr[rightIndex++];

        }
    }

    // for leftIndex 
    while(leftIndex < leftLen){
        arr[mainIndex++] = leftArr[leftIndex++];
    }

    while(rightIndex < rightLen){
        arr[mainIndex++] = rightArr[rightIndex++];
    }

   // delete left array and right array

}



void mergeSort(int* arr,int s,int e){

    //base case
    if(s >= e) return;

    //find mid
    int mid = s + (e - s)/2;

    //left part sort
    mergeSort(arr,s,mid);

    //right part sort 
    mergeSort(arr,mid + 1,e);

    //merge two sorted arrays
    merge(arr,s,e);
}

int main(){


// 👉 1️⃣ Merge Sort

int arr[] = {4,5,13,2,3888,88,13,12,5};
int n = 9;

int s = 0;
int e = n - 1;
mergeSort(arr,s,e);


for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
}


// 🎄 T.C = nlogn
// 🎄 S.C = 

// 👉 2️⃣ Quick Sort



    return 0;
}