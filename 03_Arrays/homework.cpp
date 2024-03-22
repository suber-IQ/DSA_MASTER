#include<iostream>
#include<vector>
#include<set>
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
int repeating(int a[],int n){
    unordered_map<int, int>hash;

        for(int i = 0; i < n; ++i){
      hash[a[i]]++;
    }

    for(int i = 0; i < n; ++i){
      if(hash[a[i]] > 1){
            return i + 1;
      }
    }
  return -1;
}

vector<int> commonElements(int A[],int B[],int C[],int n1,int n2,int n3){
           vector<int>ans;
             set<int> st;
      int i,j,k;
      i = j = k = 0;
      while(i < n1 && j < n2 && k < n3){
            if(A[i] == B[j] && B[j] == C[k]){
                  st.insert(A[i]);
                  i++;
                  j++;
                  k++;
            }else if(A[i] < B[j]){
                  i++;
            }else if(B[j] < C[k]){
                  j++;
            }else{
                  k++;
            }
      }
      for(auto v:st)
          ans.push_back(v);
      return ans;

}

void wavePrint(vector<vector<int> > arr){
      int m = arr.size();
      int n = arr[0].size();

      for(int j = 0; j < n; j++){
            if((j & 1) == 0){
                  for(int i = 0; i < m; i++){
                        cout << arr[i][j] << " ";
                  }
            }else{
                  for(int i = m - 1; i >= 0; i--){
                        cout << arr[i][j] << " ";
                  }
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

// vector<int> arr{1,3,5,3,4};

// missing(arr);
  // 🎉 TC:- O(n)
// 🎉 SC :- O(1)
// missing1(arr);
  // 🎉 TC:- O(n)
// 🎉 SC :- O(1)

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 5️⃣ Find first Repeating Element

//    int n = 7;
//    int a[] = {1,5,3,4,3,5,6};


//     cout << repeating(a,n) << endl;

// 🎉 TC:- O(n)
// 🎉 SC :- O(n)

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 6️⃣ Common Elements in 3 Sorted Array

//    int A[] = {1,5,10,20,40,80};
//    int B[] = {6,7,20,80,100};
//    int C[] = {3,4,15,20,30,70,80,120};
   
//    int n1 = 6;
//    int n2 = 5;
//    int n3 = 8;

//    vector<int> result = commonElements(A,B,C,n1,n2,n3);

//    printVector(result);

// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 7️⃣ *wave print / zig zig print

vector<vector<int>> arr{
      {1,2,3,4},
      {5,6,7,8},
      {9,10,11,12}
};

wavePrint(arr);

  
      return 0;
}
