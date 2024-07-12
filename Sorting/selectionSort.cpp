#include<iostream>
using namespace std;


void print(int *arr,int n){

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

void selectionSortAce(int *arr,int n){

for(int round = 1; round < n; round++){
  
  for(int i = 0; i < n - 1; ++i){
     int index = i;
     for(int j = i+1; j < n; ++j){
        if(arr[j] < arr[index]){
            index = j;
        }
     }
     swap(arr[index],arr[i]);
  }
}    

}

void selectionSortDesc(int *arr,int n){
    for(int i = n - 1; i > 0; i--){
        int index = i;
        for(int j = i - 1; j >= 0; j--){
            if(arr[j] > arr[index]){
                index = j;
            } 
        }
        swap(arr[index],arr[i]);
    }

}


int main(){

    // 👉 Selection sort Ascending order

    int arr[] = {10,8,2,3,1,4,1};
    int n = 7;

    selectionSortAce(arr,n);


    cout << "Printing Selection sort Ascending order: " << endl;

    print(arr,n);


    // 👉 Selection sort Descending order

    selectionSortDesc(arr,n);

    cout << "\nPrinting Selection sort Descending order: " << endl;
    print(arr,n);


    return 0;
}