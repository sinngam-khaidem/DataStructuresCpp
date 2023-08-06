#include<iostream>
using namespace std;

class Node{
public:
	Node* prev;
	int data;
	Node* next;
	Node(int x){
		data = x;
		prev = next = nullptr;
	}
};

class DLL{
public:
	Node* head;
	Node* tail;
	int size;
	DLL(){
		head = tail = nullptr;
		size = 0;
	}
	int getSize(){ return size;}
	void insertBeg(int data);
	void insertEnd(int data);
	void insertAt(int index, int data);
	int deleteBeg();
	int deleteEnd();
	int deleteAt(int index);
	Node* reverse();
	void Display();
};

void DLL::insertBeg(int data){
	Node *newNode = new Node(data);
	if(!head) 
		head = tail = newNode;
	else{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	size++;
}

void DLL::insertEnd(int data){
	Node *newNode = new Node(data);
	if(!head)
		head = tail = newNode;
	else{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	size++;
}

void DLL::insertAt(int index, int data){
	Node* newNode = new Node(data);
	if(!head)
		head = tail = newNode;
	else{
		if(index<=0){
			insertBeg(data);
			return;
		}
		else if(index >= size){
			insertEnd(data);
			return;
		}
		else{
			Node *p = head, *q = nullptr;
			int i;
			for(i=0; i<index; i++){
				q = p;
				p = p->next;
			}
			q->next = newNode;
			p->prev = newNode;
			newNode->prev = q;
			newNode->next = p;
			size++;
		}
	}
}

int DLL::deleteBeg(){
	int val;
	Node* p;
	if(!head) return -1;
	else if(size == 1){
		p = head;
		val = p->data;
		head = tail = nullptr;
		delete p;
		p = nullptr;
	}
	else{
		p = head;
		val = p->data;
		head = head->next;
		head->prev = nullptr;
		delete p;
		p = nullptr;
	}
	size--;
	return val;
}

int DLL::deleteEnd(){
	int val;
	Node* p;
	if(!head) return -1;
	else if(getSize()==1){
		p = head;
		val = p->data;
		head = tail = nullptr;
		delete p;
		p = nullptr;
	}
	else{
		p = tail;
		val = p->data;
		tail = tail->prev;
		tail->next = nullptr;
		delete p;
		p = nullptr;
	}
	size--;
	return val;
}

void DLL::Display(){
	Node* p = head;
	while(p){
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}

int DLL::deleteAt(int index){
	int val;
	Node *p;
	if(!head) return -1;
	else{
		if(index <= 0){
			val = deleteBeg();
		}
		else if(index >= size-1){
			val = deleteEnd();
		}
		else{
			int i;
			p = head;
			for(i=0; i<index; i++){
				p = p->next;
			}
			p->prev->next = p->next;
			p->next->prev = p->prev;
			val = p->data;
			size--;
		}
	}
	return val;
}

Node* DLL::reverse(){
	Node *p, *q;
	p = head; q = nullptr;
	while(p){
		p->prev = p->next;
		p->next = q;
		q = p;
		p = p->prev;
	}
	tail = head;
	head = q;
	return head;
}

int main(){
	DLL d;
	d.insertEnd(4);
	d.insertEnd(56);
	d.insertEnd(-3333);
	d.insertEnd(8956);
	d.Display();
	d.insertAt(3, 72);
	d.Display();
	cout<<"After deleting beg value i.e."<< d.deleteBeg()<<endl;
	d.Display();
	cout<<"After deleting value at index 0 i.e. "<< d.deleteAt(0)<<endl;
	d.Display();
	cout<<"Current size: "<<d.getSize()<<endl;
	d.head = d.reverse();
	d.Display();

}	