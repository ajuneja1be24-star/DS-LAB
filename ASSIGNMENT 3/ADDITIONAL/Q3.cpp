#include <iostream>
#include <stack>
using namespace std;
int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result[100]; 
    stack<int> s;  
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        if (s.empty())
            result[i] = -1;
        else
            result[i] = s.top();

        s.push(arr[i]);  
    }
    cout << "Next Greater Elements: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
