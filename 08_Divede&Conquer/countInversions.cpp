#include<iostream>
#include<vector>
using namespace std;



// int countInversion1(int *arr,int n){

//     // int arr[] = {8,4,2,1}; //output: 6  (T.C: O(n^2) & S.C: O(1) )
//    int count = 0;
//    for(int i = 0; i < n; i++){
//       for(int j = i + 1; j < n; j++){
//          count = arr[i] > arr[j] ? count + 1 : count;
//       }
//    }

//     return count;
// }


void printArr(int *arr, int n){

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
        cout << endl;
}

long merge(int *arr, int start, int mid, int end) {
    int tempSize = end - start + 1;
    vector<int> temp(tempSize, 0);

    int i = start, j = mid + 1, k = 0;
    long invCount = 0;  // Count of inversions

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);  // All remaining elements in left subarray are inversions
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= end) {
        temp[k++] = arr[j++];
    }

    // Copy sorted elements back to original array
    for (int i = start; i <= end; ++i) {
        arr[i] = temp[i - start];
    }

    return invCount;
}

long mergeSort(int *arr, int start, int end) {
    long invCount = 0;
    if (start < end) {
        int mid = start + (end - start) / 2;
        invCount += mergeSort(arr, start, mid);
        invCount += mergeSort(arr, mid + 1, end);
        invCount += merge(arr, start, mid, end);
    }
    return invCount;
}



int main(){
    // 👉 count Inversions (Method 1)
//     int arr[] = {8,4,2,1}; 
//     int n = 4;
//    int result = countInversion1(arr,n);  
//    cout << result << endl;

    // 👉 count Inversions (Method 2)
  int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    long inversionCount = mergeSort(arr, 0, n - 1);
    cout << "Number of inversions are " << inversionCount << endl;

    // T.C: O(nlongn)
    // S.C: O(n)

}