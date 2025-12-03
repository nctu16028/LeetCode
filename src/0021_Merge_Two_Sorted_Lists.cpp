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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    while (list1 != nullptr && list2 != nullptr) {
        ListNode* temp;
        if (list1->val <= list2->val) {
            temp = list1;
            list1 = list1->next;
            temp->next = nullptr;
        }
        else {
            temp = list2;
            list2 = list2->next;
            temp->next = nullptr;
        }

        if (head == nullptr) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = tail->next;
        }
    }

    if (list1 != nullptr) {
        if (head == nullptr)
            head = list1;
        else
            tail->next = list1;
    }
    else if (list2 != nullptr) {
        if (head == nullptr)
            head = list2;
        else
            tail->next = list2;
    }

    return head;
}

int main()
{
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* ans = mergeTwoLists(list1, list2);
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
