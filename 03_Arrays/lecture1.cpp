// Arrays - Class 1
#include<iostream>
#include<climits>
using namespace std;

// with variable
// void inc(int a){
//       a++;
//       cout << "fuction a: " << a << endl;
// }
// with array
void printArray(int arr[],int size){
      for(int i = 0; i < size; ++i){
            cout << arr[i] << " ";
      }
}

void inc(int arr[],int size){
      arr[0] += 10;
      arr[1] += 20;
      printArray(arr,size);
}

// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

   // ❓ 6️⃣ Linear Search in Array

   int linearSearch(int arr[],int size,int p){
     for(int i = 0; i < size; ++i){
      if(arr[i] == p){
            return true;
      }
    }
     return false;
   }

// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

   // ❓ 7️⃣ Count 0's and 1's in Array

   void countOnesZeros(int arr[],int size,int &zeros,int &ones){
      for(int i = 0; i < size; ++i){
            if(arr[i] == 0){
                 zeros += 1;
            }
            if(arr[i] == 1){
                  ones += 1;
            }
      }
   }

// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

   // ❓ 8️⃣ Maximum number in an array

   int findMax(int arr[],int size,int max){
      for(int i = 0;  i < size; ++i){
            if(arr[i] > max){
                  max = arr[i];
            }
      }
      return max;
   }
   int findMin(int arr[],int size,int min){
      for(int i = 0;  i < size; ++i){
            if(arr[i] < min){
                  min = arr[i];
            }
      }
      return min;
   }

// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

   // ❓ 9️⃣ Extreme Print in Array

   void extremeArray(int arr[],int size,int start,int end){

       while(start <= end){
         
            if(start == end){
               cout << arr[start] << " ";
            }else{
                cout << arr[start] << " ";
                cout << arr[end] << " ";
            
            }
            start++;
            end--;
            
          
       }
    }

void reverseArr(int arr[],int size,int start,int end){
   while(start <= end){
      //  cout << arr[end--] << " "; 
      swap(arr[start],arr[end]);
      start++;
      end--;      
   }
}

int main(){


// ❓ 👉 1️⃣ Print Array
      // int arr[5]={12,2,8,28,16};
      // cout << arr[2] << endl;

      // int size = sizeof(arr)/sizeof(arr[0]);
      // cout << sizeof(arr) << endl;  // size of all element of array
      // cout << sizeof(arr[0]) << endl; // size of one element of array

      // // with loop
      // for(int i = 0; i < size; ++i){
      //       cout << arr[i] << " ";
      // } 
      // 👉 taking input of array to print

      // int arr[5];
      // int size = sizeof(arr)/sizeof(arr[0]);
      // for(int i = 0; i < size; ++i){
      //       cin>>arr[i];
      // }
      // cout << endl;
      // // print
      // for(int i = 0; i < size; ++i){
      //       cout << arr[i] << " ";
      // }

//    🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

   // ❓ 2️⃣ take 5 element i/p in array print their doubles

//    int arr[100];

//    int n;
//    cout << "Enter value n: " << endl;
//    cin>> n;

//    for(int i = 0; i< n; ++i){
//       cin>>arr[i];
//    }

//      //  print arr give by user
//      for(int i = 0; i < n; ++i){
//       cout << 2 * arr[i] << " ";
//      }
//    🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

   // ❓3️⃣ given random number of array to change from 1.

   //  🎉 output:-  int arr[]= {1,1,1,1,1,1,1,1,1,1}; 
     
//      int arr[] = {1,3,4,5,6,7,8,9,10,11};

//      int size = sizeof(arr)/sizeof(arr[0]);

//      for(int i = 0; i < size; ++i){
//         arr[i] = 1;
//      }

//      for(int i = 0; i < size; ++i){
//       cout << arr[i] << " ";
//      }
    
//    🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

   // ❓4️⃣ check remaining number is what of array ?

//    int arr[10] = {1,2,3};

//    for(int i = 0; i < 10; ++i){
//       cout << arr[i] << " ";
//    }

//    🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

//    ❓ 5️⃣ initialise of 0 or another.. all array

// int arr[10] = {0};
// for(int i = 0; i < 10; ++i){
//       cout << arr[i] << " ";
// }


//  🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

// 👉 array && functions:

//    int a = 10;
//    inc(a);  // 🎄 pass by value working
//    cout << "variable of main a: " << a << endl;

// 👉 with array 
// int arr[] = {5,10};
// int size = 2;

// cout << "inc fuction:" << endl;
// inc(arr,size);  // 🎄 pass by reference working
// cout << "main" << endl;
// printArray(arr,size);

// 👉 how to copy array

// int srcArr[] = {2,3,4,5,6};
// int size = sizeof(srcArr)/sizeof(srcArr[0]);

// // Define destination array
// int destArr[size];

// // copy element
// for(int i = 0; i < size; ++i){
//       destArr[i] = srcArr[i];
// }


// inc(destArr,size);
// cout << endl;
// printArray(srcArr,size);

    
// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

   // ❓ 6️⃣ Linear Search in Array

//     int p,arr[100],n;
//     cout << "Enter value of n: " << endl;
//     cin>>n;
    
//     // taking input of array
//     for(int i = 0; i < n; ++i){
//       cin >> arr[i];
//     }

//     cout << "Enter value of p: " << endl;
//     cin>>p;
 
    
//     if(linearSearch(arr,n,p)){
//       cout << "Value of p: " << p << " is Persent" << endl; 
//     }else{
//       cout << "Value of p: " << p << " is Absent" << endl;
//     }


        
// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

   // ❓ 7️⃣ Count 0's and 1's in Array

//    int arr[]= {0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1}; 
//    int zeros = 0;
//    int ones = 0;
//    int size = sizeof(arr)/sizeof(arr[0]);

//    countOnesZeros(arr,size, zeros,ones);

//    cout << "Zeros: " << zeros << endl; // 🎉 output:- Zeros: 9
//    cout << "ones: " << ones << endl;  // 🎉 output:- ones: 8

// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

   // ❓ 8️⃣ Maximum number in an array

//    int arr[] = {2,4,88,1,6,8,9,1,99};
//    int size = sizeof(arr)/sizeof(arr[0]);
//     int max = INT_MIN;
//     int min = INT_MAX;

//    cout << "Max: " << findMax(arr,size,max) << endl; // 🎉 output:- Max: 99
//    cout << "Min: " << findMin(arr,size,min) << endl; // 🎉 output:- Min: 1

// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

   // ❓ 9️⃣ Extreme Print in Array

   // int arr[] = {1,2,3,4,5,6,7,8,9};

   // int size = sizeof(arr)/sizeof(arr[0]);
   // int start = 0;
   // int end = size - 1;

   // extremeArray(arr,size,start,end);



// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

   // ❓ 1️⃣0️⃣ Reverse array

   int arr[] = {1,2,3,4,5,6,7,8,9};
   int size = sizeof(arr)/sizeof(arr[0]);
    int start = 0;
    int end = size - 1;

    reverseArr(arr,size,start,end);

    printArray(arr,size);

   




  return 0;
}