#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Optimized version (Reference: https://leetcode.com/problems/minimum-window-substring/solutions/26808/here-is-a-10-line-template-that-can-solve-most-substring-problems/)
string minWindow(string s, string t)
{
    // Count each character of t
    vector<int> tmap(128, 0);
    for (auto& c : t)
        tmap[c]++;

    int left = 0, counter = t.length();
    int optHead = 0, optLen = INT_MAX;
    for (int right = 0; right < s.length(); right++)
    {
        // Expanding phase: move "right" to cover characters of t
        if (tmap[s[right]] > 0)
            counter--;
        tmap[s[right]]--;

        while (counter == 0)    // when all characters of t have been covered
        {
            // Update the solution if needed
            if (right - left + 1 < optLen)
            {
                optHead = left;
                optLen = right - left + 1;
            }

            // Shrinking phase: move "left" to minimize the window but keeping all characters of t covered
            if (tmap[s[left]] == 0)
                counter++;
            tmap[s[left]]++;
            left++;
        }
    }

    return (optLen == INT_MAX) ? "" : s.substr(optHead, optLen);
}

// Original version
/*string minWindow(string s, string t)
{
    // Count each character of t
    unordered_map<char, int> tmap, windowCount;
    for (auto& c : t)
    {
        if (tmap.find(c) == tmap.end())
        {
            windowCount.insert({c, 0});
            tmap.insert({c, 1});
        }
        else
            tmap[c]++;
    }

    // Move the left bound to reach the first character that appears in t
    int left = 0;
    while (left < s.length() && tmap.find(s[left]) == tmap.end())
        left++;
    if (left == s.length())
        return "";

    int optHead = 0, optLen = INT_MAX;
    for (int right = left; right < s.length(); right++)
    {
        // Expanding phase: move "right" to cover characters of t
        if (tmap.find(s[right]) != tmap.end())
            windowCount[s[right]]++;

        bool shrinkable = true;
        for (auto& it : tmap)
        {
            char key = it.first;
            if (windowCount[key] < tmap[key])
            {
                shrinkable = false;
                break;
            }
        }

        while (left <= right && shrinkable)     // when all characters of t have been covered
        {
            // Update the solution if needed
            if (right - left + 1 < optLen)
            {
                optHead = left;
                optLen = right - left + 1;
            }

            // Shrinking phase: move "left" to minimize the window but keeping all characters of t covered
            if (tmap.find(s[left]) != tmap.end())
            {
                windowCount[s[left]]--;
                if (windowCount[s[left]] < tmap[s[left]])
                    shrinkable = false;
            }
            left++;
        }
    }

    return (optLen == INT_MAX) ? "" : s.substr(optHead, optLen);
}*/

int main()
{
    string s, t;
    cin >> s >> t;
    cout << minWindow(s, t) << endl;

    return 0;
}
