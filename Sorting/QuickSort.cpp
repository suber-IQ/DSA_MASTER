#include<iostream>
#include<vector>
using namespace std;


void printArr(int *arr, int n){

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

 int partition(int arr[], int s, int e)
    {

        int pos = 0;
        for(int i = 0; i <= e; i++){
            if(arr[i] <= arr[e]){
                swap(arr[i], arr[pos++]);
            }
        }
        return pos - 1;
         
    }
    void quickSort(int arr[], int s, int e)
    {
        //code here
        if(s >= e) return;

        int pivot = partition(arr,s,e);        
        
        quickSort(arr,s,pivot-1);        
        quickSort(arr,pivot,e);        
    }


int main(){

    // 👉 Quick Sort 

    int arr[] = {8,2,5,6,2,1,9,4};
    int n = 8;
    int s = 0;
    int e = n - 1;


    quickSort(arr,s,e);


    printArr(arr,n);

    // 🎉 T.C :  O(n^2)
     // 🎉 T.C : Θ(nlogn)  Avg case

    // 🎉 S.C :  O(n^2)
    // 🎉 S.C :  Θ(logn)



    return 0;
}