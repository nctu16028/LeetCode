#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head)
{
    for (ListNode* curr = head; curr != nullptr; curr = curr->next)
    {
        while (curr->next != nullptr && curr->next->val == curr->val)
        {
            ListNode* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
    }

    return head;
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    ListNode* ans = deleteDuplicates(head);
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
