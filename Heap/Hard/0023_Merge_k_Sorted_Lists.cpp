#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    struct cmp
    {
        bool operator()(const pair<ListNode*, int>& a, const pair<ListNode*, int>& b) const
        {
            if ((b.first)->val == (a.first)->val)
                return b.second < a.second;
            return (b.first)->val < (a.first)->val;
        }
    };

    priority_queue<pair<ListNode*, int>, vector<pair<ListNode*, int>>, cmp> pq;   // min heap of pair(val, fromWhichList)
    ListNode* temp;
    for (int i = 0; i < lists.size(); i++)
    {
        if (lists[i] != nullptr)
        {
            temp = lists[i];
            lists[i] = lists[i]->next;
            temp->next = nullptr;
            pq.push(make_pair(temp, i));
        }
    }

    ListNode* output = nullptr;
    ListNode* tail = nullptr;
    while (!pq.empty())
    {
        // Pop out one node
        temp = pq.top().first;
        int i = pq.top().second;
        pq.pop();

        // Append it to the merged list
        if (output == nullptr)
        {
            output = temp;
            tail = output;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }

        // Push in one more node from the same list
        if (lists[i] != nullptr)
        {
            temp = lists[i];
            lists[i] = lists[i]->next;
            temp->next = nullptr;
            pq.push(make_pair(temp, i));
        }
    }

    return output;
}

int main()
{
    vector<ListNode*> lists(3);
    lists[0] = new ListNode(1);
    lists[0]->next = new ListNode(4);
    lists[0]->next->next = new ListNode(5);
    lists[1] = new ListNode(1);
    lists[1]->next = new ListNode(3);
    lists[1]->next->next = new ListNode(4);
    lists[2] = new ListNode(2);
    lists[2]->next = new ListNode(6);

    ListNode* ans = mergeKLists(lists);
    cout << "[";
    while (ans != nullptr)
    {
        ListNode* temp = ans;
        ans = ans->next;
        cout << temp->val;
        delete temp;
        if (ans != nullptr)
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
