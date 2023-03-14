#include <iostream>
#include <unordered_set>
using namespace std;

bool isHappy(int n)
{
    unordered_set<int> history;
    while (n != 1)
    {
        if (history.count(n) == 1)
            return false;

        history.insert(n);
        int prev = n;
        n = 0;
        while (prev > 0)
        {
            int digit = prev % 10;
            prev /= 10;
            n += (digit * digit);
        }
    }

    return true;
}

int main()
{
    int n;
    cin >> n;
    cout << (isHappy(n) ? "true" : "false") << endl;

    return 0;
}
