#include <iostream>
#include <vector>
using namespace std;

int longestMountain(vector<int>& arr)
{
    int n = arr.size();
    if (n < 3)
        return 0;

    char phase = 'i';   // a: ascending phase, d: descending phase, i: invalid
    int output = 0;
    int startTag = 0;
    for (int i = 1; i < n; i++)
    {
        if (phase == 'a')
        {
            if (arr[i] == arr[i - 1])
                phase = 'i';
            else if (arr[i] < arr[i - 1])
                phase = 'd';
        }
        else if (phase == 'd')
        {
            if (arr[i] == arr[i - 1])
            {
                output = max(output, i - startTag);
                phase = 'i';
            }
            else if (arr[i] > arr[i - 1])
            {
                output = max(output, i - startTag);
                phase = 'a';
                startTag = i - 1;
            }
        }
        else
        {
            if (arr[i] > arr[i - 1])
            {
                phase = 'a';
                startTag = i - 1;
            }
        }
    }

    if (phase == 'd')
        output = max(output, n - startTag);

    return output;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << longestMountain(arr) << endl;

    return 0;
}
