#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


int solve(vector<int>& arr,int target){
    // base case
    if(target == 0) return 0;
    if(target < 0) return INT_MAX;

    // let's solve 1 case
    int mini = INT_MAX;
    for(int i = 0; i < arr.size(); ++i){
        int ans = solve(arr,target - arr[i]);
        if(ans != INT_MAX){
        mini = min(mini,ans + 1);
        }
    }

    return mini;

}

int solve1(int n,int x,int y,int z){
    //  base case 
    if(n == 0) return 0;

    if(n < 0) {
        return INT_MIN;
    }
    int ans1 = solve1(n - x,x,y,z) + 1;
    int ans2 = solve1(n - y,x,y,z) + 1;
    int ans3 = solve1(n - z,x,y,z) + 1;

    int ans = max(ans1,max(ans2,ans3));
    return ans;

}
void solve2(vector<int> &arr,int i,int sum,int& maxi){
    //base case
    if(i >= arr.size()) {
       maxi = max(sum,maxi);
       return;
    }
    //include
    solve2(arr,i+2,sum+arr[i],maxi);

    //exclude
    solve2(arr,i+1,sum,maxi);


}

int main(){

    // 1️⃣ You have to tell the minimum number of elements required to reach target sum. 
    // vector<int> arr{1,2};
    // int target = 5;

    // int ans = solve(arr,target);
    // cout << "Answer is: " << ans << endl;

    // 2️⃣ Cut into Segments

    // int n = 7;
    // int x = 5;
    // int y = 2;
    // int z = 2;

    // int ans = solve1(n,x,y,z);

    // if(ans < 0)
    //    ans = 0;
    // cout << "Answer is: " << ans << endl;

     // 2️⃣ Max sum of non -adjacent elements:

    //  vector<int> arr{2,1,4,9};
    //  vector<int> arr{1,2,4};
     vector<int> arr{1,2,3,5,4};

     int sum = 0;
     int maxi = INT_MIN;
     int i = 0;

   solve2(arr,i,sum,maxi);
  cout << maxi << endl;


    return 0;
}