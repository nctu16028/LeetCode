#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k)
{
    if (head == nullptr)
        return nullptr;

    int n = 1;
    ListNode* tail;
    for (tail = head; tail->next != nullptr; tail = tail->next)
        n++;

    tail->next = head;
    for (int i = 0; i < n - k % n; i++)
        tail = tail->next;
    ListNode* newHead = tail->next;
    tail->next = nullptr;

    return newHead;
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* ans = rotateRight(head, 2);
    ListNode* curr = ans;
    ans = ans->next;
    cout << "[" << curr->val;
    delete curr;
    while (ans != nullptr)
    {
        curr = ans;
        ans = ans->next;
        cout << ", " << curr->val;
        delete curr;
    }
    cout << "]" << endl;

    return 0;
}
