#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printVector(vector<int> arr){
      for(int i = 0; i < arr.size(); ++i){
            cout << arr[i] << " ";
      }
}

void sortColor(vector<int> &arr){
      int s = 0;
      int e = arr.size() - 1;
      int i = 0;
      while(i <= e){
            if(arr[i] == 2){
                  swap(arr[i], arr[e]);
                  e--;
            }else if(arr[i] == 0){
                  swap(arr[i],arr[s]);
                  s++;
                  i++;
            }else{
                  i++;
            }
      }
}

void moveNegative(vector<int> &arr){
      int i = 0;
      int l = 0;
      while(i < arr.size()){
            if(arr[i] < 0){
                  swap(arr[i],arr[l]);
                  i++;
                  l++;
            }else{
                  i++;
            }
      }
}

int duplicate(vector<int> arr){
     sort(arr.begin(), arr.end());

     for(int i = 0; i < arr.size() - 1; ++i){
        if(arr[i] == arr[i + 1]){
            return arr[i];
        }
     }
     return -1;
}

int duplicate1(vector<int> arr){ // with modify
      int ans = -1;
      for(int i = 0; i < arr.size(); ++i){
            int index = abs(arr[i]);
            // already visted
            if(arr[index] < 0){
                  ans = index;
                  break;
            }
            // visted mark 
            arr[index] *= -1;
      }
      return ans;
}

int duplicate2(vector<int> arr){ // with modify (swap)
     while(arr[0] != arr[arr[0]]){
        swap(arr[0],arr[arr[0]]);
     }
     return arr[0];
}

void missing(vector<int> arr){
      for(int i = 0; i < arr.size(); ++i){
            int index = abs(arr[i]);
            if(arr[index - 1] > 0){
                  arr[index - 1] *= -1;
            }
      }

      for(int i = 0; i < arr.size(); ++i){
            if(arr[i] > 0){
            cout << i + 1 << endl;
            }
      }
}


void missing1(vector<int> arr){

     int i = 0;
     while(i < arr.size()){
       int index = arr[i] - 1;
       if(arr[i] != arr[index]){
            swap(arr[i],arr[index]);
       }else{
            ++i;
       }
     }

     for(int i = 0; i < arr.size(); ++i){
      if(arr[i] != i + 1){
            cout << i + 1 << " ";
      }
     }

}

int main(){

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓1️⃣ sort colors

//      vector<int> arr{2,0,2,1,1,0};
//      vector<int> arr{2,0,2,1,1,0,0,1,2,0,1,2,0,1};

//      sortColor(arr);

//     printVector(arr);

// 🎉 TC:- O(n)
// 🎉 SC :- O(1)



// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 2️⃣ Move all -ve number to the left side of an array

// vector<int> arr{1,2,-3,4,-5,6};
// moveNegative(arr);
// printVector(arr);

// 🎉 TC:- O(n)
// 🎉 SC :- O(1)

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓3️⃣ Find the Duplicate Number

//    vector<int> arr{1,3,4,2,2};
//    vector<int> arr{2,2,2,2};

//   cout << duplicate(arr) << endl;
// 🎉 TC:- O(nlogn)
// 🎉 SC :- O(n)


//   cout << duplicate1(arr) << endl;
  // 🎉 TC:- O(n)
// 🎉 SC :- O(1)

//   cout << duplicate2(arr) << endl;
  // 🎉 TC:- O(n)
// 🎉 SC :- O(1)


// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 4️⃣ Missing Element from an Array with duplicates

vector<int> arr{1,3,5,3,4};

// missing(arr);
  // 🎉 TC:- O(n)
// 🎉 SC :- O(1)
missing1(arr);
  // 🎉 TC:- O(n)
// 🎉 SC :- O(1)


      return 0;
}
