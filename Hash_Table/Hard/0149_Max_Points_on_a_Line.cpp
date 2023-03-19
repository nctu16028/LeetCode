#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define INFINITY 100000

int maxPoints(vector<vector<int>>& points)
{
    if (points.size() <= 2)
        return points.size();

    int output = 2;
    for (int i = 0; i < points.size() - 1; i++)
    {
        unordered_map<double, int> slopeFrequency;
        for (int j = i + 1; j < points.size(); j++)
        {
            double slope;
            if (points[i][0] == points[j][0])
                slope = INFINITY;
            else
                slope = (double)(points[i][1] - points[j][1]) / (double)(points[i][0] - points[j][0]);

            if (slopeFrequency.count(slope) > 0)
                slopeFrequency[slope]++;
            else
                slopeFrequency.insert({slope, 2});
        }

        for (auto& s : slopeFrequency)
            output = max(output, s.second);
        slopeFrequency.clear();
    }

    return output;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> points(n);
    for (int i = 0; i < n; i++)
    {
        points[i] = vector<int>(2);
        cin >> points[i][0] >> points[i][1];
    }
    cout << maxPoints(points) << endl;

    return 0;
}
