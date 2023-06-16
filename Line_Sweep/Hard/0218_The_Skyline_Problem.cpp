#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
{
    // Gather all the corner points
    vector<pair<int, int>> corners;
    for (int i = 0; i < buildings.size(); i++)
    {
        corners.push_back(make_pair(buildings[i][0], -buildings[i][2]));    // add left corner of building i (use negative height)
        corners.push_back(make_pair(buildings[i][1], buildings[i][2]));     // add right corner of building i (use positive height)
    }
    sort(corners.begin(), corners.end());

    // Locate the key points of skyline by line sweeping
    vector<vector<int>> output;
    multiset<int> heightSet;
    heightSet.insert(0);    // add the ground level
    int prevHighest = 0, currHighest = 0;
    for (auto& corner : corners)
    {
        int xPos = corner.first;
        int height = corner.second;
        if (height < 0)     // encounter left corner of a building
            heightSet.insert(-height);
        else                // encounter right corner of a building
            heightSet.erase(heightSet.find(height));

        currHighest = *(heightSet.rbegin());
        if (currHighest != prevHighest)     // if the highest level changes, the corner contributes a key point to the skyline
        {
            output.push_back(vector<int>({xPos, currHighest}));
            prevHighest = currHighest;
        }
    }

    return output;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> buildings(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        cin >> buildings[i][0] >> buildings[i][1] >> buildings[i][2];

    vector<vector<int>> ans = getSkyline(buildings);
    cout << "[[" << ans[0][0] << ", " << ans[0][1] << "]";
    for (int i = 1; i < ans.size(); i++)
        cout << ", [" << ans[i][0] << ", " << ans[i][1] << "]";
    cout << "]" << endl;

    return 0;
}
