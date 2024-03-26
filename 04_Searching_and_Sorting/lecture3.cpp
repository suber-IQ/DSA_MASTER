// 👉 Binary Search (sorted array) (T.C :- O(logn))
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int nearlySorted(vector<int> arr,int target){

      int s = 0;
      int e = arr.size() - 1;
      int mid = s + (e - s) / 2;

      while(s <= e){
            if(arr[mid] == target){
                  return mid;
            }else if(mid - 1 >= s && arr[mid-1] == target){
                  return mid - 1;
            }else if (mid + 1 <= e && arr[mid + 1] == target){
                  return mid + 1;
            }else if(target > arr[mid]){
                  s = mid + 2;
            }else {
                  e = mid - 2;
            }
            mid = s + (e - s) /2;
      }
      return -1;
}

int divide(int dividend,int divisor){
      int s = 0;
      int e = abs(dividend);
      int mid = s + (e - s)/2;
      int ans = 0;
      while(s <= e){
            if(abs(mid*divisor) == abs(dividend)){
                  ans = mid;
                  break;
            }else if(abs(mid*divisor) > abs(dividend)){
                e = mid - 1;
            }else{
                ans = mid;
                s = mid + 1;
            }
            mid = s + (e - s)/2;
      }

      if((divisor < 0 && dividend < 0) || (divisor > 0 && dividend > 0)){
            return ans;
      }else{
            return -ans;
      }
}

int oddOccuring(vector<int> arr){
      int s = 0;
      int e = arr.size() - 1;
      int mid = s + (e - s)/2;

      while(s <= e){
            if(s == e){
                 return s; 
            }
            // mid -> even or odd 
            if(mid % 2 == 0){
                  if(arr[mid] == arr[mid + 1]){
                        s = mid + 2;
                  }else{
                        e = mid;
                  }
            }else{
                  if(arr[mid- 1] == arr[mid]){
                        s = mid + 1;
                  }else{
                        e = mid - 1;
                  }
            }
            mid = s + (e - s)/2;
      }
      return -1;
}

int main(){

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓1️⃣1️⃣ Search in a nearly sorted array in log time

// vector<int> arr{10,3,40,20,50,80,70};

// int target = 20;

// int ans  = nearlySorted(arr,target);
// cout << "index: " << ans << endl;

// 🎉 T.C = O(logn)


// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓1️⃣2️⃣ Divide 2 numbers using Binary Search

//   int dividend = -22;
//   int divisor = 7;

//   int ans = divide(dividend,divisor);
//   cout << "Quotient: " << ans << endl;

// int pression;
// cout << "Enter pression: " << endl;
// cin>>pression;
// double nextans = abs(ans);
// double step = 0.1;

// for(int i = 0; i < pression; i++){
//       for(double j = nextans; j * abs(divisor) <= abs(dividend); j += step){
//             nextans = j;
//       }
//       step /= 10;
// }

// if((divisor < 0 && dividend < 0) || (divisor > 0 && dividend > 0)){
//       nextans *= 1;
// }else{
//      nextans *= -1;

// }

// cout << "next ans: " << nextans << endl;


// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓1️⃣3️⃣ Find the odd occuring element in an array using Binary Search

// vector<int> arr{1,1,2,2,3,3,4,4,3,600,600,4,4};

//      int ans = oddOccuring(arr);
//      cout << "Index: " << ans << endl;
//      cout << "value is: " << arr[ans] << endl;
 

      

      return 0;
}