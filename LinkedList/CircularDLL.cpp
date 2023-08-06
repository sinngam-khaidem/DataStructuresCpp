#include<iostream>
using namespace std;

class Node{
public:
	Node* prev;
	int data;
	Node* next;
	Node(int x){
		data = x;
		prev = next = this;
	}
};

class CircularDLL{
public:
	Node* tail;
	int size;
	int getSize(){ return size; }
	CircularDLL(){
		size = 0;
		tail = nullptr;
	}
	void insertBeg(int data);
	void insertEnd(int data);
	void insertAt(int index, int data);
	int deleteBeg();
	int deleteEnd();
	int deleteAt(int index);
	void Display();
};

void CircularDLL::insertBeg(int data){
	Node* newNode = new Node(data);
	if(!tail)
		tail = newNode;
	else{
		Node *p = tail->next;
		newNode->next = p;
		newNode->prev = tail;
		tail->next = newNode;
		p->prev = newNode;
	}
	size++;
}

void CircularDLL::insertEnd(int data){
	Node* newNode = new Node(data);
	if(!tail)
		tail = newNode;
	else{
		Node* p = tail->next;
		newNode->next = p;
		newNode->prev = tail;
		tail->next = newNode;
		p->prev = newNode;
		tail = newNode;
	}
	size++;
}

void CircularDLL::insertAt(int index, int data){
	Node* newNode = new Node(data);
	if(!tail)
		tail = newNode;
	else if(index <= 0)
		insertBeg(data);
	else if(index >= size)
		insertEnd(data);
	else{
		Node* p = tail->next;
		for(int i=0; i<index-1; i++)
			p = p->next;
		newNode->next = p->next;
		newNode->prev = p;
		p->next->prev = newNode;
		p->next = newNode;
		size++;
	}
}

int CircularDLL::deleteBeg(){
	int val = -1;
	Node *p;
	if(!tail) 
		return -1;
	p = tail->next;
	tail->next = p->next;
	p->next->prev = tail;
	val = p->data;
	if(p==tail) 
		tail = nullptr;
	delete p;
	size--;
	return val;
}

int CircularDLL::deleteEnd(){
	int val = -1;
	Node *p;
	if(!tail) 
		return -1;
	p = tail;
	tail = tail->prev;
	tail->next = p->next;
	p->next->prev = tail;
	val = p->data;
	if(p == tail)
		tail = nullptr;
	delete p;
	size--;
	return val;
}

int CircularDLL::deleteAt(int index){
	int i, val = -1;
	Node *p;
	if(!tail) return -1;
	else if(index <= 0) val = deleteBeg();
	else if(index >= getSize()) val = deleteEnd();
	else{
		p = tail->next;
		for(i=0; i<index; i++){
			p = p->next;
		}
		p->prev->next = p->next;
		p->next->prev = p->prev;
		val = p->data;
		delete p;
		size --;
	}
	return val;
}

void CircularDLL::Display(){
	if(tail == nullptr)
		return;
	Node* ptr = tail->next;
	do{
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}while(ptr!=tail->next);
	cout<<endl;
}

int main(){
	CircularDLL c;
	c.insertEnd(45);
	c.insertEnd(-67);
	c.insertEnd(23);
	c.insertEnd(5555);
	c.Display();
	cout<<"After deleting "<<c.deleteAt(4)<<endl;
	c.Display();
}