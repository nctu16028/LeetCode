#include <iostream>
using namespace std;

int climbStairs(int n)
{
    // n steps = 1 step + (n-1) steps = 2 steps + (n-2) steps
    // Recurrence relation: climbStairs(n) = climbStairs(n-1) + climbStairs(n-2)
    int dp_table[1+45] = {0};
    dp_table[1] = 1;
    dp_table[2] = 2;
    for (int i = 3; i <= n; i++)
        dp_table[i] = dp_table[i-1] + dp_table[i-2];

    return dp_table[n];
}

int main()
{
    int n;
    cin >> n;
    cout << climbStairs(n) << endl;

    return 0;
}
