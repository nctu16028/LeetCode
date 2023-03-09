#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height)
{
    int left_rod = 0, right_rod = height.size() - 1;
    int max_area = 0;
    while (left_rod != right_rod)
    {
        int area = (right_rod - left_rod) * min(height[left_rod], height[right_rod]);
        max_area = (area > max_area) ? area : max_area;

        if (height[left_rod] <= height[right_rod])
            left_rod++;
        else
            right_rod--;            
    }

    return max_area;
}

int main()
{
    int n;
    cin >> n;

    vector<int> height(n);
    for (int i = 0; i < n; i++)
        cin >> height[i];
    cout << maxArea(height) << endl;

    return 0;
}
