#include <iostream>
#include <string>
using namespace std;

string removeKdigits(string num, int k)
{
    string output = "";
    for (int i = 0; i < num.length(); i++)
    {
        // Greedily replace the last character with the smaller one until k reaches 0
        while (output.length() > 0 && num[i] < output.back() && k > 0)
        {
            output.pop_back();
            k--;
        }
        if (!(output.length() == 0 && num[i] == '0'))   // ignore the leading zeros
            output += num[i];
    }

    while (output.length() > 0 && k > 0)
    {
        output.pop_back();
        k--;
    }

    if (output.length() == 0)
        output = "0";

    return output;
}

int main()
{
    string num;
    cin >> num;

    int k;
    cin >> k;
    cout << removeKdigits(num, k) << endl;

    return 0;
}
