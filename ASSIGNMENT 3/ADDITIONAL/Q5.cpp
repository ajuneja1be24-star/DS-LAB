#include <iostream>
#include <stack>
using namespace std;
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int A[1000];
    cout << "Enter elements of A: ";
    for (int i = 0; i < n; i++) cin >> A[i];
    int target[1000];
    for (int i = 0; i < n; i++) target[i] = A[i];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (target[j] < target[i]) {
                int temp = target[i];
                target[i] = target[j];
                target[j] = temp;
            }
        }
    }
    stack<int> s;      
    int B[1000];      
    int bSize = 0;     
    int needIndex = 0; 
    for (int i = 0; i < n; i++) {
        s.push(A[i]);
        while (!s.empty() && s.top() == target[needIndex]) {
            B[bSize++] = s.top();
            s.pop();
            needIndex++;
        }
    }
    bool possible = (bSize == n);
    cout << (possible ? "Yes possible" : "No not possible") << endl;
    return 0;
}
