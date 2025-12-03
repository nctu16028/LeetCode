#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return;

    ListNode* slow = head;
    ListNode* fast = head->next;

    stack<ListNode*> frontHalf;
    head = head->next;
    slow->next = nullptr;
    frontHalf.push(slow);
    while (fast->next != nullptr && fast->next->next != nullptr) {
        fast = fast->next->next;
        slow = head;
        head = head->next;
        slow->next = nullptr;
        frontHalf.push(slow);
    }

    ListNode* newHead;
    if (fast->next == nullptr) {
        newHead = head;
        head = head->next;
        newHead->next = nullptr;

        ListNode* temp = frontHalf.top();
        frontHalf.pop();
        temp->next = newHead;
        newHead = temp;
    }
    else if (fast->next->next == nullptr) {
        newHead = head;
        head = head->next;
        newHead->next = nullptr;

        ListNode* temp = head;
        head = head->next;
        temp->next = newHead;
        newHead = temp;

        temp = frontHalf.top();
        frontHalf.pop();
        temp->next = newHead;
        newHead = temp;
    }

    while (!frontHalf.empty()) {
        ListNode* temp = head;
        head = head->next;
        temp->next = newHead;
        newHead = temp;

        temp = frontHalf.top();
        frontHalf.pop();
        temp->next = newHead;
        newHead = temp;
    }

    head = newHead;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    //head->next->next->next->next = new ListNode(5);

    reorderList(head);

    cout << "[";
    ListNode* temp;
    if (head != nullptr) {
        cout << head->val;
        temp = head;
        head = head->next;
        delete temp;
    }
    while (head != nullptr) {
        cout << ", " << head->val;
        temp = head;
        head = head->next;
        delete temp;
    }
    cout << "]" << endl;

    return 0;
}
