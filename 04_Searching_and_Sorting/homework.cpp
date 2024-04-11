// 👉 Assignment week 4 (Searching and Sortings)
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int binarySearch(vector<int> &arr,int start,int x){
      int end = arr.size() - 1;
      while(start <= end){
            int mid = start + (end -start) / 2;
            if(arr[mid] == x){
                  return mid;
            }else if(x > arr[mid]){
                  start = mid + 1;
            }else{
                  end = mid - 1;
            }
            mid = start + (end - start)/2;
      }
      return -1;
}

int kDiffPairs(vector<int> arr,int k){
      sort(arr.begin(),arr.end());
      set<pair<int,int> > ans;      
      int i = 0;
      int j = 1;
      int diff;
      while(j < arr.size()){
            diff = arr[j] - arr[i];
            
            if(diff == k){
                ans.insert({arr[i],arr[j]});
                i++;
                j++;
            }else if(diff < k){
                  j++;
            }else{
                  i++;
            }
            if(i == j){
                  j++;
            }
      }
      return ans.size();
}
int kDiffPairs1(vector<int> arr,int k){
     sort(arr.begin(),arr.end());
          set<pair<int,int> > ans;      

     for(int i = 0; i < arr.size(); ++i){
        if(binarySearch(arr,i+1,arr[i] + k) != -1){
           ans.insert({arr[i],arr[i] + k});
        }
     }
     return ans.size();
}
int lowerBound(vector<int> &arr,int x){
      int start = 0;
      int end = arr.size() - 1;
      int ans = end;
      while(start <= end){
            int mid = start + (end - start) /2;
            if(arr[mid] >= x){
                  ans = mid;
                  end = mid - 1;
            }else if(x > arr[mid]){
                  start = mid + 1;
            }else{
                  end = mid - 1;
            }
      }
      return ans;
}
vector<int> bs_method(vector<int>& arr,int k,int x){
      //lower bound
      int h = lowerBound(arr,x);
      int l = h -1;
      while(k--){
            if(l < 0){
                  h++;
            }else if(h >= arr.size()){
                  l--;
            }
            else if(x-arr[l] > arr[h] - x){
                  h++;
            }else{
                  l--;
            }
      }
      return vector<int>(arr.begin() + l + 1,arr.begin() + h);
}

vector<int> kClosest(vector<int> &arr,int k, int x){
      // method 1 
      // int l = 0;
      // int h = arr.size() - 1;
      // while(h-l >= k){
      //       if(x - arr[l] > arr[h] - x){
      //             l++;
      //       }else{
      //             h--;
      //       }
      // }
      // vector<int> ans;
      // for(int i = l; i <= h; i++){
      //       ans.push_back(arr[i]);
      // }
      // return ans;

      // return vector<int>(arr.begin() + l,arr.begin() + h + 1);

      // method 2 
return bs_method(arr,k,x);



}
int main(){

      // 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 1️⃣ K-Diff Pairs in an Array
     
//      vector<int> arr{3,1,4,1,5};
//      vector<int> arr{1,3,1,5,4};
//      int k = 0;

// //    int result = kDiffPairs(arr,k);
//    int result = kDiffPairs1(arr,k);
// //   🎉 T.C = O(nLogn)
//    cout << "Ans: " << result << endl;



// 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

// ❓ 2️⃣ Find k-Closest Element

vector<int> arr{12,16,22,30,35,39,42,45,48,50,53,55,56};
int k = 4;
int x = 35;
vector<int> result = kClosest(arr,k,x);

// 🎉 T.C = O(n)
// 🎉 S.C = O(1)

for(int i = 0; i < result.size(); ++i){
      cout << result[i] << " ";
}



      return 0;
}