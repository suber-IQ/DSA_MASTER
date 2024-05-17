#include<iostream>
using namespace std;

int fact(int n){
    // base condition/case
    if(n == 1)
      return 1;

    // recursive call/recursive relation
    int ans = n * fact(n - 1);
    return ans;

    //processing (optional)
}
void printCounting(int n){
    // base case 
    if(n == 0) return;

    // processing (optional) (reverse printing)
    cout << n << " ";

    //recusively call/recursive relation
     printCounting(n - 1);

      // processing (optional) (normal 1 to n printing)
    // cout << n << " ";
}

int fib(int n){
    if(n == 1){
        //first term
        return 0;
    }
    if(n == 2){
        //second term
        return 1;
    }

    //RR- f(n) = f(n-1) + f(n-2);
    int ans = fib(n-1) + fib(n-2);
    return ans;


}

int main(){

    // 1️⃣  Recurstion with Factorial 
    // int n;
    // cout << "Enter the value of n: " << endl;
    // cin>>n;

    // int ans = fact(n);

    // cout << "Answer: " << ans << endl;

    // 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

    // 2️⃣ print counting

    // int n;
    // cout << "Enter the value of n: " << endl;
    // cin>>n;

//    printCounting(n);    

    // 🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

    // 3️⃣ fibonacci series
    // 0,1,1,2,3,5,8,13,21..

   int n;
   cout << "Enter the term you want to see" << endl;
   cin>>n;

   int ans = fib(n);
   cout << n << "the term is: "<< ans << endl;
   

    return 0;
}