#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int n)
{
    // [0] -> [0 1] -> [0 1 1 2] -> [0 1 1 2 1 2 2 3] -> ...
    vector<int> output(n+1, 0);
    int base = 1;
    for (int i = 1; i <= n; i++)
    {
        output[i] = output[i - base] + 1;
        if (i + 1 == base * 2)
            base *= 2;
    }

    return output;
}

int main()
{
    int n;
    cin >> n;

    vector<int> ans = countBits(n);
    cout << "[" << ans[0];
    for (int i = 1; i <= n; i++)
        cout << ", " << ans[i];
    cout << "]" << endl;

    return 0;
}
