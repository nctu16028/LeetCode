#include <iostream>
using namespace std;

int consecutiveNumbersSum(int n)
{
    int output = 1;
    for (int i = 2; n / i - (i-1) / 2 > 0; i++)
    {
        if (i % 2 == 0)
        {
            if ((double)n / (double)i == n / i + 0.5)
                output++;
        }
        else
        {
            if (n % i == 0)
                output++;
        }
    }

    return output;
}

int main()
{
    int n;
    cin >> n;
    cout << consecutiveNumbersSum(n) << endl;

    return 0;
}
