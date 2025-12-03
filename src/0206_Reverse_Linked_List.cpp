#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    if (head == nullptr)
        return head;

    stack<ListNode*> nodes;
    while (head->next != nullptr) {
        ListNode* temp = head;
        head = head->next;
        temp->next = nullptr;
        nodes.push(temp);
    }

    ListNode* tail = head;
    while (!nodes.empty()) {
        ListNode* temp = nodes.top();
        nodes.pop();
        tail->next = temp;
        tail = tail->next;
    }

    return head;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* ans = reverseList(head);
    cout << "[";
    if (ans != nullptr) {
        cout << ans->val;
        ListNode* temp = ans;
        ans = ans->next;
        delete temp;
    }
    while (ans != nullptr) {
        cout << ", " << ans->val;
        ListNode* temp = ans;
        ans = ans->next;
        delete temp;
    }
    cout << "]" << endl;

    return 0;
}
