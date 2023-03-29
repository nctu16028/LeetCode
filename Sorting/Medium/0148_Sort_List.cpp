#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoList(ListNode* leftHead, ListNode* rightHead)
{
    ListNode* mergedHead = nullptr;
    ListNode* mergedTail = nullptr;
    while (leftHead != nullptr && rightHead != nullptr)
    {
        // Cutting node
        ListNode* temp;
        if (leftHead->val <= rightHead->val)
        {
            temp = leftHead;
            leftHead = leftHead->next;
        }
        else
        {
            temp = rightHead;
            rightHead = rightHead->next;
        }

        // Pasting node
        if (mergedHead == nullptr)
        {
            mergedHead = temp;
            mergedTail = mergedHead;
        }
        else
        {
            mergedTail->next = temp;
            mergedTail = mergedTail->next;
        }
    }

    if (leftHead != nullptr)
        mergedTail->next = leftHead;

    if (rightHead != nullptr)
        mergedTail->next = rightHead;

    return mergedHead;
}

ListNode* mergeSort(ListNode* head, int len)
{
    if (len < 2)
        return head;

    int leftLen = len / 2;
    int rightLen = len - leftLen;

    // Separate the list into two lists
    ListNode* mid = head;
    for (int i = 0; i < leftLen - 1; i++)
        mid = mid->next;
    ListNode* midPrev = mid;
    mid = mid->next;
    midPrev->next = nullptr;

    // Core
    ListNode* leftHead = mergeSort(head, leftLen);
    ListNode* rightHead = mergeSort(mid, rightLen);
    return mergeTwoList(leftHead, rightHead);
}

ListNode* sortList(ListNode* head)
{
    int len = 0;
    for (ListNode* curr = head; curr != nullptr; curr = curr->next)
        len++;

    return mergeSort(head, len);
}

int main()
{
    int n;
    cin >> n;

    ListNode* head = nullptr;
    if (n > 0)
    {
        head = new ListNode();
        ListNode* temp = head;
        cin >> temp->val;
        for (int i = 1; i < n; i++)
        {
            temp->next = new ListNode();
            temp = temp->next;
            cin >> temp->val;
        }
    }

    ListNode* ans = sortList(head);
    cout << "[";
    if (n > 0)
    {
        cout << ans->val;
        for (ListNode* curr = ans->next; curr != nullptr; curr = curr->next)
            cout << ", " << curr->val;
    }
    cout << "]" << endl;

    // Memory leak avoidance
    ListNode* toRemoved;
    while (ans != nullptr)
    {
        toRemoved = ans;
        ans = ans->next;
        delete toRemoved;
    }

    return 0;
}
