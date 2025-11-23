#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int x)
    {
        val = x;
        next = NULL;
    }
};

Node *detect(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return slow;
    }
    return NULL;
}

Node *find(Node *head)
{
    Node *meet = detect(head);
    if (meet == NULL)
        return NULL;
    Node *slow = head;
    Node *fast = meet;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

void removeLoop(Node *head)
{
    Node *start = find(head);
    if (start == NULL)
        return;
    Node *temp = start;
    while (temp->next != start)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head->next->next->next->next->next = head->next->next;
    removeLoop(head);
    printList(head);

    return 0;
}
