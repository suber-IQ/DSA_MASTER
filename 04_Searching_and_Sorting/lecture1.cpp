// 👉 Binary Search (sorted array) (T.C :- O(logn))
#include<iostream>
#include<vector>
using namespace std;


int binarySearch(vector<int> &arr,int target){
      int start = 0;
      int end = arr.size() - 1; 
      
      int mid = start + (end - start)/2;

      while(start <= end){

            if(arr[mid] == target){
                  return mid;
            }
             if(arr[mid] < target){
                  start = mid + 1;
            }
            else{
                  end = mid - 1;
            }
         mid = start + (end - start)/2;
      }
      return -1;
}

int firstOccurence(vector<int> arr,int target){
      int start = 0;
      int end = arr.size() - 1;
      int index = -1;
      int mid = start + (end - start)/2;

      while(start <= end){
            if(arr[mid] == target){
                  index = mid;
                  end = mid - 1;
            }else if(arr[mid] < target){
                  start = mid + 1;
            }else{
                 end = mid - 1;
            }
            mid = start + (end - start)/2;
      }
      return index;

}
int lastOccurence(vector<int> arr,int target){
      int start = 0;
      int end = arr.size() - 1;
      int index = -1;
      int mid = start + (end - start)/2;

      while(start <= end){
            if(arr[mid] == target){
                  index = mid;
                  start = mid + 1;
            }else if(arr[mid] < target){
                  start = mid + 1;
            }else{
                 end = mid - 1;
            }
            mid = start + (end - start)/2;
      }
      return index;

}
int totalOccurence(vector<int> arr,int target){
   int total = lastOccurence(arr,target) - firstOccurence(arr,target) + 1; 
   return total;
}

// int missingElement(vector<int> arr,int target){

// }

int peakElement(vector<int> arr){
      int s = 0;
      int e = arr.size() - 1;
      int mid = s + (e - s)/2;

      while(s < e){
            if(arr[mid] < arr[mid + 1]){
                  s = mid + 1;
            }else{
                  e = mid;
            }
            mid  = s + (e - s)/2;
      }
      return s;
}

int main(){

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 1️⃣ Binary Search

//       vector<int> arr{2,4,7,10,15,19,21};
//       int target = 19;


//      int result = binarySearch(arr,target);
//      cout << result << endl;

     // 🎉 TC:- O(logn)

//     💁 algorithm: - 
                 // binary_search(arr,arr+n,target);
                 // binary_search(v.begin(),v.end(),target);

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 2️⃣ Find the first occurence of an element

// vector<int> arr{1,3,4,4,4,4,4,6,7,9};
// int target = 4;

// int result = firstOccurence(arr,target);
// cout << "first Occurence index : " << result << endl;

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 3️⃣ Find the first occurence of an element

// vector<int> arr{1,3,4,4,4,4,4,6,7,9};
// int target = 4;

// int result = lastOccurence(arr,target);
// cout << "index : " << result << endl;

//     💁 algorithm: - 
                 //auto ans2 = lower_bound(v.begin(),v.end(),target);
                 // ans2-v.begin()
                 // upper_bound(v.begin(),v.end(),target);

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 4️⃣ Total no of Occurence

// vector<int> arr{1,3,4,4,4,4,4,6,7,9};
// int target = 4;

// int result = totalOccurence(arr,target);
// cout << "total : " << result << endl;



// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 5️⃣ *Find missing element 


// vector<int> arr{1,3,4,4,4,4,4,6,7,9};
// int target = 4;

// int result = missingElement(arr,target);
// cout << "index : " << result << endl;


// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 6️⃣ Peak element in a Mountain Array


vector<int> arr{0,10,5,2};

int result = peakElement(arr);
cout << "index : " << result << endl;


      

      return 0;
}