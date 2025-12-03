#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int sum = l1->val + l2->val;
    int carry = sum / 10;
    ListNode* output = new ListNode(sum % 10);

    ListNode* l1_curr = l1;
    ListNode* l2_curr = l2;
    ListNode* output_curr = output;
    while (l1_curr->next != nullptr && l2_curr->next != nullptr) {
        l1_curr = l1_curr->next;
        l2_curr = l2_curr->next;
        sum = l1_curr->val + l2_curr->val + carry;
        carry = sum / 10;
        output_curr->next = new ListNode(sum % 10);
        output_curr = output_curr->next;
    }

    while (l1_curr->next != nullptr) {
        l1_curr = l1_curr->next;
        sum = l1_curr->val + carry;
        carry = sum / 10;
        output_curr->next = new ListNode(sum % 10);
        output_curr = output_curr->next;
    }
    while (l2_curr->next != nullptr) {
        l2_curr = l2_curr->next;
        sum = l2_curr->val + carry;
        carry = sum / 10;
        output_curr->next = new ListNode(sum % 10);
        output_curr = output_curr->next;
    }
    if (carry > 0) {
        output_curr->next = new ListNode(carry);
    }

    return output;
}

int main() {
    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);
    l1->next->next->next = new ListNode(9);
    l1->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next->next = new ListNode(9);

    ListNode* l2 = new ListNode(9);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(9);
    l2->next->next->next = new ListNode(9);

    ListNode* ans = addTwoNumbers(l1, l2);
    cout << "[" << ans->val;
    ListNode* temp = ans;
    ans = ans->next;
    delete temp;
    while (ans != nullptr) {
        cout << ", " << ans->val;
        temp = ans;
        ans = ans->next;
        delete temp;
    }
    cout << "]" << endl;

    while (l1 != nullptr) {
        temp = l1;
        l1 = l1->next;
        delete temp;
    }

    while (l2 != nullptr) {
        temp = l2;
        l2 = l2->next;
        delete temp;
    }

    return 0;
}
