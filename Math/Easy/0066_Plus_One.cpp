#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits)
{
    vector<int> output = digits;
    int curr = output.size() - 1;
    output[curr]++;
    while (curr > 0 && output[curr] >= 10)
    {
        output[curr--] -= 10;
        output[curr]++;
    }
    if (output[0] >= 10)
    {
        output[0] -= 10;
        output.insert(output.begin(), 1);
    }

    return output;
}

int main()
{
    int n;
    cin >> n;

    vector<int> digits(n);
    for (int i = 0; i < n; i++)
        cin >> digits[i];

    vector<int> ans = plusOne(digits);
    cout << "[" << ans[0];
    for (int i = 1; i < ans.size(); i++)
        cout << ", " << ans[i];
    cout << "]" << endl;

    return 0;
}
