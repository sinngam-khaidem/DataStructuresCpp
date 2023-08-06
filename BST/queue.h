#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

class Node{
public:
	Node* lchild;
    int data;
    Node* rchild;
    Node(int x){
		lchild = nullptr;
		data = x;
		rchild = nullptr;
	}
	Node(){
		
	}   
};

class Queue{
	private:
		int size;
		int front;
		int rear;
		Node** Q;
	public:
		Queue(int size);
		~Queue();

		bool isEmpty();
		bool isFull();
		void enqueue(Node* x);
		Node* dequeue();
		Node* frontpeek();
};

Queue::Queue(int size){
	this->size = size;
	front =-1;
	rear = -1;
	Q = new Node*[size];
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

void Queue::enqueue(Node* x){
	if(isFull()){
		cout<<"Queue Overflow"<<endl;
		return;
	}
	Q[++rear] = x;
}

Node* Queue::dequeue(){
	Node* x = nullptr;
	if(isEmpty()){
		cout<<"Queue Underflow"<<endl;
		return nullptr;
	}
	x = Q[++front];
	return x;
}

Node* Queue::frontpeek(){
	Node* x = nullptr;
	if(isEmpty()){
		cout<<"Queue Underflow"<<endl;
		return nullptr;
	}
	int lead = front;
	x = Q[++lead];
	return x;
}

#endif