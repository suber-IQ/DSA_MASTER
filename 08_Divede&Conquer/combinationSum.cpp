#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<vector<int>> & ans){
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

void combinationSum(vector<int>& candidates,int target,vector<vector<int> >& ans,vector<int>& v,int index){
    //base case
    if(target == 0){
        ans.push_back(v);
        return;
    }
    if(target < 0){
        return;
    }

    for(int i =index; i < candidates.size(); ++i){
        v.push_back(candidates[i]);
        combinationSum(candidates,target - candidates[i],ans,v,i);
        v.pop_back();
    }

}



int main(){
    vector<int> candidates{2,3,6,7}; // output: [[2,2,3],[7]]
    int target = 7;
    vector<vector<int> > ans;
    vector<int> v;
    int index = 0;

    combinationSum(candidates, target,ans,v,index);

    printVector(ans);


    return 0;
}