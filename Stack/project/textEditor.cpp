#include<iostream>
#include<stack>
#include<string>

using namespace std;

// ⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐
//👉 C++ uses a stack to implement a simple text editor with undo/redo functionality

class TextEditor{
    private:
       stack<string> undoStack;
       stack<string> redoStack;
       string text;
    public: 
       TextEditor(){
        text = "";
       }
       void append(string str){
          undoStack.push(text);
          text += str;
       }
       void backspace(){
        if(text.length() > 0){
            undoStack.push(text);
            text.pop_back();
        }
       }
       void undo(){
        if(!undoStack.empty()){
            redoStack.push(text);
            text = undoStack.top();
            undoStack.pop();
        }
       }
       void redo(){
        if(!redoStack.empty()){
            undoStack.push(text);
            text = redoStack.top();
            redoStack.pop();
        }
       }

       void print(){
        cout << text << endl;
       }
};

int main(){
   TextEditor editor;

   editor.append("hello");
   editor.append(" world!");
   editor.print();  //output: hello world

   editor.backspace();
   editor.print();  // output: hello world without !

   editor.undo();
   editor.print();  //output: hello world!

   editor.redo();
   editor.print(); // output: Hello world

   return 0;

    

}