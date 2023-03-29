#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int candy(vector<int>& ratings)
{
    int n = ratings.size();
    if (n == 1)
        return 1;

    // Create another list for sorting
    vector<pair<int, int>> ratingIndexPairs;
    for (int i = 0; i < n; i++)
        ratingIndexPairs.push_back(make_pair(ratings[i], i));

    // Sort the list by the ratings mainly
    struct
    {
        bool operator()(pair<int, int> a, pair<int, int> b) const
        {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        }
    } customLess;
    sort(ratingIndexPairs.begin(), ratingIndexPairs.end(), customLess);

    // Distribute candies from lowest-rating child to highest-rating child
    vector<int> candies(n, 1);
    for (auto& rip : ratingIndexPairs)
    {
        int idx = rip.second;   // rip.first == ratings[idx]
        if (idx == 0)
        {
            if (ratings[0] > ratings[1])
                candies[0] = 1 + candies[1];
        }
        else if (idx == n - 1)
        {
            if (ratings[n - 1] > ratings[n - 2])
                candies[n - 1] = 1 + candies[n - 2];
        }
        else
        {
            if (ratings[idx] > ratings[idx - 1] && ratings[idx] > ratings[idx + 1])
                candies[idx] = 1 + max(candies[idx - 1], candies[idx + 1]);
            else if (ratings[idx] > ratings[idx - 1])
                candies[idx] = 1 + candies[idx - 1];
            else if (ratings[idx] > ratings[idx + 1])
                candies[idx] = 1 + candies[idx + 1];
        }
    }

    // Count the total number of candies
    int output = 0;
    for (auto& c : candies)
        output += c;

    return output;
}

int main()
{
    int n;
    cin >> n;

    vector<int> ratings(n);
    for (int i = 0; i < n; i++)
        cin >> ratings[i];
    cout << candy(ratings) << endl;

    return 0;
}
