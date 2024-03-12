// Array - class 3
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void printVector(vector<int> arr){
      for(int i=0; i<arr.size(); ++i){
            cout << arr[i] << endl;
      }
}
void printTwoDArray(int arr[][4],int rows, int cols){
      for(int i=0; i<rows; ++i){
            for(int j=0; j<cols; ++j){
                  cout << arr[i][j] << " ";
            }
            cout << endl;
      }
}

void rowSum(int arr[][4],int rows,int cols){
      for(int i = 0; i < rows; ++i){
            int sum = 0;
            for(int j = 0; j < cols; ++j){
                   sum += arr[i][j];
            }
            cout << sum << " ";
      }

}

void colSum(int arr[][4],int rows,int cols){
      for(int i = 0; i < rows; ++i){
            int sum = 0;
            for(int j = 0; j < cols; ++j){
                  sum += arr[j][i];
            }
            cout << sum << " ";
      }
}

int linearSearch(int arr[][4],int rows,int cols,int key){
      int f = 0;
      
      for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                  if(arr[i][j] == key){
                        f = 1;
                        break;
                  }
            }
      }


      return f;
}

int max(int arr[][4],int rows,int cols){
      int maxi = INT_MIN;
      for(int i = 0; i < rows; ++i){
            
            for(int j = 0; j < cols; ++j){
                  if(arr[i][j] > maxi){
                       maxi = arr[i][j];
                  }
            }
      }

      return maxi;


}
int min(int arr[][4],int rows,int cols){
      int mini = INT_MAX;
      for(int i = 0; i < rows; ++i){
            
            for(int j = 0; j < cols; ++j){
                  if(arr[i][j] < mini){
                       mini = arr[i][j];
                  }
            }
      }

      return mini;


}

void transpose(int arr[][4],int rows,int cols,int ans[][4]){
      for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                  ans[j][i] = arr[i][j];
            }
      }
}

void print2DVector(vector<vector<int>> arr){
      for(int i = 0; i < arr.size(); ++i){
      for(int j = 0; j < arr[i].size(); ++j){
            cout << arr[i][j] << " ";
      }
      cout << endl;
}

}

int main(){
    
      //  👉 declare 2D array
      //  int arr[3][3];

       // 👉initialize 2D array
      //  int brr[3][3] = { {1,2,3}, 
      //                    {4,5,6}, 
      //                    {2,4,8}};

      //  cout << brr[2][2] << endl;

      // 👉  row-wise print
      // for(int i = 0; i < 3; ++i){
      //       for(int j = 0; j < 3; ++j){
      //             cout << brr[i][j] << " ";
      //       }
      //       cout << endl;
      // }

      // cout << "printing column wise " << endl;

      // 👉  column-wise print
      // for(int i = 0; i < 3; ++i){
      //       for(int j = 0; j < 3; ++j){
      //             cout << brr[j][i] << " ";
      //       }
      //       cout << endl;
      // }

      // 👉  row-wise input
      // int arr[4][3];
      // int rows = 4;
      // int cols = 3;

      // for(int i = 0; i < rows; ++i){
      //       for(int j = 0; j < cols; ++j){
      //             cin>>arr[i][j];
      //       }
      // }

      // // printing
      // cout << "printing row wise " << endl;

      // for(int i = 0; i < rows; ++i){
      //       for(int j = 0; j < cols; ++j){
      //             cout << arr[i][j] << " ";
      //       }
      //       cout << endl;
      // }
      // 👉  column-wise input
      // int arr[3][3];
      // int rows = 3;
      // int cols = 3;

      // for(int i = 0; i < rows; ++i){
      //       for(int j = 0; j < cols; ++j){
      //             cin>>arr[j][i];
      //       }
      // }

      // // printing
      // cout << "printing row wise " << endl;

      // for(int i = 0; i < rows; ++i){
      //       for(int j = 0; j < cols; ++j){
      //             cout << arr[i][j] << " ";
      //       }
      //       cout << endl;
      // }



  // 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

  //❓ 1️⃣ row-sum print

      // int arr[4][4] = {
      //       {1,2,3,4},
      //       {2,3,4,1},
      //       {5,6,1,3},
      //       {2,4,6,8},
      // };
      // int rows = 4;
      // int cols = 4;

      // rowSum(arr,rows,cols);


  // 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

  //❓ 2️⃣ column-sum print

      // int arr[4][4] = {
      //       {1,2,3,4},
      //       {2,3,4,1},
      //       {5,6,1,3},
      //       {2,4,6,8},
      // };
      // int rows = 4;
      // int cols = 4;

      // colSum(arr,rows,cols);

  // 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

  //❓ 3️⃣ linear search 2D array

//   int arr[4][4] = {
//             {1,2,3,4},
//             {2,3,4,1},
//             {5,6,1,3},
//             {2,4,6,8},
//       };
//       int rows = 4;
//       int cols = 4;
//       int key = 9;


//      cout << "linear Search true or false: " << linearSearch(arr,rows,cols,key) << endl;

     
  // 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

  //❓ 4️⃣ Maxmium number 2D array


//   int arr[4][4] = {
//             {1,2,3,4},
//             {2,3,99,1},
//             {5,6,1,3},
//             {2,4,6,8},
//       };
//       int rows = 4;
//       int cols = 4;


//      cout << "Maxmium: " << max(arr,rows,cols) << endl;

  // 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

  //❓ 5️⃣ Minmium number 2D array


//   int arr[4][4] = {
//             {22,2,3,4},
//             {2,3,99,8},
//             {5,6,44,3},
//             {2,4,6,8},
//       };
//       int rows = 4;
//       int cols = 4;


//      cout << "Minmium: " << min(arr,rows,cols) << endl;

  // 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

  //❓ 6️⃣ Transpose a matrix

//  int arr[4][4] = {
//             {5,2,3,4},
//             {2,3,9,8},
//             {5,6,10,3},
//             {2,4,6,8},
//       };
//       int rows = 4;
//       int cols = 4;
//       int ans[4][4];


// cout << "before printing array: " << endl;
//       printTwoDArray(arr, rows, cols);

// cout << "starting Transpose" << endl;
//       transpose(arr,rows,cols,ans);

// cout << "after priting array" << endl;
//       printTwoDArray(ans, rows, cols);



  // 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

//   👉 2d or more Vector 

// vector<vector<int>> arr;

// vector<int> a{1,2,3};
// vector<int> b{2,4,6,5,8};
// vector<int> c{1,3};

// arr.push_back(a);
// arr.push_back(b);
// arr.push_back(c);

// for(int i = 0; i < arr.size(); ++i){
//       for(int j = 0; j < arr[i].size(); ++j){
//             cout << arr[i][j] << " ";
//       }
//       cout << endl;
// }

// 👉 different 2d vector

int row = 3;
int col = 5;

vector<vector<int> > arr(row,vector<int>(col,0));
vector<vector<int> > brr(row,vector<int>(col,-1));
vector<vector<int> > krr(5,vector<int>(5,-8));

print2DVector(arr);
print2DVector(brr);
print2DVector(krr);
cout << krr[2][3] << endl;
      return 0;
}