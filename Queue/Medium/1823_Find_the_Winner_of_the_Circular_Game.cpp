#include <iostream>
#include <queue>
using namespace std;

int findTheWinner(int n, int k)
{
    queue<int> circle;
    for (int i = 1; i <= n; i++)
        circle.push(i);

    int counter = 0;
    while (circle.size() > 1)
    {
        if (counter < k - 1)
        {
            circle.push(circle.front());
            circle.pop();
            counter++;
        }
        else
        {
            circle.pop();
            counter = 0;
        }
    }

    return circle.front();
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << findTheWinner(n, k) << endl;

    return 0;
}
