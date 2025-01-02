#include<iostream>
using namespace std;


int main(){

      // int n;
      // if(cin>>n){
      //       cout << "Welcome";
      // }
      // // if(cout << "hello"){
      // //       cout << "Sumit" << endl;
      // // }


// Testing
      // string name;
      // int age;

      // cin>>name>>age;

      // cout << "Name: " << name << endl;
      // cout << "Age: " << age << endl;


// Eligiable to vote
  string name;
      int age;

      cin>>name>>age;
      
      if(age>=18){
            cout << name << " is eligible to vote" << endl;
      }else{
            cout << name << " is not eligible to vote" << endl;
      }

      return 0;
}