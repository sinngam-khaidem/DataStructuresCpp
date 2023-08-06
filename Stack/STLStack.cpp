#include<iostream>
#include<stack>
using std::stack;
using namespace std;

int main(){
	stack<int> myStack;
	myStack.push(6);
	myStack.push(-7777);
	myStack.pop();
	cout<<myStack.top()<<endl;
	cout<<myStack.empty()<<endl;
}
