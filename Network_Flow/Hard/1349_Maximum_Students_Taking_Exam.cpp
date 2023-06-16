#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool pathExist(int start, int end, const vector<vector<int>>& adjLists, const vector<vector<bool>>& capacityMatrix, vector<int>& prevOf)
{
    // Initialization of BFS
    int n = adjLists.size();
    vector<bool> mark(n, false);
    queue<int> toVisit;

    // Determine the starting point
    mark[start] = true;
    toVisit.push(start);

    // Start the search
    while (!toVisit.empty())
    {
        int u = toVisit.front();
        toVisit.pop();

        // Find all the neighbors of the current vertex
        for (auto& v : adjLists[u])
        {
            if (capacityMatrix[u][v] == 0)  // this arc is currently unavailable
                continue;

            if (!mark[v])
            {
                mark[v] = true;
                prevOf[v] = u;
                toVisit.push(v);
            }

            if (v == end)
                return true;
        }
    }

    return false;
}

int maxStudents(vector<vector<char>>& seats)
{
    /* Model the seats as a bipartite graph plus a source and a sink:
     * 1. Add arc (u, v) if u can see v or v can see u, for each pair of even-column seat u and odd-column seat v
     * 2. Add arcs from the source to even-column seats
     * 3. Add arcs from odd-column seats to the sink
     * 4. The maximum flow value of the big graph
     *      = the maximum matching size of the bipartite graph
     *      = the minimum vertex cover size of the bipartite graph
     *      = the minimum number of seats to disable to avoid cheating,
     *    so the answer = (the number of seats) - (the maximum flow value)
     */

    int row = seats.size(), col = seats[0].size();
    int n = row * col + 2;  // the last two nodes are the source and the sink
    vector<vector<int>> adjLists(n + 2, vector<int>());
    vector<vector<bool>> capacityMatrix(n + 2, vector<bool>(n + 2, 0));

    // Build the bipartite graph
    for (int j = 0; j < col; j += 2)
    {
        for (int i = 0; i < row; i++)
        {
            if (seats[i][j] == '.')
            {
                if (i > 0 && j > 0 && seats[i - 1][j - 1] == '.')
                {
                    adjLists[i * col + j].push_back((i-1) * col + (j-1));
                    adjLists[(i-1) * col + (j-1)].push_back(i * col + j);
                    capacityMatrix[i * col + j][(i-1) * col + (j-1)] = 1;
                }
                if (j > 0 && seats[i][j - 1] == '.')
                {
                    adjLists[i * col + j].push_back(i * col + (j-1));
                    adjLists[i * col + (j-1)].push_back(i * col + j);
                    capacityMatrix[i * col + j][i * col + (j-1)] = 1;
                }
                if (i < row - 1 && j > 0 && seats[i + 1][j - 1] == '.')
                {
                    adjLists[i * col + j].push_back((i+1) * col + (j-1));
                    adjLists[(i+1) * col + (j-1)].push_back(i * col + j);
                    capacityMatrix[i * col + j][(i+1) * col + (j-1)] = 1;
                }
                if (i > 0 && j < col - 1 && seats[i - 1][j + 1] == '.')
                {
                    adjLists[i * col + j].push_back((i-1) * col + (j+1));
                    adjLists[(i-1) * col + (j+1)].push_back(i * col + j);
                    capacityMatrix[i * col + j][(i-1) * col + (j+1)] = 1;
                }
                if (j < col - 1 && seats[i][j + 1] == '.')
                {
                    adjLists[i * col + j].push_back(i * col + (j+1));
                    adjLists[i * col + (j+1)].push_back(i * col + j);
                    capacityMatrix[i * col + j][i * col + (j+1)] = 1;
                }
                if (i < row - 1 && j < col - 1 && seats[i + 1][j + 1] == '.')
                {
                    adjLists[i * col + j].push_back((i+1) * col + (j+1));
                    adjLists[(i+1) * col + (j+1)].push_back(i * col + j);
                    capacityMatrix[i * col + j][(i+1) * col + (j+1)] = 1;
                }
            }
        }
    }

    // Connect the source and the sink and count the number of seats
    int sr = n - 2, sk = n - 1;
    int numSeats = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (seats[i][j] == '.')
            {
                numSeats++;
                if (j % 2 == 0)
                {
                    adjLists[sr].push_back(i * col + j);
                    adjLists[i * col + j].push_back(sr);
                    capacityMatrix[sr][i * col + j] = 1;
                }
                else
                {
                    adjLists[i * col + j].push_back(sk);
                    adjLists[sk].push_back(i * col + j);
                    capacityMatrix[i * col + j][sk] = 1;
                }
            }
        }
    }

    // Calculate the maximum flow value by Edmonds-Karp algorithm
    int maxFlow = 0;
    vector<int> prevOf(n, -1);
    while (pathExist(sr, sk, adjLists, capacityMatrix, prevOf))
    {
        for (int v = sk; v != sr; v = prevOf[v])
        {
            // Reverse each arc on the augmenting path
            int u = prevOf[v];
            capacityMatrix[u][v] = 0;
            capacityMatrix[v][u] = 1;
        }
        maxFlow++;
        fill(prevOf.begin(), prevOf.end(), -1);     // clear prev table
    }

    return numSeats - maxFlow;
}

int main()
{
    int row, col;
    cin >> row >> col;

    vector<vector<char>> seats(row);
    for (int i = 0; i < row; i++)
    {
        seats[i] = vector<char>(col);
        for (int j = 0; j < col; j++)
            cin >> seats[i][j];
    }
    cout << maxStudents(seats) << endl;

    return 0;
}
