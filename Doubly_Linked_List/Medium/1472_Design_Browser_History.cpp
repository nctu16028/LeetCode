#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        size = 1;
        currentPos = 0;
    }
    
    void visit(string url) {
        currentPos++;
        size = currentPos + 1;
        if (currentPos < history.size())
            history[currentPos] = url;
        else
            history.push_back(url);
    }
    
    string back(int steps) {
        currentPos -= steps;
        if (currentPos < 0)
            currentPos = 0;
        return history[currentPos];
    }
    
    string forward(int steps) {
        currentPos += steps;
        if (currentPos >= size)
            currentPos = size - 1;
        return history[currentPos];
    }

private:
    vector<string> history;
    int size;
    int currentPos;
};

int main()
{
    BrowserHistory* browserHistory = new BrowserHistory("leetcode.com");
    browserHistory->visit("google.com");
    browserHistory->visit("facebook.com");
    browserHistory->visit("youtube.com");
    cout << browserHistory->back(1) << endl;
    cout << browserHistory->back(1) << endl;
    cout << browserHistory->forward(1) << endl;
    browserHistory->visit("linkedin.com");
    cout << browserHistory->forward(2) << endl;
    cout << browserHistory->back(2) << endl;
    cout << browserHistory->back(7) << endl;
    delete browserHistory;

    return 0;
}
