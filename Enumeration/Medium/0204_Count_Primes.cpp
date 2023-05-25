#include <iostream>
#include <vector>
using namespace std;

int countPrimes(int n)
{
    if (n <= 2)
        return 0;

    int output = n - 2;
    vector<bool> filtered(n, false);
    for (int i = 2; i * i < n; i++)
    {
        if (!filtered[i])
        {
            for (int j = i * i; j < n; j += i)
            {
                if (!filtered[j])
                {
                    output--;
                    filtered[j] = true;
                }
            }
        }
    }

    return output;
}

int main()
{
    int n;
    cin >> n;
    cout << countPrimes(n) << endl;

    return 0;
}
