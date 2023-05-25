#include <iostream>
#include <vector>
using namespace std;

int fastModExp(int a, int b)
{
    if (b == 1)
        return a;

    int half = fastModExp(a, b / 2);
    int ans = (half * half) % 1337;
    if (b % 2 == 1)
        ans = (ans * a) % 1337;

    return ans;
}

int superPow(int a, vector<int>& b)
{
    // Euler's theorem: a^phi(n) mod n == 1
    // => a^b mod 1337 == a^(b mod phi(1337)) mod 1337
    int exp = 0;
    for (auto digit : b)
        exp = (10 * exp + digit) % 1140;    // phi(1337) = phi(7*191) = (7-1)*(191-1) = 1140

    return fastModExp(a % 1337, exp);
}

int main()
{
    int a, n;
    cin >> a >> n;

    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    cout << superPow(a, b) << endl;

    return 0;
}
