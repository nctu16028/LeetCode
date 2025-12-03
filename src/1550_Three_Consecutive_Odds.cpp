#include <iostream>
#include <vector>
using namespace std;

bool threeConsecutiveOdds(vector<int>& arr) {
    int count = 0;
    for (const auto& num : arr) {
        if (num % 2)
            count++;
        else
            count = 0;

        if (count == 3)
            return true;
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << (threeConsecutiveOdds(arr) ? "true" : "false") << endl;

    return 0;
}
