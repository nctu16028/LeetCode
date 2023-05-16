#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val)
{
    if (head == nullptr)
        return nullptr;

    ListNode* curr = head->next;
    ListNode* prev = head;
    while (curr != nullptr)
    {
        if (curr->val == val)
        {
            ListNode* toDelete = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete toDelete;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    if (head->val == val)
    {
        ListNode* toDelete = head;
        head = head->next;
        delete toDelete;
    }

    return head;
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    ListNode* ans = removeElements(head, 6);
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
