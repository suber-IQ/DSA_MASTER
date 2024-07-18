#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<int,bool> rowCheck;
unordered_map<int,bool> leftUpperDiagonalCheck;
unordered_map<int,bool> leftDownDiagonalCheck;


void printSoln(vector<vector<char>>& board,int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < board[0].size(); j++){
            cout << board[i][j] << " ";
        }
        cout << endl;

    }

    cout << endl << endl;
}

// bool isSafe(int row,int col,vector<vector<char>>& board,int n){
bool isSafe(int row,int col,int n){



if(rowCheck[row] == true){
    return false;
}

if(leftUpperDiagonalCheck[n-1+col-row] == true){
    return false;
}

if(leftDownDiagonalCheck[row+col] == true){
    return false;
}


return true;
//     // reverse left side
//     int i = row;
//     int j = col;

//     while(j >= 0){
//         if(board[i][j] == 'Q'){
//             return false;
//         }
//             j--;
//     }
//     // reverse left top diagonal
//     i = row;
//     j = col;
//     while(i >= 0 && j >= 0){
//         if(board[i][j] == 'Q'){
//             return false;    
//         }
//         i--;
//         j--;
//     }

//     // reverse left bottom diagonal
//      i = row;
//     j = col;
//     while(i < n && j >= 0){
//         if(board[i][j] == 'Q'){
//             return false;
//         }
//         i++;
//         j--;
//     }


// return true;


}

void nQueen(int col,vector<vector<char>>& board,int n){
  if(col >= n){
     printSoln(board,n);
     return;
  }

  for(int row = 0; row < n; row++){
     if(isSafe(row,col,n)){
        board[row][col] = 'Q';
        rowCheck[row] = true;
        leftUpperDiagonalCheck[n-1+col-row] = true;
        leftDownDiagonalCheck[row+col] = true;
        nQueen(col+1,board,n);
        board[row][col] = '-';
         rowCheck[row] = false;
        leftUpperDiagonalCheck[n-1+col-row] = false;
        leftDownDiagonalCheck[col+row] = false;
     }
  }
}




int main(){

// 👉  Method 1

int n = 4;
vector<vector<char>> board(n,vector<char>(n,'-'));

int col = 0;
nQueen(col,board,n);

// coming from map to read then optimize code 


 


    return 0;
}