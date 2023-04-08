#include<iostream>

using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

class Stack{
	private:
		int size;
		Node* top;
	public:
		Stack();
		~Stack();
		void push(int data);
		int pop();
		int stackTop();
		int isEmpty();
		int isFull();
		int peek(int index);
		void Display();
};

Stack::Stack(){
	this->size = 0;
	top = nullptr;
}

Stack::~Stack(){
	Node* temp = top;
	while(top!=nullptr){
		top = temp->next;
		delete temp;
		temp = top;
	}
}

void Stack::push(int data){
	Node* newNode = new Node;
	if(newNode == nullptr){
		cout<<"Stack Overflow"<<endl;
		return;
	}
	newNode->data = data;
	newNode->next = top;
	top = newNode;
	size++;
}

int Stack::pop(){
	int x = -1;
	if(isEmpty()){
		cout<<"Stack Underflow"<<endl;
	}
	else{
		Node* temp = top;
		top = top->next;
		x = temp->data;
		delete temp;
	}
	size--;
	return x;
}

int Stack::isEmpty(){
	return top == nullptr;
}

int Stack::isFull(){
	Node* t = new Node;
	int val = t?0:1;
	delete t;
	return val;
}

int Stack::stackTop(){
	if(top){
		return top->data;
	}
	return -1;
}

int Stack::peek(int index){
	if(top==nullptr)
		return -1;
	Node* p = top;
	for(int i=0; p!=nullptr && i<=index-1; i++){
		p = p->next;
	}

	if(p != nullptr)
		return p->data;
	else
		return -1;
}

void Stack::Display(){
	Node* node = top;
	while(node != nullptr){
		cout<<node->data<<" ";
		node = node->next;
	}
	cout<<endl;
}

int main(){
	Stack stk;
	stk.push(10);
	stk.push(20);
	stk.push(30);
	stk.push(40);
	stk.push(50);
	stk.Display();
	cout<<"Peek index starts from 0."<<endl;
	cout<<"Peek at index 2: "<< stk.peek(2)<<endl;
	cout<<"Calling stk.pop() after calling destructor."<<endl;
	stk.~Stack();
	cout<<"You poped "<<stk.pop()<<endl;
}


