#include <iostream>
#include <vector>
using namespace std;

vector<int> grayCode(int n)
{
    /*
     * n = 1: 0, 1
     * n = 2: 0[0], 0[1], 1[1], 1[0]
     * n = 3: 0[00], 0[01], 0[11], 0[10], 1[10], 1[11], 1[01], 1[00]
     * ...
     */

    vector<int> output(1, 0);
    for (int i = 0; i < n; i++)
    {
        int adder = (1 << i);
        int currSize = output.size();
        for (int j = currSize - 1; j >= 0; j--)
            output.push_back(output[j] + adder);
    }

    return output;
}

int main()
{
    int n;
    cin >> n;

    vector<int> ans = grayCode(n);
    cout << "[" << ans[0];
    for (int i = 1; i < ans.size(); i++)
        cout << ", " << ans[i];
    cout << "]" << endl;

    return 0;
}
