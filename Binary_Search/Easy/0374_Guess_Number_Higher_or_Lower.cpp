#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int pick;

int guess(int num)
{
    if (num > pick)
        return -1;
    else if (num < pick)
        return 1;
    else
        return 0;
}

int guessNumber(int n)
{
    if (guess(1) == 0)
        return 1;
    if (guess(n) == 0)
        return n;

    int left = 1, right = n;
    while (left < right)
    {
        int mid = ((long long int)left + (long long int)right) / 2;
        if (guess(mid) == -1)
            right = mid;
        else if (guess(mid) == 1)
            left = mid;
        else
            return mid;
    }

    return -1;  // should not reach here normally
}

int main()
{
    int n;
    cin >> n;

    srand(time(0));
    pick = rand() % n + 1;
    cout << guessNumber(n) << endl;

    return 0;
}
