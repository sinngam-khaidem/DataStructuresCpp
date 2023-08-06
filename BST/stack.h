#ifndef STACK_H
#define STACK_H


#include<iostream>
using namespace std;

class Stack{
	private:
		int size;
		int top;
		Node** S;
	public:
		Stack(int size);
		~Stack();
		void push(Node* x);
		 Node* pop();
		int isFull();
		int isEmpty();
		Node* peek(int index);
};

Stack::Stack(int size){
	this->size = size;
	top = -1;
	S = new Node*[size];
}

Stack::~Stack(){
	delete[] S;
}

void Stack::push(Node* x){
	if(isFull()){
		cout<<"Stack overflow"<<endl;
	}
	else{
		S[++top] = x;
	}
}

Node* Stack::pop(){
	Node* x = nullptr;
	if(isEmpty()){
		cout<<"Stack underflow"<<endl;
	}
	else{
		x = S[top];
		top--;
	}
	return x;
}

int Stack::isFull(){
	return top == size-1;
}

int Stack::isEmpty(){
	return top == -1;
}

Node* Stack::peek(int index) {
    Node* x = nullptr;
    if (top-index+1 < 0 || top-index+1 == size){
        cout << "Invalid position!" << endl;
    } else {
        x = S[top-index+1];
    }
    return x;
}

#endif