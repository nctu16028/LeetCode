#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

/*bool isValidSerialization(string preorder)
{
    // Tokenize the string
    vector<string> tokens;
    char delimiter = ',';
    int prevCommaPos = -1;
    size_t commaPos = preorder.find(delimiter);
    while (commaPos != string::npos)
    {
        tokens.push_back(preorder.substr(prevCommaPos + 1, commaPos - (prevCommaPos + 1)));
        prevCommaPos = commaPos;
        commaPos = preorder.find(delimiter, commaPos + 1);
    }
    tokens.push_back(preorder.substr(prevCommaPos + 1));

    // Verification
    stack<string> checker;
    for (int i = 0; i < tokens.size(); i++)
    {
        // When the second "#" is pushed into the stack, pop two "#", one number, and then push one "#"
        if (tokens[i] == "#" && !checker.empty() && checker.top() == "#")
        {
            while (!checker.empty() && checker.top() == "#")
            {
                checker.pop();
                if (checker.empty())
                    return false;
                checker.pop();
            }
        }
        checker.push(tokens[i]);
    }

    return (checker.size() == 1 && checker.top() == "#");
}*/

// Less memory version
bool isValidSerialization(string preorder)
{
    int node_checker = 1;
    string token;
    char delimiter = ',';
    int prevCommaPos = -1;
    size_t commaPos = preorder.find(delimiter);
    while (commaPos != string::npos)
    {   
        token = preorder.substr(prevCommaPos + 1, commaPos - (prevCommaPos + 1));
        node_checker--;
        if (node_checker < 0)
            return false;
        if (token != "#")
            node_checker += 2;

        prevCommaPos = commaPos;
        commaPos = preorder.find(delimiter, commaPos + 1);
    }

    token = preorder.substr(prevCommaPos + 1);
    node_checker--;
    if (node_checker < 0)
        return false;
    if (token != "#")
        node_checker += 2;

    return (node_checker == 0);
}

int main()
{
    string preorder;
    cin >> preorder;
    cout << (isValidSerialization(preorder) ? "true" : "false") << endl;

    return 0;
}
