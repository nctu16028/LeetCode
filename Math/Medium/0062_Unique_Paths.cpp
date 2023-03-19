#include <iostream>
using namespace std;

int uniquePaths(int m, int n)
{
    // The answer is C(m-1+n-1, m-1) = C(m-1+n-1, n-1)
    int ans = 1;
    int N = min(m-1, n-1);
    for (int i = 1; i <= N; i++)
    {
        ans *= ((m + n - 2) - i + 1);
        ans /= i;
    }

    return ans;
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << uniquePaths(m, n) << endl;

    return 0;
}
