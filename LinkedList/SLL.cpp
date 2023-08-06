#include<iostream>

using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class LinkedList{
private:
    int size;
public:
	Node* head;
	Node* tail;

    LinkedList(){size=0; head = NULL; tail=NULL;}
    LinkedList(int A[], int n);
    ~LinkedList();

    void InsertFirst(int data);
    void InsertLast(int data);
    void Insert(int data, int index);
    int getSize();
    int Delete(int index);
	void Reverse();
	int isLoop();

    void Display();
	void RDisplay(Node* p);
};

LinkedList::LinkedList(int A[], int n){
    head = new Node;
    head->data = A[0];
    head->next = nullptr;
    tail = head;
    Node* temp;
    size = 0;
    size++;
    for(int i=1; i<n; i++){
        temp = new Node;
        temp->data = A[i];
        temp->next = nullptr;
        tail->next = temp;
        tail = temp;
        size++;
    }
}

LinkedList::~LinkedList(){
    Node* p = head;
    while(head != nullptr){
        head = head->next;
        delete p;
        p = head;
    }
}

int LinkedList::getSize(){
    return size;
}


void LinkedList::InsertFirst(int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    size++;
}

void LinkedList::InsertLast(int data){
    if(head == nullptr){
        InsertFirst(data);
        tail = head;
        return;
    }
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    tail = newNode;
    size++;
}

void LinkedList::Insert(int data, int index){
    if(index<0 || index>size)
        return;
    if(index==0){
        InsertFirst(data);
        return;
    }

    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    Node* temp = head;
    for(int i=0; i<index-1; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    size++;
}

int LinkedList::Delete(int index){
    Node *p, *q;
    int x = -1;

    if(index<0 || index>size-1)
        return x;
    p = head;
    q = nullptr;
    if(index == 0){
        head = p->next;
    }
    else{
        for(int i=0; i<index; i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        if(index == size-1)
            tail = q;
    }
    x = p->data;
    delete p;
    size--;
    return x;
}

int LinkedList::isLoop(){
	Node *p,*q;
	p=q=head;
	do{
		p=p->next;
		q=q->next;
		q=q?q->next:q;
	}while(p && q && p!=q);
	if(p==q)
		return 1;
	else
		return 0;
	
}

void LinkedList::Reverse(){
	Node *p,*q = nullptr;
	while(head != nullptr){
		p = head;
		head = head->next;
		p->next = q;
		q = p;
	}
	head = p;
	p = q = nullptr;
}

void LinkedList::Display(){
    Node* node = head;
    while(node!=nullptr){
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<endl;
}


int main(){
    int A[] = {1,2,3,4,5,6};
    int n = sizeof(A)/sizeof(A[0]);
    LinkedList l1(A,n);

	Node *t1;
	t1 = l1.head->next->next;
	t1->next = l1.head;
	cout<<l1.isLoop()<<endl;
		
}

