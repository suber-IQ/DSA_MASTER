#include<iostream>
using namespace std;


void print(int *arr,int n){

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}


void bubbleSort(int *arr,int n){

for(int i =  n - 2; i >= 0; i--){
    bool isSwapped = 0;
    for(int j = 0; j<= i; ++j){
        if(arr[j] > arr[j+1]){
            swap(arr[j],arr[j+1]);
            isSwapped = 1;
        }
    }
    if(isSwapped == 0){
        break;
    }
}
    
}

void bubbleSortDec(int *arr, int n){
   for(int i =  n - 2; i >= 0; i--){
    bool isSwapped = false;
    for(int j = 0; j<= i; ++j){
        if(arr[j] < arr[j+1]){
            swap(arr[j],arr[j+1]);
            isSwapped = true;
        }
    }
    if(isSwapped == false){
        break;
    }
}
}

void bubbleSortIncFromLast(int *arr, int n){
    //  also may be use this for(int i = 0; i < n; i++) (👉 Extra not required run to last element (beacuse last one element is always sorted) so, use that {n - 1})
     for(int i = 0; i < n - 1; i++){
       bool isSwapped = false;
        for(int j = n - 1; j > i ; --j){
              if(arr[j] < arr[j - 1]){
                 swap(arr[j],arr[j-1]);
                 isSwapped = true;
              }
        }
        if(isSwapped == false) break;
     }
}


int main(){

    // 👉 Selection sort Ascending order

    // int arr[] = {10,8,2,3,1,4,1};
    int arr[] = {1,2,3,4,5,6,7};
    int n = 7;

   bubbleSort(arr,n);
   print(arr,n);


     // 🎉 S.C : Auxiliary: O(1)
     // 🎉 S.C : Total: O(n)

     // 🎉 T.C : O(n^2)  worst case
     // 🎉 T.C : Ω(n^2)  Best case
     // 🎉 T.C : Θ(n^2)  Avg case

//   👉 Bubble sort Decreasing order

cout << "\n Decreasing order of bubble sort: " << endl;
bubbleSortDec(arr,n);

print(arr,n);

//   👉 Bubble sort increasing order from last

cout << "\n Bubble sort increasing order from last: " << endl;
bubbleSortIncFromLast(arr,n);

print(arr,n);

    return 0;
}

