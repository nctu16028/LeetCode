#include <iostream>
#include <vector>
#include <string>
using namespace std;

string simplifyPath(string path)
{
    // Tokenize the string and remove unnecessary tokens
    vector<string> tokens;
    string token;
    char delimiter = '/';
    int prevSlashPos = -1;
    size_t slashPos = path.find(delimiter);
    while (slashPos != string::npos)
    {
        token = path.substr(prevSlashPos + 1, slashPos - (prevSlashPos + 1));
        if (token.length() == 0 || token == "." || (tokens.empty() && token == "..")) {}
        else if (!tokens.empty() && token == "..")
            tokens.pop_back();
        else
            tokens.push_back(token);

        prevSlashPos = slashPos;
        slashPos = path.find(delimiter, slashPos + 1);
    }
    token = path.substr(prevSlashPos + 1);  // this is the part after the last one slash character
    if (token.length() == 0 || token == "." || (tokens.empty() && token == "..")) {}
    else if (!tokens.empty() && token == "..")
        tokens.pop_back();
    else
        tokens.push_back(token);

    // Build simplified path
    string output = "/";
    for (int i = 0; i < tokens.size(); i++)
    {
        if (i > 0)
            output += "/";
        output += tokens[i];
    }

    return output;
}

int main()
{
    string path;
    cin >> path;
    cout << simplifyPath(path) << endl;

    return 0;
}
