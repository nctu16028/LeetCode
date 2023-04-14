#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int evalRPN(vector<string>& tokens)
{
    stack<int> operands;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "+")
        {
            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();
            operands.push(a + b);
        }
        else if (tokens[i] == "-")
        {
            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();
            operands.push(a - b);
        }
        else if (tokens[i] == "*")
        {
            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();
            operands.push(a * b);
        }
        else if (tokens[i] == "/")
        {
            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();
            operands.push(a / b);
        }
        else
            operands.push(stoi(tokens[i]));
    }

    return operands.top();
}

int main()
{
    int n;
    cin >> n;

    vector<string> tokens(n);
    for (int i = 0; i < n; i++)
        cin >> tokens[i];
    cout << evalRPN(tokens) << endl;

    return 0;
}
