#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string largestNumber(vector<int>& nums)
{
    vector<string> numStrs;
    for (auto& num : nums)
        numStrs.push_back(to_string(num));

    struct
    {
        bool operator()(string a, string b) const { return a + b > b + a; }
    } customLess;
    sort(numStrs.begin(), numStrs.end(), customLess);

    string output = "";
    if (numStrs[0] == "0")
        output += '0';
    else
    {
        for (auto& s : numStrs)
            output += s;
    }

    return output;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << largestNumber(nums) << endl;

    return 0;
}
