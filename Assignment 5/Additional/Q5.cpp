#include <iostream>
using namespace std;

class Node
{
public:
    int coef;
    int exp;
    Node *next;

    Node(int c, int e)
    {
        coef = c;
        exp = e;
        next = NULL;
    }
};

Node *addPolynomials(Node *a, Node *b)
{
    Node *head = NULL;
    Node *tail = NULL;

    while (a != NULL || b != NULL)
    {
        int c = 0, e = 0;

        if (a != NULL && (b == NULL || a->exp > b->exp))
        {
            c = a->coef;
            e = a->exp;
            a = a->next;
        }
        else if (b != NULL && (a == NULL || b->exp > a->exp))
        {
            c = b->coef;
            e = b->exp;
            b = b->next;
        }
        else
        {
            c = a->coef + b->coef;
            e = a->exp;
            a = a->next;
            b = b->next;
        }

        if (head == NULL)
        {
            head = new Node(c, e);
            tail = head;
        }
        else
        {
            tail->next = new Node(c, e);
            tail = tail->next;
        }
    }

    return head;
}

void printPoly(Node *head)
{
    while (head != NULL)
    {
        cout << "[" << head-> coef << "," << head->exp << "] ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *poly1 = new Node(5, 2);
    poly1->next = new Node(4, 1);
    poly1->next->next = new Node(2, 0);

    Node *poly2 = new Node(5, 1);
    poly2->next = new Node(5, 0);

    Node *sum = addPolynomials(poly1, poly2);
    printPoly(sum); 
    return 0;
}
