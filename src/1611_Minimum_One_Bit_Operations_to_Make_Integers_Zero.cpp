#include <iostream>
using namespace std;

int minimumOneBitOperations(int n)
{
    int output = 0;
    unsigned int mask = 2;
    while (n > 0)
    {
        if (n % 2)
            output = (mask - 1) - output;
        mask *= 2;
        n /= 2;
    }

    return output;
}

int main()
{
    int n;
    cin >> n;
    cout << minimumOneBitOperations(n) << endl;

    return 0;
}

/*
Observation:
1000 -> 1001 -> 1011 -> 1010 -> 1110 -> 1111 -> 1101 -> 1100 -> 100 -> 101 -> 111 -> 110 -> 10 -> 11 -> 1 -> 0
*/
