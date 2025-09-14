#include <iostream>
using namespace std;
#define SIZE 5
class queue{
	public:
	int arr[SIZE];
	int front;
	int rear;

	queue(){
		front=-1;
		rear=-1;
	}
	bool isEmpty(){
		if(front==-1){
			return true;
		}
	return false;
	}
	bool isFull(){
		if(rear==SIZE-1){
			return true;
		}
		return false;
	}
	void enqueue(int val){
	if(isFull()){
		cout<<"Queue is full"<<endl;
		return;
	}
	if(front==-1){
		front=0;
	}
		arr[++rear]=val;
	}
	void dequeue(){
	if(isEmpty()){
		cout<<"Queue is empty";
		return;
	}
	if(front==rear){
		front =-1;
		rear=-1;
	}
	else{
		front++;
	}
}
	void peek(){
	if(isEmpty()){
		cout<<"Queue is empty";
		return;
	}
	else{
		cout<<"front element: "<<arr[front]<<endl;
	}
}
	void display(){
	if(isEmpty()){
		cout<<"Queue is empty";
		return;
	}
	for(int i=front;i<=rear;i++){
		cout<<"Element: "<<arr[i]<<endl;
	}
}
};
int main() {
	queue q;
	int val;
	while(true){
	
	cout<<"Choose option 1. enqueue 2. dequeue 3.peek 4.display 5.exit";
	int n;
	cin>>n;
	switch(n){
		case 1:
			cout<<"Enter value: ";
			cin>>val;
			q.enqueue(val);
			break;
		case 2:
			q.dequeue();
			break;
		case 3:
			q.peek();
			break;
		case 4:
			q.display();
			break;
		case 5:
			exit(0);
			break;
		default:
			cout<<"invalid choice";
			break;
	}
	}
	return 0;
}
