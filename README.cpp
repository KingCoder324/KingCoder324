- 👋 Hi, I’m @KingCoder324
- 👀 I’m interested in ...
- 🌱 I’m currently learning ...
- 💞️ I’m looking to collaborate on ...
- 📫 How to reach me ...

#include<iostream>
using namespace std;

class InfixToPostfix {
    char exp[20], s[20], x, item;
    int top;

public:
    void reading() {
        cout << "Enter Expression: ";
        cin >> exp;
    }

    void convert() {
        int i = 0;
        top = 0;
        push('(');

        while (exp[i] != '\0') {
            item = exp[i];

            if (isalpha(item)) {
                cout << item;
            } else if (item == '(') {
                push(item);
            } else if (item == ')') {
                while (s[top] != '(') {
                    cout << pop();
                }
                pop(); // Pop '('
            } else if (ISP(s[top]) >= ICP(item)) {
                cout << pop();
                push(item);
            } else if (ISP(s[top]) < ICP(item)) {
                push(item);
            } else {
                cout << "Invalid expression";
                exit(0);
            }

            i++;
        }

        // Pop remaining operators from the stack
        while (s[top] != '(') {
            cout << pop();
        }
    }

    void push(char item) {
        top++;
        s[top] = item;
    }

    char pop() {
        char data = s[top];
        top--;
        return data;
    }

    int ISP(char c) {
        switch (c) {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 3;
            case '%':
                return 9;
            case '(':
                return 0;
            default:
                return 0; // Add a default case
        }
    }

    int ICP(char c) {
        switch (c) {
            case '+':
            case '-':
                return 2;
            case '*':
            case '/':
                return 4;
            case '%':
                return 2;
            case '(':
                return 0;
            case ')':
                return 9;
            default:
                return 0; // Add a default case
        }
    }
};

int main() {
    cout << "\n\t\t\tINFIX TO POSTFIX CONVERSION" << endl;
    cout << "\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;

    InfixToPostfix p;
    p.reading();
    p.convert();

    return 0;
}

