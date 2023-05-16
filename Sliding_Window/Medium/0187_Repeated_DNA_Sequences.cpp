#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<string> findRepeatedDnaSequences(string s)
{
    vector<string> output;
    unordered_map<string, int> seqFreq;
    for (int i = 0; i < (int)s.length() - 9; i++)
    {
        string seq = s.substr(i, 10);
        if (seqFreq.find(seq) == seqFreq.end())
            seqFreq.insert({seq, 1});
        else
        {
            if (seqFreq[seq] == 1)
                output.push_back(seq);
            seqFreq[seq]++;
        }
    }

    return output;
}

int main()
{
    string s;
    cin >> s;

    vector<string> ans = findRepeatedDnaSequences(s);
    cout << "[";
    if (!ans.empty())
    {
        cout << "\"" << ans[0] << "\"";
        for (int i = 1; i < ans.size(); i++)
            cout << ", \"" << ans[i] << "\"";
    }
    cout << "]" << endl;

    return 0;
}
