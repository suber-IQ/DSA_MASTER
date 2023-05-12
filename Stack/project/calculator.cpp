#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟
// 👉 C++ that uses a stack to implement a simple calculator that can handle basic arithmetic operations:

class Calculator {
public:
    void pushNumber(int num);
    void pushOperator(char op);
    int calculate();

private:
    stack<int> numStack;
    stack<char> opStack;

    int performOperation(char op, int left, int right);
};

void Calculator::pushNumber(int num) {
    numStack.push(num);
}

void Calculator::pushOperator(char op) {
    if (op == '(') {
        opStack.push(op);
    } else if (op == ')') {
        while (opStack.top() != '(') {
            int right = numStack.top();
            numStack.pop();
            int left = numStack.top();
            numStack.pop();
            char op = opStack.top();
            opStack.pop();

            int result = performOperation(op, left, right);

            numStack.push(result);
        }
        opStack.pop(); // remove the left parenthesis
    } else if (op == '+' || op == '-' || op == '*' || op == '/') {
        while (!opStack.empty() && (opStack.top() == '*' || opStack.top() == '/') && opStack.top() != '(') {
            int right = numStack.top();
            numStack.pop();
            int left = numStack.top();
            numStack.pop();
            char op2 = opStack.top();
            opStack.pop();

            int result = performOperation(op2, left, right);

            numStack.push(result);
        }
        opStack.push(op);
    }
}

int Calculator::calculate() {
    while (!opStack.empty()) {
        int right = numStack.top();
        numStack.pop();
        int left = numStack.top();
        numStack.pop();
        char op = opStack.top();
        opStack.pop();

        int result = performOperation(op, left, right);

        numStack.push(result);
    }

    return numStack.top();
}

int Calculator::performOperation(char op, int left, int right) {
    int result;
    switch (op) {
        case '+':
            result = left + right;
            break;
        case '-':
            result = left - right;
            break;
        case '*':
            result = left * right;
            break;
        case '/':
            result = left / right;
            break;
    }

    return result;
}

int main() {
    Calculator calc;

    string expr;
    cout << "Enter an arithmetic expression: ";
    getline(cin, expr);

    int num = 0;
    for (int i = 0; i < expr.length(); i++) {
        if (isdigit(expr[i])) {
            num = num * 10 + (expr[i] - '0');
        } else {
            if (num != 0) {
                calc.pushNumber(num);
                num = 0;
            }
            calc.pushOperator(expr[i]);
        }
    }
    if (num != 0) {
        calc.pushNumber(num);
    }

    int result = calc.calculate();
    cout << "Result: " << result << endl;

    return 0;
}
