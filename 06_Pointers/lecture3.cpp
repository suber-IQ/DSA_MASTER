#include<iostream>
using namespace std;

void util(int* p){
    // p = p + 1;
    *p = *p + 1;
}

// void solve(int** ptr){
    // ptr = ptr + 1;
    // *ptr = *ptr + 1;
    // **ptr = **ptr + 1;
// }

void solve(int value){
    value++;
}
void solve1(int& value){ // pass by reference
    value++;
}
void solve3(int* value){
    *value = *value + 1;
}

int* solve5(){
    int a = 5;
    int *ans = &a;
    return ans;
}
int main(){

//  int a = 5;
//  int* p = &a;

//  int** q = &p;


// cout << &a << endl;
// cout << a << endl;
// cout << p << endl;
// cout << &p << endl;
// cout << *p << endl;
// cout << q << endl;
// cout << &q << endl;
// cout << *q << endl;
// cout << **q << endl;

// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

// int a = 5;

// int* p = &a;

// cout << "before" << endl;
// cout << a << endl;
// cout << p << endl;
// cout << *p << endl;

// util(p);

// cout << "after" << endl;
// cout << a << endl;
// cout << p << endl;
// cout << *p << endl;

// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

// int x = 12;
// int* p = &x;
// int** q = &p;

// solve(q);

// cout << x << endl;

// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟
// 👉 reference variable (same memory location different name)

// int a = 5;
// creating a reference variable
// int& b = a;

// cout << a << endl;
// cout << b << endl;

// a++;
// cout << a << endl;
// cout << b << endl;

// b++;
// cout << a << endl;
// cout << b << endl;
    
// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟
// 👉 reference variable (same memory location different name)


// 👉case 1:
// int a = 5;
// solve(a);
// cout << a << endl; //output: 5;

// 👉case 2:
int a = 5;
solve1(a);
cout << a << endl; //output: 6;

// 👉case 3:
int b = 12;
// int *p = &b;
// solve3(p);
solve3(&b);
cout << b << endl; //output: 

 cout << solve5() << endl;r
 

    return 0;
}