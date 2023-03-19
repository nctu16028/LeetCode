#include <iostream>
#include <string>
using namespace std;

string addBinary(string a, string b)
{
    // Pad the shorter one with enough 0
    if (a.length() > b.length())
        b = string(a.length() - b.length(), '0') + b;
    else if (a.length() < b.length())
        a = string(b.length() - a.length(), '0') + a;

    // Simulate a ripple carry adder
    bool carry_bit = 0;
    string sum(a.length(), '0');
    for (int i = a.length() - 1; i >= 0; i--)
    {
        bool a_bit = a[i] - '0';
        bool b_bit = b[i] - '0';
        sum[i] = static_cast<char>((a_bit ^ b_bit ^ carry_bit) + '0');
        carry_bit = ((a_bit | b_bit) & carry_bit) | (a_bit & b_bit);
    }
    if (carry_bit == 1)
        sum = "1" + sum;

    return sum;
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << addBinary(a, b) << endl;

    return 0;
}
