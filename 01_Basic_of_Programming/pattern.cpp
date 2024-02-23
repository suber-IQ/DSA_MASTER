#include<iostream>
using namespace std;


int main(){


// ❓ 1️⃣ Solid rectangle star pattern
     // * * * * * 
     // * * * * * 
     // * * * * *
  

// 🎄 Solution 1:
      // int rows = 3;
      // int cols = 5;

      // for(int i = 0; i < rows * cols; i++){
      //       if(i % cols == 0 && i != 0){
      //             cout << endl;
      //       }

      //       cout << "* ";
      // }
// 🎄 Solution 2:

//     for(int row = 0; row < 3; ++row){
//       for(int col = 0; col < 5; ++col){
//             cout << "* ";
//       }
//       cout << endl;
//     }

// ❓ 2️⃣ Square star pattern  (4 * 4)
// * * * * 
// * * * * 
// * * * * 
// * * * *

// 🎄 Solution 1:

// int row;
// cout << "Enter number: " << endl;
// cin>>row;

//    for(int i = 0; i < row * row; ++i){
//       if(i % row == 0 && i != 0){
//             cout << endl;
//       }
//       cout << "* ";
//    }

// 🎄 Solution 2:
// int n;
// cout << "Enter number: " << endl;
// cin>> n;

//    for(int row = 0; row < n; ++row){
//       for(int col = 0; col < n; ++col){
//          cout << "* ";
//       }
//       cout << endl;
//    }

// ❓ 3️⃣ Hollow star Rectangle

// * * * * * 
// *       * 
// * * * * * 

//        int rows,cols;
//        cout << "Enter rows: " << endl;
//        cin>>rows;
//        cout << "Enter cols: " << endl;
//        cin>>cols;

//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1)
//                 cout << "* ";
//             else
//                 cout << "  ";
//         }
//         cout << endl;
//     }

// ❓ 4️⃣ Half star Pyramid
// * 
// * * 
// * * * 
// * * * * 
// * * * * * 


    // int n;
    // cout << "Enter n: " << endl;
    // cin>>n;

    // for(int rows = 0; rows < n; ++rows){
    //   for(int cols = 0; cols < rows + 1; ++cols){
    //          cout << "* ";
    //   }
    //   cout << endl;
    // }

// ❓ 5️⃣ Inverted Half star Pyramid
// * * * * * 
// * * * * 
// * * * 
// * * 
// * 

  // int n;
  // cout << "Enter n: " << endl;
  // cin>>n;

  //    for(int rows = 0; rows < n; ++rows){
  //     for(int cols = 0; cols < n - rows; ++cols)
  //        cout << "* ";
  //        cout << endl;
  //    }

// ❓ 6️⃣ Numeric Half Pyramid

// 1
// 12
// 123
// 1234
// 12345

// int n;
// cout << "Enter n: " << endl;
// cin>>n;

// for(int rows = 0; rows < n; ++rows){
//   for(int cols = 0; cols<rows + 1; ++cols)
//     cout << cols + 1;
//     cout << endl;
// }
// ❓ 7️⃣ Inverted Half Pyramid

// 12345
// 1234
// 123
// 12
// 1

// int n;
// cout << "Enter n: " << endl;
// cin>>n;


// for(int rows = 0; rows < n; ++rows){
//   for(int cols = 0; cols < n - rows; ++cols)
//     cout << cols + 1;
//     cout << endl;
// }

// ❓ 8️⃣ Full Star Pyramid

  //     * 
  //    * * 
  //   * * * 
  //  * * * * 
  // * * * * * 

// int n;
// cout << "Enter n: " << endl;
// cin>>n;

// 🎄 solution: 1

// for(int rows = 0; rows < n; ++rows){
//    for(int i = 0; i < n - (rows - 1); ++i)
//      cout << " ";
//    for(int j = 0; j < rows + 1; ++j)
//    cout << "* ";
//    cout << endl;  
// }

// ❓ 9️⃣ Inverted Full Star Pyramid

// * * * * * 
//  * * * * 
//   * * * 
//    * * 
//     *

  //  int n;
  //  cout << "Enter n: " << endl;
  //  cin>>n;
   
  //  for(int rows = 0; rows < n; ++rows){
  //   //  space 
  //   for(int i = 0; i < rows; ++i)
  //   cout << " ";
  //   // star print
  //   for(int j = 0; j < n - rows; ++j)
  //     cout << "* ";
  //   cout << endl;
  //  }

// ❓ 1️⃣2️⃣ Hollow Square Pattern
// ****
// *  *
// *  *
// ****

// int n;
// cout << "Enter n: " << endl;
// cin>>n;

// for(int i = 0; i < n; ++i){
//   for(int j = 0; j < n; ++j)
//     if(i == 0 || i == (n-1) || j == 0 || j == (n-1)){
//       cout << "*";
//     }else{
//       cout << " ";
//     }
//     cout << endl;
// }


// ❓ 1️⃣3️⃣ Hollow Inverted Half Pyramid

// **********
// *       * 
// *      *  
// *     *   
// *    *    
// *   *     
// *  *      
// * *       
// **        
// *

// int n;
// cout << "Enter n: " << endl;
// cin>>n;


// for(int i = 0; i < n; ++i){
//    for(int j = 0; j < n; ++j){
//       if(i == 0 || j == 0 || j == n - i - 1)
//        cout << "*";
//       else
//         cout << " ";
//    }
//    cout << endl;
// }

// ❓ 1️⃣4️⃣ Hollow full Star Pyramid

//     *    
//    * *   
//   *   *  
//  *     * 
// *********

int n;
cout << "Enter n: " << endl;
cin>>n;


for(int i = 0; i < n; ++i){
  int k = 0;
   for(int j = 0; j < (2*n - 1); ++j){
      if(j < n-i-1 ){
        cout << " ";
      }else if(k < 2 * i + 1){
        if(k==0 || k == 2*i || i == n - 1){
        cout << "*";
        }else{
          cout << " ";
        }
        k++;
      }else{
        cout << " ";
      }
   }
   cout << endl;
}




      return 0;
}