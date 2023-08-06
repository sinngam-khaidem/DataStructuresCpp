#include<iostream>
using namespace std;

template <typename E>
class ArrayStack{
	private:
		int size;
		int top;
		E* S;
	public:
		ArrayStack(int size);
		~ArrayStack();
		void push(const E& e) throw(StackFull);
		const E& pop() throw(StackEmpty);
		const E& top() throw(StackEmpty);
		void Display();
		int isFull();
		int isEmpty();
		const E& peek(int index) throw(InvalidIndex);
};

template <typename E>
ArrayStack<E>::ArrayStack(int size){
	this->size = size;
	top = -1;
	S = new E[size];
}

template <typename E>
ArrayStack<E>::~ArrayStack(){
	delete[] S;
}

template <typename E>
void ArrayStack<E>::push(const E& e) throw(StackFull){
	if(isFull()) throw StackFull("Push to full stack")
	S[++top] = data;
}

template <typename E>
const E& ArrayStack::pop() throw(StackEmpty){
	const E& x;
	if(isEmpty()) throw StackEmpty("Pop from empty stack");
	x = S[top];
	top--;
	return x;
}

template <typename E>
const E& ArrayStack<E>::top() throw(StackEmpty){
	if(isEmpty()) throw StackEmpty("Pop from empty stack");
	return S[top];
}

template <typename E>
int ArrayStack<E>::isFull(){
	return top == size-1;
}

template <typename E>
int ArrayStack::isEmpty(){
	return top == -1;
}

template <typename E>
const E& ArrayStack<E>::peek(int index) throw(InvalidIndex){
   	const E& x;
    if (top-index+1 < 0 || top-index+1 == size) throw InvalidIndex("Index out of range");
    x = S[top-index+1];
    return x;
}


template <typename E>
void ArrayStack<E>::Display(){
	for(int i=0; i<=top; i++){
		cout<<S[i]<<" ";
	}
	cout<<endl;
}

int main(){

}
