#include <iostream>
using namespace std;

int twoEggDrop(int n)
{
    int i = 1;
    while (i * (i + 1) / 2 < n)
        i++;

    return i;
}

int main()
{
    int n;
    cin >> n;
    cout << twoEggDrop(n) << endl;

    return 0;
}
