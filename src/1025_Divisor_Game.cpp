#include <iostream>
#include <vector>
using namespace std;

bool divisorGame(int n)
{
    vector<bool> canAliceWin(n + 1, false);
    for (int i = 2; i <= n; i++)
    {
        for (int div = 1; div < i; div++)
        {
            if (i % div == 0 && !canAliceWin[i - div])
            {
                canAliceWin[i] = true;
                break;
            }
        }
    }

    return canAliceWin[n];
}

int main()
{
    int n;
    cin >> n;
    cout << (divisorGame(n) ? "true" : "false") << endl;

    return 0;
}
