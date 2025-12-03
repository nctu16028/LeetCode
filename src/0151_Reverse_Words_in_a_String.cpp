#include <iostream>
#include <vector>
#include <string>
using namespace std;

string reverseWords(string s) {
    vector<int> idx;
    bool isSpace = true;
    for (int i = 0; i < s.length(); i++) {
        if (isSpace && s[i] != ' ') {
            idx.push_back(i);
            isSpace = false;
        }
        else if (!isSpace && s[i] == ' ') {
            idx.push_back(i);
            isSpace = true;
        }
    }
    if (!isSpace)
        idx.push_back(s.length());

    string output = "";
    int j = idx.size() - 2;
    if (!idx.empty())
        output += s.substr(idx[j], idx[j + 1] - idx[j]);
    for (j -= 2; j >= 0; j -= 2) {
        output += " ";
        output += s.substr(idx[j], idx[j + 1] - idx[j]);
    }

    return output;
}

int main() {
    string s;
    getline(cin, s);
    cout << reverseWords(s) << endl;

    return 0;
}
