#include<iostream>
using namespace std;

int partision(int* arr,int s,int e){

   int pivotIndex = s;
   int pivotElement = arr[s];

  //right position of pivotIndex
  int count = 0;
  for(int i = pivotIndex + 1; i <= e; ++i){
      if(pivotElement >= arr[i]){
         count++;
      }
  } 

  //jab main loop se bahar hua, toh mere paas pivot ki right position ka index ready h 
  int rightIndex = s + count;
  swap(arr[pivotIndex],arr[rightIndex]);
  pivotIndex = rightIndex;

   //Step3: left me chote and right me bade
   int i = s;
   int j = e;

  while( i < pivotIndex && j > pivotIndex) {
    if(arr[i] <= pivotElement) {
      i++;
    }
    if( arr[j] > pivotElement){
      j--;
    }

    //2 case ho sakte h -> 
    //A-> you found the elements to swap
    //B-> no need to swap
    if(i < pivotIndex && j > pivotIndex)
      swap(arr[i],arr[j]);
   
  }
  return pivotIndex;



}

void quickSort(int* arr,int s,int e){
    //base case
    if(s >= e) return;

    //place pivotIndex 
    int pivotIndex = partision(arr,s,e);

    //left and right part sorting
    quickSort(arr,s,pivotIndex-1);

    quickSort(arr,pivotIndex + 1,e);
}


void printPermutation1(string str,int i){
    //base case
    if(i >= str.length()){
        cout << str<< " ";
        return;
    }

    //swapping
    for(int j = i; j<str.length(); j++){
        //swap
        swap(str[i],str[j]);

        //rec call
        printPermutation1(str,i+1);

        //backtracking
        // swap(str[i],str[j]);
        
    }
    // abc acb bac bca cba cab
}
void printPermutation2(string& str,int i){
    //base case
    if(i >= str.length()){
        cout << str<< " ";
        return;
    }

    //swapping
    for(int j = i; j<str.length(); j++){
        //swap
        swap(str[i],str[j]);

        //rec call
        printPermutation2(str,i+1);

        //backtracking
        swap(str[i],str[j]);
        
    }
}

int main(){


// 1️⃣ Quick Sort 
        
    // int arr[] = {8,1,23,83,20,30,6,5,2,3,2,5,60,5};

    // int n = 14;
    // int s = 0;
    // int e = n - 1;

    // quickSort(arr,s,e);

    // for(int val:arr){
    //   cout << val << " ";
    // }

    // 🎉 T.C O(nlogn) (Avg. case)
    // 🎉 T.C O(n2) (worst case)
    // 🎉 S.C O()

// 2️⃣ print permutation 

string str = "abc";
int i = 0;

// printPermutation1(str,i);
printPermutation2(str,i);


    return 0;
}