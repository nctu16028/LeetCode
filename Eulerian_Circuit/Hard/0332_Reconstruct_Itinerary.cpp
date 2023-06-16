#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <stack>
using namespace std;

vector<string> findItinerary(vector<vector<string>>& tickets)
{
    // Build the graph and keep track of in-degree and out-degree of each node
    unordered_map<string, multiset<string>> stringGraph;
    for (auto& ticket : tickets)
    {
        if (stringGraph.find(ticket[0]) == stringGraph.end())
            stringGraph.insert({ticket[0], multiset<string>()});
        stringGraph[ticket[0]].insert(ticket[1]);
    }

    // Draw an Eulerian path from "JFK" as long as possible
    stack<string> inProcess, finished;
    inProcess.push("JFK");
    while (true)
    {
        // If we are stuck at some node, we "break out" from one of the previous nodes
        while (!inProcess.empty() && stringGraph[inProcess.top()].empty())
        {
            finished.push(inProcess.top());
            inProcess.pop();
        }

        if (inProcess.empty())
            break;
        else
        {
            // Hop to the next node
            auto nextNodeIterator = stringGraph[inProcess.top()].begin();
            string next = *(nextNodeIterator);
            stringGraph[inProcess.top()].erase(nextNodeIterator);
            inProcess.push(next);
        }
    }

    vector<string> output;
    while (!finished.empty())
    {
        output.push_back(finished.top());
        finished.pop();
    }

    return output;
}

int main()
{
    int m;
    cin >> m;

    vector<vector<string>> tickets(m, vector<string>(2));
    for (int i = 0; i < m; i++)
        cin >> tickets[i][0] >> tickets[i][1];

    vector<string> ans = findItinerary(tickets);
    cout << "[" << ans[0];
    for (int i = 1; i < ans.size(); i++)
        cout << ", " << ans[i];
    cout << "]" << endl;

    return 0;
}
