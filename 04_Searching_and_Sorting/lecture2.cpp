// 👉 Binary Search (sorted array) (T.C :- O(logn))
#include<iostream>
#include<vector>
using namespace std;

int findSqrt(int n){
      int target = n;
      int s = 0;
      int e = n;
      int mid = s + (e - s)/2;
      int ans = -1;
      while(s <= e){
            if(mid*mid == target){
                  return mid;
            }else if(mid*mid > target){
                  e = mid - 1;
            }else{
                  ans = mid;
                  s = mid + 1;

            }
            mid = s + (e - s)/2;
      }
    return ans;
}

bool binarySearch(int arr[][4],int rows, int cols, int target){
      int s= 0;
      int e = rows*cols - 1;
      int mid = s + (e - s)/2;
      while(s <= e){
            int rowIndex = mid/cols;
            int colIndex = mid % cols;

            if(arr[rowIndex][colIndex] == target){
                  return true;
            }else if(arr[rowIndex][colIndex] < target){
               s = mid + 1;
            }else{
                  e = mid - 1;
            }
            mid = s + (e - s)/2;

      }
      return false;
}

int main(){


// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 9️⃣ SquareRoot of a number using Binary search

// int n;
// cout << "Enter the number: " << endl;
// cin>>n;

// int ans = findSqrt(n);
// cout << "Ans is : " << ans << endl;

// int precission;
// cout << "Precision is : " << endl;
// cin>>precission;

// double step = 0.1;
// double nextAns = ans;
// for(int i = 0; i < precission; i++){
//       for(double j = nextAns; j * j <= n; j += step){
//             nextAns = j;
//       }
//       step /= 10;
// }

// cout << nextAns << endl;


// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 10. Binary Search into 2D matrix

     int arr[5][4] = {
         {1,2,3,4},
         {5,6,7,8},
         {9,10,11,12},
         {13,14,15,16},
         {17,18,19,20},
     };
     int rows = 5;
     int cols = 4;

     int target = 5;

     bool ans = binarySearch(arr,rows,cols,target);

     if(ans){
      cout << "Found " << endl;
     }else{
      cout << "Not Found!" << endl;
     }


      

      return 0;
}