#include<iostream>

using namespace std;

class Queue{
	private:
		int size;
		int front;
		int rear;
		int* Q;
	public:
		Queue(int size);
		~Queue();

		bool isEmpty();
		bool isFull();
		void enqueue(int data);
		int dequeue();
		void Display();
};

Queue::Queue(int size){
	this->size = size;
	front =-1;
	rear = -1;
	Q = new int[size];
}

Queue::~Queue(){
	delete[] Q;
}

bool Queue::isEmpty(){
	if(front == rear)
		return true;
	else
		return false;
}

bool Queue::isFull(){
	if(rear == size-1)
		return true;
	else
		return false;
}

void Queue::enqueue(int data){
	if(isFull()){
		cout<<"Queue Overflow"<<endl;
		return;
	}
	Q[++rear] = data;
}

int Queue::dequeue(){
	int x = -1;
	if(isEmpty()){
		cout<<"Queue Underflow"<<endl;
		return -1;
	}
	x = Q[++front];
	return x;
}

void Queue::Display(){
	for(int i=front+1; i<=rear; i++){
		cout<<Q[i]<<" "; 
	}
	cout<<endl;
}



int main(){
	int A[] = {10,20,30,40,50};
	int n = sizeof(A)/sizeof(A[0]);

	Queue q(n);

	for(int i=0; i<n; i++){
		q.enqueue(A[i]);
	}

	q.Display();
}
