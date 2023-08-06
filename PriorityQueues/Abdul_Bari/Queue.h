#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>

using namespace std;

class Queue{
	private:
		int size;
		int front;
		int rear;
		char* Q;
	public:
		Queue(int size);
		~Queue();

		bool isEmpty();
		bool isFull();
		void enqueue(char data);
		char dequeue();
		void Display();
};

Queue::Queue(int size){
	this->size = size;
	front =-1;
	rear = -1;
	Q = new char[size];
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

void Queue::enqueue(char data){
	if(isFull()){
		cout<<"Queue Overflow"<<endl;
		return;
	}
	Q[++rear] = data;
}

char Queue::dequeue(){
	char x = '\0';
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

#endif