#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string getPermutation(int n, int k)
{
    int factorial[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    bool isChoosed[9] = {false};    // isChoosed[i] means the number i+1 is choosed

    k--;    // change to 0-indexed
    string output = "";
    for (int i = n - 1; i > 0; i--)
    {
        // Choose the toChoose-th number that has not been chosen
        int toChoose = k / factorial[i] + 1;
        k %= factorial[i];
        for (int j = 0; j < n; j++)
        {
            if (!isChoosed[j])
                toChoose--;
            if (toChoose == 0)
            {
                output += to_string(j + 1);
                isChoosed[j] = true;
                break;
            }
        }
    }

    // Append the remaining one that has not been chosen
    for (int j = 0; j < n; j++)
    {
        if (!isChoosed[j])
        {
            output += to_string(j + 1);
            break;
        }
    }

    return output;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << getPermutation(n, k) << endl;

    return 0;
}
