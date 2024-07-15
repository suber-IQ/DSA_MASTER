#include<iostream>
using namespace std;


void printArr(int *arr,int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

void insertionSort(int *arr,int n){
    for(int i = 1; i <= n - 1; i++){
        for(int j = i;  j > 0; j--){
            if(arr[j] < arr[j - 1]){
                swap(arr[j],arr[j - 1]);
            }else{
                break;
            }
        }
    }
}

void decSort(int *arr,int n){

 for(int i = 1; i <= n - 1; i++){
        for(int j = i;  j > 0; j--){
            if(arr[j] > arr[j - 1]){
                swap(arr[j],arr[j - 1]);
            }else{
                break;
            }
        }
    }
}

void IncSortFromLast(int *arr,int n){

 for(int i = n - 2; i >= 0; i--){
    for(int j = i; j < n - 1; j++){
        if(arr[j] > arr[j + 1]){
            swap(arr[j],arr[j+1]);
        }
    }
 }
}

int main(){

    // int arr[] = {7,4,2,3,5};
    int arr[] = {8,2,5,9,10};
    int n = 5;

    // insertionSort(arr,n);

    // printArr(arr,n);

    // 🎉 T.C :  O(n^2)
    // 🎉 T.C : Ω(n)  Best case
     // 🎉 T.C : Θ(n^2)  Avg case

    // 🎉 S.C :  O(1)


    // 👉 //Q ->  Insertion sort(decreasing)

    // decSort(arr,n);
    // printArr(arr,n);

    // 👉 //Q ->  Insertion sort(Increasing) (start from last)

    IncSortFromLast(arr,n);
    printArr(arr,n);





    // 👉 HomeWork
        //Q ->  Insertion sort(decreasing)
            //   3 1 2 4 5
             //  5 4 3 2 1

        //Q ->  Insertion sort(Increasing)
                  // i            
    //round1   7 5 2 4 3
                 //  | start from here  
    //round2   7 5 2 |3  4
                // i
    //round3   7 5 2 |3  4
            //7  2 |5 3  4
            //7  2 |3 5  4
            //7  2 |3 4  5  
               //i
  //round4    7  2 |3 4  5  
            //2  7  3 4  5  
            //2  3  7 4  5  
            //2  3  4 7  5  
            //2  3  4 5  7  


            //2  3  4 5 7 (sorted)



    return 0;
}