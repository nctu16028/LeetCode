#include <iostream>
#include <queue>
using namespace std;

class RecentCounter {
public:
    queue<int> pings;

    RecentCounter() {
        
    }
    
    int ping(int t) {
        pings.push(t);
        while (pings.front() < t - 3000)
            pings.pop();
        return pings.size();
    }
};

int main() {
    RecentCounter* recentCounter = new RecentCounter();
    cout << recentCounter->ping(1) << endl;     // requests = [1], range is [-2999,1], return 1
    cout << recentCounter->ping(100) << endl;   // requests = [1, 100], range is [-2900,100], return 2
    cout << recentCounter->ping(3001) << endl;  // requests = [1, 100, 3001], range is [1,3001], return 3
    cout << recentCounter->ping(3002) << endl;  // requests = [1, 100, 3001, 3002], range is [2,3002], return 3

    return 0;
}
