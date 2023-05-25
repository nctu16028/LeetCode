#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int partition(vector<int>& nums, int head, int tail)
{
    // Use randomization to diminish the effect of worst cases
    srand(time(0)); 
    int pivot_idx = head + rand() % (tail - head + 1);
    swap(nums[pivot_idx], nums[tail]);

    // The tail is chosen as the pivot
    int i = head - 1;                   // [head, i] is the interval whose elements are smaller than pivot
    for (int j = head; j < tail; j++)   // [i+1, j-1] is the interval whose elements are larger than pivot
    {
        if (nums[j] <= nums[tail])
        {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[tail]);      // move the pivot to the right place

    return i + 1;
}

void quicksort(vector<int>& nums, int head, int tail)
{
    if (head >= tail)
        return;

    // Identify extreme cases
    bool sorted = true;
    for (int i = head + 1; i <= tail; i++)
    {
        if (nums[i] < nums[i - 1])
        {
            sorted = false;
            break;
        }
    }

    if (!sorted)
    {
        int pivot = partition(nums, head, tail);
        quicksort(nums, head, pivot - 1);
        quicksort(nums, pivot + 1, tail);
    }
}

vector<int> sortArray(vector<int>& nums)
{
    quicksort(nums, 0, nums.size() - 1);
    return nums;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> ans = sortArray(nums);
    cout << "[" << ans[0];
    for (int i = 1; i < n; i++)
        cout << ", " << ans[i];
    cout << "]" << endl;

    return 0;
}
