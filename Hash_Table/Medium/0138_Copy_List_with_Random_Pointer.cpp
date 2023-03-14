#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head)
{
    if (head == nullptr)
        return nullptr;

    unordered_map<Node*, Node*> oldToNewNodeMapping;
    Node* newHead, *newCurr;
    for (Node* curr = head; curr != nullptr; curr = curr->next)
    {
        if (curr == head)
        {
            newHead = new Node(curr->val);
            newCurr = newHead;
        }
        else
        {
            newCurr->next = new Node(curr->val);
            newCurr = newCurr->next;
        }
        oldToNewNodeMapping.insert({curr, newCurr});
    }

    for (Node* curr = head, *newCurr = newHead; curr != nullptr; curr = curr->next, newCurr = newCurr->next)
        newCurr->random = oldToNewNodeMapping[curr->random];

    return newHead;
}

int main()
{
    int n;
    cin >> n;

    vector<Node*> nodeAddr(n, nullptr);
    for (int i = 0; i < n; i++)
        nodeAddr[i] = new Node(0);

    Node* head = (n > 0) ? nodeAddr[0] : nullptr;
    int val, randomIndex;
    for (int i = 0; i < n; i++)
    {
        cin >> val >> randomIndex;
        nodeAddr[i]->val = val;
        if (randomIndex != -1)
            nodeAddr[i]->random = nodeAddr[randomIndex];
        if (i != 0)
            nodeAddr[i-1]->next = nodeAddr[i];
    }

    Node* copyHead = copyRandomList(head);
    cout << "Copied successfully" << endl;

    // Handle memory leak
    Node* toDelete;
    while (head != nullptr)
    {
        toDelete = head;
        head = head->next;
        delete toDelete;
        toDelete = copyHead;
        copyHead = copyHead->next;
        delete toDelete;
    }

    return 0;
}
