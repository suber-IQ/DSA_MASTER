#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(string expr) {
    stack<char> st;

    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            st.push(expr[i]);
        } else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}') {
            if (st.empty()) {
                return false;
            }
            char top = st.top();
            st.pop();
            if ((expr[i] == ')' && top != '(') || 
                (expr[i] == ']' && top != '[') || 
                (expr[i] == '}' && top != '{')) {
                return false;
            }
        }
    }

    return st.empty();
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr);

    if (isBalanced(expr)) {
        cout << "The expression is balanced." << endl;
    } else {
        cout << "The expression is not balanced." << endl;
    }

    return 0;
}
