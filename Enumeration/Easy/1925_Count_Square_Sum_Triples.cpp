#include <iostream>
#include <cmath>
using namespace std;

int countTriples(int n)
{
    int output = 0;
    for (int a = 1; a < n; a++)
    {
        for (int b = 1; b < a; b++)
        {
            if (sqrt(a*a + b*b) > n)
                break;
            else if ((int)sqrt(a*a + b*b) * (int)sqrt(a*a + b*b) == a*a + b*b)
                output += 2;
        }
    }

    return output;
}

int main()
{
    int n;
    cin >> n;
    cout << countTriples(n) << endl;

    return 0;
}
