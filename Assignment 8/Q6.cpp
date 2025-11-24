#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int helper(priority_queue<int, vector<int>, greater<int> >pq, int k){
    stack<int>s;
    int temp;
    for(int i=0;i<k-1;i++){
        temp=pq.top();
        s.push(temp);
        pq.pop();
    }
    return pq.top();
}
int main(){
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(-10);
    pq.push(20);
    pq.push(50);
    pq.push(-45);
    pq.push(45);
    pq.push(80);
    for (int k = 1; k <= pq.size(); k++)
        cout<< helper(pq, k) << endl;
}
