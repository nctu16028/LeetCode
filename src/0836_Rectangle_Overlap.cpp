#include <iostream>
#include <vector>
using namespace std;

bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    if (rec1[2] <= rec2[0])
        return false;
    if (rec2[2] <= rec1[0])
        return false;
    if (rec1[3] <= rec2[1])
        return false;
    if (rec2[3] <= rec1[1])
        return false;
    return true;
}

int main() {
    vector<int> rec1(4), rec2(4);
    cin >> rec1[0] >> rec1[1] >> rec1[2] >> rec1[3];
    cin >> rec2[0] >> rec2[1] >> rec2[2] >> rec2[3];
    cout << (isRectangleOverlap(rec1, rec2) ? "true" : "false") << endl;

    return 0;
}
