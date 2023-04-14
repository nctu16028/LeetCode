#include <iostream>
#include <string>
using namespace std;

string removeDuplicates(string s)
{
    string output = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (output.length() > 0 && s[i] == output.back())
            output.pop_back();
        else
            output += s[i];
    }

    return output;
}

int main()
{
    string s;
    cin >> s;
    cout << removeDuplicates(s) << endl;

    return 0;
}
