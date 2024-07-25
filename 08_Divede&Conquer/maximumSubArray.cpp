#include<iostream>
#include<vector>
#include<climits>
using namespace std;



int maxSubArr(vector<int>& arr,int s,int e){
     if(s == e) return arr[s];

     int maxLeftBorderSum = INT_MIN,maxRightBorderSum = INT_MIN;
     int mid = s + ((e-s) >> 1);

    int maxLeftSum = maxSubArr(arr,s,mid);
    int maxRightSum = maxSubArr(arr,mid+1,e);


    // find left max sum array border
    int maxLeftSumArr = 0;
    for(int i = mid; i >= s; i--){
       maxLeftSumArr += arr[i];
       if(maxLeftSumArr > maxLeftBorderSum) maxLeftBorderSum = maxLeftSumArr;
    }
    // find right max sum array border
    int maxRightSumArr = 0;
    for(int i = mid+1; i <= e; i++){
       maxRightSumArr += arr[i];
       if(maxRightSumArr > maxRightBorderSum) maxRightBorderSum = maxRightSumArr;
    }

    // crossBordersum = maxLeftBorderSum + maxRightBorderSum
    int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;

    return max(maxLeftSum,max(maxRightSum,crossBorderSum));


}


int main(){

     vector<int>  arr{-2,1,-3,4,-1,2,1,-5,4}; //output: 6

     int result = maxSubArr(arr,0,arr.size() - 1);
     cout << result << endl;

    //  T.C O(nlogn)
    // S.C O(logn)

    return 0;
}