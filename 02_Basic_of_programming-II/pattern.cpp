#include<iostream>
using namespace std;


int main(){


// ❓ 1️⃣5️⃣ Solid Diamond star pattern
           // *
        //   * *
        //  * * *
        // * * * *
       // * * * * *
       // * * * * *
       //  * * * *
       //   * * *
        //   * *
       //     *
//      int n;
//      cout << "Enter value of n: " << endl;
//      cin>>n;

//      for(int i = 0; i < n; ++i){
//       //   space
//         for(int j = 0; j < n - i - 1; ++j)
//           cout << " ";
//       //   star
//         for(int k = 0; k < i + 1; ++k)
//           cout << "* ";
//       cout << endl;
//      }
//      for(int i = 0; i < n; ++i){
//       //  space
//        for(int j = 0; j < i; ++j)
//          cout << " ";
//       // star
//         for(int k = 0; k < n - i; ++k)
//           cout << "* ";
//       cout << endl;
//      }

// ❓ 1️⃣6️⃣ Hollow Diamond pattern

//      *
//     * *
//    *   *
//   *     *
//  *       *
// *         *
// *         *
//  *       *
//   *     *
//    *   *
//     * *
//      *

// int n;
//   cout << "Enter Value of n: ";
//   cin >> n;
//   for (int i = 0; i < n; ++i) {
//     // space
//     for (int j = 0; j < n - i - 1; ++j) {
//       cout << " ";
//     }
//     // star
//     for (int j = 0; j < 2 * i + 1; ++j) {
//       if (j == 0 || j == 2 * i) {
//         cout << "*";
//       } else {
//         cout << " ";
//       }
//     }
//     cout << endl;
//   }
//   for (int i = 0; i < n; ++i) {
//     // space
//     for (int j = 0; j < i; ++j) {
//       cout << " ";
//     }
//     // star
//     for (int j = 0; j < ((2 * n) - (2 * i)) - 1; ++j) {
//       if (j == 0 || j == ((2 * n) - (2 * i) - 2)) {
//         cout << "*";
//       } else {
//         cout << " ";
//       }
//     }
//     cout << endl;
//   }

// ❓ 1️⃣7️⃣ Flipped Solid Diamond pattern

// **********
// ****  ****
// ***    ***
// **      **
// *        *
// *        *
// **      **
// ***    ***
// ****  ****
// **********

// int n;
// cout << "Enter value of n: " << endl;
// cin>>n;

// for(int i = 0; i < n; ++i){
//       // left
//    for(int j = 0; j < n - i; ++j){
//       cout << "*";
//    }
//   // middle
//   for(int j = 0; j < 2*i; ++j){
//       cout << " ";
//   }
// //   right
// for(int j = 0; j < n - i; ++j){
//       cout << "*";
// }
   
//    cout << endl;
// }

// for(int i = 0; i < n; ++i){
//       // left
//       for(int j = 0; j < i + 1; ++j){
//             cout << "*";
//       }
//       // middle
//       for(int j = 0; j < ((2*n) - (2*i) - 2); ++j){
//             cout << " ";
//       }
//       // right
//       for(int j = 0; j < i + 1; ++j){
//             cout << "*";
//       }
//       cout << endl;
// }

// ❓ 1️⃣8️⃣ Fancy Pattern


// 1
// 2*2
// 3*3*3
// 4*4*4*4
// 5*5*5*5*5
// 5*5*5*5*5
// 4*4*4*4
// 3*3*3
// 2*2
// 1
// int n;
// cout << "Enter value of n: " << endl;
// cin>>n;

// for(int i = 0; i < n; ++i){
//    for(int j = 0; j < i + 1; ++j){
//       cout << i + 1;
//       if(j != i){
//             cout << "*";
//       }
//    }      
//    cout << endl;
// }
// for(int i = 0; i < n; ++i){
//       for(int j = 0; j < n - i; ++j){
//             cout << n - i;
//             if(j != n - i - 1){
//                   cout << "*";
//             }
//       }
//       cout << endl;
// }

// ❓ 1️⃣9️⃣ Alphabet Palindrome Pyramid



// 1
// 121
// 12321
// 1234321
// 123454321

// A
// ABA
// ABCBA
// ABCDCBA
// ABCDEDCBA


//  int n;
//   cout << "Enter Value of n: ";
//   cin >> n;
//   for(int i = 0; i < n; ++i){
//     int j = 0;
//     for(; j < i + 1; ++j){
//       int ans = j + 1;
//       char ch = ans + 'A' - 1;
//       // cout << j + 1;
//       cout << ch;
//     }
//     j = j - 1;
//     for(; j; --j){
//       char ch = j + 'A' - 1;
//       // cout << j;
//       cout << ch;
//     }
//     cout << endl;
//   }


      return 0;
}