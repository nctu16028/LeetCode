#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head)
{
    if (head == nullptr)
        return nullptr;

    // Use two pointers method to find one of the nodes in the cycle
    ListNode* slow = head;
    ListNode* fast = head;
    while (true)
    {
        if (fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }
        else
            return nullptr;     // no cycle exists
    }

    // Find the entry node of the cycle
    ListNode* entry = head;
    while (entry != slow)
    {
        entry = entry->next;
        slow = slow->next;
    }

    return entry;
}

int main()
{
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    cout << detectCycle(head) << endl;

    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
