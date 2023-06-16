#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int x) : val(x), prev(nullptr), next(nullptr), child(nullptr) {}
};

// This recursive function returns the tail node of the list on that level
Node* flattenChild(Node* head)
{
    if (head == nullptr)
        return nullptr;

    Node* curr = head, *lowerHead, *lowerTail;
    for (; curr->next != nullptr; curr = curr->next)
    {
        lowerHead = curr->child;
        lowerTail = flattenChild(lowerHead);
        if (lowerTail != nullptr)
        {
            lowerHead->prev = curr;
            lowerTail->next = curr->next;
            curr->next->prev = lowerTail;
            curr->next = lowerHead;
            curr->child = nullptr;
            curr = lowerTail;
        }
    }

    Node* tail = curr;
    lowerHead = tail->child;
    lowerTail = flattenChild(lowerHead);
    if (lowerTail != nullptr)
    {
        lowerHead->prev = tail;
        tail->next = lowerHead;
        tail->child = nullptr;
        tail = lowerTail;
    }

    return tail;
}

Node* flatten(Node* head)
{
    flattenChild(head);
    return head;
}

int main()
{
    Node* one = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(3);
    Node* four = new Node(4);
    Node* five = new Node(5);
    Node* six = new Node(6);
    Node* seven = new Node(7);
    Node* eight = new Node(8);
    Node* nine = new Node(9);
    Node* ten = new Node(10);
    Node* eleven = new Node(11);
    Node* twelve = new Node(12);

    one->next = two;
    two->prev = one;
    two->next = three;
    three->prev = two;
    three->child = seven;
    three->next = four;
    four->prev = three;
    four->next = five;
    five->prev = four;
    five->next = six;
    six->prev = five;
    seven->next = eight;
    eight->prev = seven;
    eight->child = eleven;
    eight->next = nine;
    nine->prev = eight;
    nine->next = ten;
    ten->prev = nine;
    eleven->next = twelve;
    twelve->prev = eleven;

    Node* ans = flatten(one);
    cout << "[";
    if (ans != nullptr)
    {
        Node* temp = ans;
        ans = ans->next;
        cout << temp->val;
        delete temp;
        while (ans != nullptr)
        {
            temp = ans;
            ans = ans->next;
            cout << ", " << temp->val;
            delete temp;
        }
    }
    cout << "]" << endl;

    return 0;
}
