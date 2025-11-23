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

Node *reverseK(Node *head, int k)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    int count = 0;

    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next != NULL)
        head->next = reverseK(next, k);

    return prev;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(1);
    Node *temp = head;
    for (int i = 2; i <= 9; i++)
    {
        temp->next = new Node(i);
        temp = temp->next;
    }
    int k = 3;
    head = reverseK(head, k);

    printList(head);

    return 0;
}
