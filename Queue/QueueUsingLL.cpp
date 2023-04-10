#include<iostream>

using namespace std;

class Node{
	public:
		int data;
		Node* next;
};


class Queue{
	private:
		Node* front;
		Node* rear;
	public:
		Queue();
		~Queue();
		bool isEmpty();
		void enqueue(int data);
		int dequeue();
		void Display();
};

Queue::~Queue(){
	Node* p;
	while(front!=nullptr){
		p = front;
		front = front->next;
		delete p;
	}
}

Queue::Queue(){
	front = nullptr;
	rear = nullptr;
}

bool Queue::isEmpty(){
	if(front == nullptr)
		return true;
	else
		return false;
}

void Queue::enqueue(int data){
	Node *t = new Node;
	if(t==nullptr){
		cout<<"Queue Overflow"<<endl;
	}
	else{
		t->data = data;
		t->next = nullptr;
		if(rear == nullptr){
			rear = t;
			front = t;
		}
		else{
			rear->next = t;
			rear = t;
		}
	}
}

int Queue::dequeue(){
	int x = -1;
	Node* p;
	if(isEmpty()){
		cout<<"Queue Underflow"<<endl;
	}
	else{
		p = front;
		front = front->next;
		x = p->data;
		delete p;
	}
	return x;
}

void Queue::Display(){
	Node* p = front;
	while(p!=nullptr){
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}

int main(){
	Queue q;
	q.dequeue();
	q.Display();
}

