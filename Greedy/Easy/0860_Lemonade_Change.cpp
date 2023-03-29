#include <iostream>
#include <vector>
using namespace std;

bool lemonadeChange(vector<int>& bills)
{
    int count5 = 0, count10 = 0;
    for (auto& bill : bills)
    {
        if (bill == 5)
            count5++;
        else if (bill == 10)    // return a $5
        {
            if (count5 > 0)
            {
                count5--;
                count10++;
            }
            else
                return false;
        }
        else    // return a $10 and a $5, or return three $5
        {
            if (count10 > 0 && count5 > 0)
            {
                count10--;
                count5--;
            }
            else if (count5 >= 3)
                count5 -= 3;
            else
                return false;
        }
    }

    return true;
}

int main()
{
    int n;
    cin >> n;

    vector<int> bills(n);
    for (int i = 0; i < n; i++)
        cin >> bills[i];
    cout << (lemonadeChange(bills) ? "true" : "false") << endl;

    return 0;
}
