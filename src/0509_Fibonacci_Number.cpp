#include <iostream>
using namespace std;

int fib(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;

    int f_prev, f_curr = 0, f_next = 1;
    for (int i = 1; i < n; i++)
    {
        f_prev = f_curr;
        f_curr = f_next;
        f_next = f_prev + f_curr;
    }

    return f_next;
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl;

    return 0;
}
