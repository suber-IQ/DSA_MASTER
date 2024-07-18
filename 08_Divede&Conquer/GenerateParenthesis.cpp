#include<iostream>
#include<vector>
#include<string>
using namespace std;


void generateParenthesis(int n,vector<string>& ans,string output,int open,int close){

    if(open == 0 && close == 0){
        ans.push_back(output);
        return;
    }



    // open
    if(open > 0){
        output.push_back('(');
        generateParenthesis(n,ans,output,open-1,close);
        output.pop_back();
    }

    //close
    if(close > open){
        output.push_back(')');
        generateParenthesis(n,ans,output,open,close-1);
        output.pop_back();
    }
}


int main(){

    int n = 3;
    string output = "";
    vector<string> ans;
    int open = n;
    int close = n;
    generateParenthesis(n,ans,output,open,close);
    for(int i = 0; i < ans.size(); i++){
            cout << '"' << ans[i] << '"' << endl;
    }


    return 0;
}