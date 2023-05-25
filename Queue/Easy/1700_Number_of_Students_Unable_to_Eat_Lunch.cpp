#include <iostream>
#include <vector>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches)
{
    int n = sandwiches.size();
    int queueFront = 0, stackTop = 0;
    int skipCount = 0;
    while (skipCount < students.size() - queueFront)
    {
        if (students[queueFront] == sandwiches[stackTop])
        {
            queueFront++;
            stackTop++;
            skipCount = 0;
        }
        else
        {
            students.push_back(students[queueFront]);
            queueFront++;
            skipCount++;
        }
    }

    return skipCount;
}

int main()
{
    int n;
    cin >> n;

    vector<int> students(n);
    for (int i = 0; i < n; i++)
        cin >> students[i];

    vector<int> sandwiches(n);
    for (int i = 0; i < n; i++)
        cin >> sandwiches[i];

    cout << countStudents(students, sandwiches) << endl;

    return 0;
}
