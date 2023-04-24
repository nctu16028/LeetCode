#include <iostream>
#include <vector>
using namespace std;

bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
{
    if (source == destination)
        return true;
    else if (edges.size() == 0)
        return false;

    // We check whether source and destination are in the same component
    vector<int> cpnRep(n, -1);      // cpnRep[i] == -1 means i is an isolated vertex
    for (auto& rel : edges)
    {
        if (cpnRep[rel[0]] == -1 && cpnRep[rel[1]] == -1)
        {
            cpnRep[rel[0]] = min(rel[0], rel[1]);
            cpnRep[rel[1]] = cpnRep[rel[0]];
        }
        else if (cpnRep[rel[0]] == -1)
            cpnRep[rel[0]] = cpnRep[rel[1]];
        else if (cpnRep[rel[1]] == -1)
            cpnRep[rel[1]] = cpnRep[rel[0]];
        else
        {
            int rep1 = cpnRep[rel[0]];
            while (rep1 != cpnRep[rep1]) rep1 = cpnRep[rep1];   // trace to the root representative of rel[0]
            int rep2 = cpnRep[rel[1]];
            while (rep2 != cpnRep[rep2]) rep2 = cpnRep[rep2];   // trace to the root representative of rel[1]
            cpnRep[max(rep1, rep2)] = min(rep1, rep2);
        }
    }

    if (cpnRep[source] == -1 || cpnRep[destination] == -1)
        return false;
    else
    {
        int repS = cpnRep[source];
        while (repS != cpnRep[repS]) repS = cpnRep[repS];   // trace to the root representative of source
        int repD = cpnRep[destination];
        while (repD != cpnRep[repD]) repD = cpnRep[repD];   // trace to the root representative of destination
        return (repS == repD);
    }
}

int main()
{
    int n, nE;
    cin >> n >> nE;

    vector<vector<int>> edges(nE, vector<int>(2));
    for (int i = 0; i < nE; i++)
        cin >> edges[i][0] >> edges[i][1];

    int source, destination;
    cin >> source >> destination;
    cout << (validPath(n, edges, source, destination) ? "true" : "false") << endl;

    return 0;
}
