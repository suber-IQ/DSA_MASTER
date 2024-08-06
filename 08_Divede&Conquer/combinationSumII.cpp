#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

void printVector(vector<vector<int>> & ans){
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

void combinationSumII(vector<int>& candidates,int target,vector<vector<int> >& ans,vector<int>& v,int index){
    //base case
    if(target == 0){
        ans.push_back(v);
        return;
    }
    if(target < 0){
        return;
    }

    for(int i =index; i < candidates.size(); ++i){
        if(i > index && candidates[i] == candidates[i - 1]){
            continue;
        }
        v.push_back(candidates[i]);
        combinationSumII(candidates,target - candidates[i],ans,v,i+1);
        v.pop_back();
    }

}



int main(){
    vector<int> candidates{10,1,2,7,6,1,5}; // output: [[1,1,6],[1,2,5],[1,7],[2,6]]
    sort(candidates.begin(),candidates.end());
    int target = 8;
    vector<vector<int> > ans;
    vector<int> v;
    int index = 0;

    combinationSumII(candidates, target,ans,v,index);
//    set<vector<int>> mySet;
//     for(auto e : ans){
//         mySet.insert(e);
//     }
//     ans.clear();
//     for(auto e : mySet){
//         ans.push_back(e);
//     }

    printVector(ans);


    return 0;
}