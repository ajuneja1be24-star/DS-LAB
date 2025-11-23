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
int getLength(Node *head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

Node *intersection(Node *head1, Node *head2)
{
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    if (len1 > len2)
    {
        int diff = len1 - len2;
        for (int i = 0; i < diff; i++)
            head1 = head1->next;
    }
    else
    {
        int diff = len2 - len1;
        for (int i = 0; i < diff; i++)
            head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL)
    {
        if (head1 == head2)
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main()
{
    Node *common = new Node(8);
    common->next = new Node(10);

    Node *head1 = new Node(3);
    head1->next = common;

    Node *head2 = new Node(99);
    head2->next = common;

    Node *res = intersection(head1, head2);

    if (res != NULL)
        cout << "Intersection at node with value: " << res->val << endl;
    else
        cout << "No intersection." << endl;

    return 0;
}
