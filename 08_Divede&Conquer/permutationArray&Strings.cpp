#include<iostream>
#include<vector>
using namespace std;


void print2DArr(vector<vector<int> > & ans){
         for(int i = 0; i < ans.size(); i++){
             for(int j = 0; j < ans[i].size(); j++){
                cout << ans[i][j] << " ";
             }
             cout << endl;
        }

}

void permutation1(int* arr,vector<vector<int>> &ans,vector<bool> &visted, vector<int> &temp){

        if(visted.size() == temp.size()){
           ans.push_back(temp);
           return;
        }
    

     for(int i = 0; i < visted.size(); i++){
         if(visted[i] == 0){
                visted[i] = 1;
                temp.push_back(arr[i]);
                permutation1(arr,ans,visted,temp);
                visted[i] = 0;
                temp.pop_back();
         }
     }
}

void permutation2(vector<int>& arr, vector<vector<int>> &ans,int index){
   if(index == arr.size()){
      ans.push_back(arr);
      return;
   }

   for(int i = index; i< arr.size(); i++){
       swap(arr[i],arr[index]);
       permutation2(arr,ans,index+1);
       swap(arr[i],arr[index]);
   }
}


int main(){

//   👉 permutations 

        // {1,2,3} 

        // 1 2 3
        // 1 3 2
        // 2 3 1
        // 2 1 3
        // 3 1 2
        // 3 2 1

        // 3! = 6  (size of arr 3)
        // 4! = 24
        // 2! = 2
        // 1! = 1

// 👉 Method 1

      //   int arr[] = {1,2,3};
      //   vector<vector<int> > ans;
      //   vector<bool> visted(3,0);
      //   vector<int> temp;

      //   permutation1(arr,ans,visted,temp);

   // print2DArr(ans)
  
      // T.C: O(n!)  
      // S.C: O(n)  

// 👉 Method 2 

      vector<int> arr = {1,2,3};
        vector<vector<int> > ans;
        int index = 0;
        permutation2(arr,ans,index);

      print2DArr(ans);




    return 0;
}