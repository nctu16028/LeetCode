#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    ListNode* temp1 = head;
    ListNode* prev;
    while (temp1 != nullptr && temp1->next != nullptr) {
        ListNode* temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->next = temp1;
        if (temp1 == head)
            head = temp2;
        else
            prev->next = temp2;
        prev = temp1;
        temp1 = temp1->next;
    }

    return head;
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    //head->next->next->next = new ListNode(4);

    ListNode* ans = swapPairs(head);
    cout << "[";
    while (ans != nullptr) {
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
