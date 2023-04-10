#include <iostream>
using namespace std;

int numTrees(int n)
{
    // Number of unique BSTs with n nodes = the n-th Catalan number
    long long int output = 1;
    int numerator = 2 * n;
    int denominator = 1;
    for (; denominator <= n; numerator--, denominator++)
        output = output * numerator / denominator;
    output /= (n + 1);

    return output;
}

int main()
{
    int n;
    cin >> n;
    cout << numTrees(n) << endl;

    return 0;
}
