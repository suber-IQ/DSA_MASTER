#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printVector(vector<int> &arr){
      for(int i = 0; i < arr.size(); ++i){
           cout << arr[i] << " ";
      }
}

void selectionSort(vector<int> &arr){
     for(int i = 0; i < arr.size() - 1; ++i){
        int minIndex = i;
        for(int j = i + 1; j < arr.size(); ++j){
            if(arr[j] < arr[minIndex]){
                  // new minimum
                  minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
     }
}

void bubbleSort(vector<int> &arr){
      for(int round = 1; round < arr.size(); ++round){
            bool swapped = false;
            for(int j = 0; j < arr.size() - round; ++j){
                  if(arr[j] > arr[j + 1]){
                        swapped = true;
                        swap(arr[j],arr[j + 1]);
                  }
            }
            if(swapped == false){
                  // sort ho chuka hai, no need to check in further rounds
                  break;
            }
      }
}

void insertionSort(vector<int> &arr){
      for(int round = 1; round < arr.size(); ++round){
            //step A - fetch
            int value = arr[round];
            //stepB: Compare
            int j = round - 1;
            for( ;j >= 0; --j){
                  if(arr[j] > value){
                        //step C: shift
                        arr[j + 1] = arr[j];
                  }else{
                        //rukna hai
                        break;
                  }
            }
            // stepD: copy
            arr[j + 1] = value;
      }
}


int main(){


// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓1️⃣ Selection Sort

// vector<int> arr{5,4,3,2,1};

// selectionSort(arr);

// 🎉 T.C :- O(n2)
// 🎉 S.C :- O(1)

// printVector(arr);

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓2️⃣ Bubble Sort

// vector<int> arr{10,1,7,6,14,9};

// bubbleSort(arr);
// 🎉 T.C :- O(n) :- best case(with sorted array)
// 🎉 T.C :- O(n2) :- worst case
// 🎉 S.C :- O(1)

// printVector(arr);

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓3️⃣ Insertion Sort

//   vector<int> arr{10,1,7,6,14,9};

//   insertionSort(arr);

// 🎉 T.C :- O(n) :- best case(with sorted array)
// 🎉 T.C :- O(n2) :- worst case
// 🎉 S.C :- O(1)


//   printVector(arr);











      return 0;
}