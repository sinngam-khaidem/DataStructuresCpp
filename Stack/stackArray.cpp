#include<iostream>
using namespace std;

class Stack{
	private:
		int size;
		int top;
		int* S;
	public:
		Stack(int size);
		~Stack();
		void push(int data);
		int pop();
		void Display();
		int isFull();
		int isEmpty();
		int peek(int index);

};

Stack::Stack(int size){
	this->size = size;
	top = -1;
	S = new int[size];
}

Stack::~Stack(){
	delete[] S;
}

void Stack::push(int data){
	if(isFull()){
		cout<<"Stack overflow"<<endl;
	}
	else{
		S[++top] = data;
	}
}

int Stack::pop(){
	int x = -1;
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

int Stack::peek(int index) {
    int x = -1;
    if (top-index+1 < 0 || top-index+1 == size){
        cout << "Invalid position!" << endl;
    } else {
        x = S[top-index+1];
    }
    return x;
}


void Stack::Display(){
	for(int i=0; i<=top; i++){
		cout<<S[i]<<" ";
	}
	cout<<endl;
}

int main(){
	Stack stk(5);
	stk.push(10);
	stk.push(20);
	stk.push(30);
	stk.push(30);
	stk.push(40);
	stk.peek(0);
		
	stk.Display();

}
