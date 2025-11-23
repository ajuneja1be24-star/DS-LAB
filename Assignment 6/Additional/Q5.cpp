#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node* up;
    Node* down;
    Node(int val) {
        data = val;
        next = prev = up = down = NULL;
    }
};

Node* converttoLL(int mat[][3], int m, int n) {
    Node* head = NULL;
    Node* rowStart = NULL;
    Node* prevRow = NULL;

    for (int i = 0; i < m; i++) {
        Node* prev = NULL;
        for (int j = 0; j < n; j++) {
            Node* newNode = new Node(mat[i][j]);
            if (!head) head = newNode;
            if (!rowStart) rowStart = newNode;
            if (prev) {
                prev->next = newNode;
                newNode->prev = prev;
            }
            if (prevRow) {
                Node* upNode = prevRow;
                for (int k = 0; k < j; k++) upNode = upNode->next;
                upNode->down = newNode;
                newNode->up = upNode;
            }
            prev = newNode;
        }
        prevRow = rowStart;
        rowStart = NULL;
        for (int j = 0; j < n; j++) {
            if (!rowStart) rowStart = prevRow->down;
            prevRow = prevRow->next;
        }
    }
    return head;
}

void display(Node* head, int m, int n) {
    Node* row = head;
    for (int i = 0; i < m; i++) {
        Node* col = row;
        for (int j = 0; j < n; j++) {
            cout << col->data << " ";
            col = col->next;
        }
        cout << endl;
        row = row->down;
    }
}

int main() {
    int mat[3][3] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    Node* head = converttoLL(mat, 3, 3);
    display(head, 3, 3);
    return 0;
}
