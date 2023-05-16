#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right)
{
    ListNode* leftPrev = nullptr, *leftPtr, *rightPtr, *rightNext;
    ListNode* prev = nullptr;
    ListNode* curr = head;
    for (int i = 1; i <= right; i++)
    {
        // Tag critical breakpoints
        if (i == left - 1)
            leftPrev = curr;
        if (i == left)
            leftPtr = curr;
        if (i == right)
        {
            rightPtr = curr;
            rightNext = rightPtr->next;
        }

        // Reverse the "next" pointer between left and right
        if (i > left && i <= right)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    // Reconnect the middle part
    if (leftPrev == nullptr)
        head = rightPtr;
    else
        leftPrev->next = rightPtr;
    leftPtr->next = rightNext;

    return head;
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* ans = reverseBetween(head, 2, 4);
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
