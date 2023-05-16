#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    // Connect the tail of listA and the head of listB to form a bigger linked list
    ListNode* tailA = headA;
    while (tailA->next != nullptr)
        tailA = tailA->next;
    tailA->next = headB;

    // Use two pointers method to find one of the nodes in the cycle
    ListNode* slow = headA;
    ListNode* fast = headA;
    while (true)
    {
        if (fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }
        else    // no cycle exists
        {
            tailA->next = nullptr;  // restore the input structures
            return nullptr;
        }
    }

    // Find the entry node of the cycle
    ListNode* entry = headA;
    while (entry != slow)
    {
        entry = entry->next;
        slow = slow->next;
    }

    tailA->next = nullptr;  // restore the input structures
    return entry;
}

int main()
{
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headA->next->next;

    cout << getIntersectionNode(headA, headB) << endl;

    delete headB->next->next;
    delete headB->next;
    delete headB;
    delete headA->next->next->next->next;
    delete headA->next->next->next;
    delete headA->next->next;
    delete headA->next;
    delete headA;

    return 0;
}
