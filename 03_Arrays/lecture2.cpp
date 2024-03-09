// Arrays - Class 2
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;


int findUnique(vector<int> arr){
      int ans = 0;

      for(int i = 0; i < arr.size(); ++i){
            ans = ans ^ arr[i];
      }

      return ans;
}
void printVector(vector<int> arr){
      for(int i = 0; i < arr.size(); ++i){
            cout << arr[i] << " ";
      }
}
void unionArrys(vector<int> &arr,int a[],int size){
      for(int i = 0; i < size; ++i){
            if(a[i] != INT_MIN){
               arr.push_back(a[i]);
            }
      }
}

void intersectionArrays(vector<int> &ans,int a[],int b[],int sizea,int sizeb){
       for(int i = 0; i < sizea; ++i){
           for(int j = 0; j < sizeb; ++j){
             if(a[i] == b[j]){
                  b[j] = INT_MIN;
                  ans.push_back(a[i]);
             }
           }
       }
}

void unionDuplicate(vector<int> &ans,int a[],int b[],int sizea,int sizeb){
     for(int i = 0; i < sizea; ++i){
           for(int j = 0; j < sizeb; ++j){
              if(a[i] == b[j]){
                  b[j] = INT_MIN;
             }
           }
       }
       unionArrys(ans,a,sizea);
       unionArrys(ans,b,sizeb);

}

int main()
{

      // 👉 Create vector
//       vector<int> arr;

//       int ans = (sizeof(arr) / sizeof(int));
//       cout << ans << endl; // 🎉 output:- 6

//       cout << arr.size() << endl;     // 🎉 output:- 0
//       cout << arr.capacity() << endl; // 🎉 output:- 0

//       // 👉 insert vector
//       arr.push_back(5);
//       arr.push_back(6);

//       //👉 print
//       for(int i = 0; i < arr.size(); ++i){
//             cout << arr[i] << " ";
//       }
//       cout << endl;
//       cout << arr.size() << endl; 

//       // 👉 remove / delete
//       arr.pop_back();

//       //👉 print
//       for(int i = 0; i < arr.size(); ++i){
//             cout << arr[i] << " ";
//       }
//      cout << arr.size() << endl;


      // 👉 Create vector part - 2

//       vector<int> brr(10);
//       cout << "size of b: " << brr.size() << endl;
//       cout << "capacity of b: " << brr.capacity() << endl;


//       for(int i = 0; i < brr.size(); ++i){
//             cout << brr[i] << " ";  // 🎉 output:- 0 0 0 0 0 0 0 0 0 0
//       }
//       cout << endl;
//      vector<int> drr(10,-101);


//      for(int i = 0; i < drr.size(); ++i){
//       cout << drr[i] << " ";   // 🎉 output:- -101 -101 -101 -101 -101 -101 -101 -101 -101 -101 
//      }

//       int n;
//       cout << "Enter value of n: " << endl;
//       cin>>n;
//       vector<int> prr(n,5);

//       for(int i = 0; i < prr.size(); ++i){
//             cout <<  prr[i] << " ";  
//       }
//       cout << endl;

//       vector<int> krr{10,20,30,40,50};

//       for(int i = 0; i < krr.size(); ++i){
//             cout << krr[i] << " ";
//       }

//       cout << endl;

//       cout << "Vector krr is empty or not " << krr.empty() << endl;

//       vector<int> lrr;
//       cout << "Vector krr is empty or not " << lrr.empty() << endl;


      // 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

      // ❓ 1️⃣ Find Unique Element (every element occurs twice except one)

      // int n;
      // cout << "Enter the size of array: " << endl;
      // cin>>n;

      // vector<int> arr(n);
      // cout << "Enter the elements: " << endl;

      // //taking input
      // for(int i=0; i<arr.size(); ++i){
      //       cin>> arr[i];
      // }

      // int uniqueElement = findUnique(arr);

      // cout << "Unique element: " << uniqueElement << endl;

   // 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

      // ❓ 2️⃣ Union of 2 arrays

      // vector<int> arr;
      // int a[]= {2,4,6,8};
      // int sizea = 4;
      // int b[]= {1,3,7};
      // int sizeb = 3;


      //  unionArrys(arr,a,sizea);
      //  unionArrys(arr,b,sizeb);

      // for(int i = 0; i < arr.size(); ++i){
      //       cout << arr[i] << " ";
      // }
      // cout << endl;



   // 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

      // ❓ 3️⃣ Intersection of 2 arrays

      // int a[] = {1,2,3,4,3,6,8};
      // int sizea = 7;
      // int b[] = {3,4,9,2,3,10};
      // int sizeb = 6;

      // vector<int> ans;

      // intersectionArrays(ans,a,b, sizea, sizeb);

      // printVector(ans);
      // cout << endl;


   // 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

      // ❓ 4️⃣ Union (with duplicate)

      // int  a[] = {1,2,4,6,8,10};
      // int b[] = {3,4,5,6};
      // int sizea = 6;
      // int sizeb = 4;

      // vector<int> ans;

      // unionDuplicate(ans,a,b,sizea,sizeb);
       
      // printVector(ans);
      return 0;
}
