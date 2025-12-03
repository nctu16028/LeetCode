#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height)
{
    int n = height.size();

    int leftMax = -1, leftMaxHeight = 0;
    vector<int> leftBarrier(n);
    for (int i = 0; i < n; i++)
    {
        if (height[i] > leftMaxHeight)
        {
            leftMaxHeight = height[i];
            leftMax = i;
        }
        leftBarrier[i] = leftMax;
    }

    int rightMax = -1, rightMaxHeight = 0;
    vector<int> rightBarrier(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (height[i] > rightMaxHeight)
        {
            rightMaxHeight = height[i];
            rightMax = i;
        }
        rightBarrier[i] = rightMax;
    }

    int output = 0;
    for (int i = 0; i < n; i++)
    {
        if (leftBarrier[i] != -1 && rightBarrier[i] != -1)
            output += (min(height[leftBarrier[i]], height[rightBarrier[i]]) - height[i]);
    }

    return output;
}

int main()
{
    int n;
    cin >> n;

    vector<int> height(n);
    for (int i = 0; i < n; i++)
        cin >> height[i];
    cout << trap(height) << endl;

    return 0;
}
