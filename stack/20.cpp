/* Valid Parenthesis

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s) {
    stack<char> stack;
    for (const auto& c : s) {
        switch(c) {
            case '{':
                stack.push('}');
                break;
            case '(':
                stack.push(')');
                break;
            case '[':
                stack.push(']');
                break;
            default:
                if (stack.empty() || c != stack.top()) return false;
                else stack.pop();
        }
    }
    return stack.empty();
}

int main() {
    string str;
    cin >> str;
    cout << boolalpha;
    cout << bool(isValid(str)) << "\n";
    return 0;
}