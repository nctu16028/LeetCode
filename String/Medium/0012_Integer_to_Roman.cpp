#include <iostream>
#include <vector>
#include <string>
using namespace std;

string intToRoman(int num)
{
    vector<pair<int, string>> dict = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"},
        {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    string output = "";
    for (int i = 0; i < dict.size(); i++)
    {
        while (num >= dict[i].first)
        {
            output += dict[i].second;
            num -= dict[i].first;
        }
    }

    return output;
}

int main()
{
    int num;
    cin >> num;
    cout << intToRoman(num) << endl;

    return 0;
}
