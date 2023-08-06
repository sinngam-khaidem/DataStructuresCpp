//BST
#include<iostream>
#include "queue.h"
#include "stack.h"
#define INT_MIN -9999

using namespace std;

class BST{
public:
	Node* root;
	BST(){ root = nullptr;}
	void createTree();
	void InOrder(Node* p);
	void LevelOrder(Node* p);
	Node* RecursiveSearch(Node* p, int key);
	Node* NonRecursiveSearch(int key);
	Node* NonRecursiveFindMin();
	Node* FindMin(Node* p);
	Node* FindMax(Node* p);
	Node* RecursiveInsert(Node* p, int key);
	Node* RecursiveInsert(Node* p, Node* key);
	int Height(Node* p);
	Node* InPre(Node* p);
	Node* InSucc(Node* p);
	Node* RecursiveDelete(Node* p, int key);
	Node* FindLCA(Node* p, Node* alpha, Node* beta);
	bool isBST(Node *p);
	bool isBST(Node *p, int *prev);
	Node* Append(Node *a, Node* b);
	Node* TreetToList(Node *p);
	void DisplayCDLL(Node* head);
};

void BST::createTree(){
	Node *p, *t;
	int x;
	Queue q(100);
	root = new Node;
	//cout<<"Enter root value: ";
	cin>>x;
	root->data=x;
	root->lchild = nullptr;
	root->rchild = nullptr;
	q.enqueue(root);

	while(!q.isEmpty()){
		p = q.dequeue();
		//cout<<"Enter left child value of "<<p->data<<": ";
		cin >> x;
		if(x != -1){
			t = new Node;
			t->data = x;
			t->lchild = nullptr;
			t->rchild = nullptr;
			p->lchild = t;
			q.enqueue(t);
		}
		//cout << "Enter right child value of "<<p->data<<": ";
		cin>>x;
		if(x!=-1){
			t = new Node;
			t->data = x;
			t->lchild = nullptr;
			t->rchild = nullptr;
			p->rchild = t;
			q.enqueue(t);
		}
	}
}

void BST::LevelOrder(Node* p){
	Queue q(100);
	cout<<p->data<<" ";
	q.enqueue(p);
	while(!q.isEmpty()){
		p = q.dequeue();
		if(p->lchild){
			cout<<p->lchild->data<<" ";
			q.enqueue(p->lchild);
		}
		if(p->rchild){
			cout<<p->rchild->data<<" ";
			q.enqueue(p->rchild);
		}
	}
}

void BST::InOrder(Node* p){
	if(p){
		InOrder(p->lchild);
		cout<< p->data<< " ";
		InOrder(p->rchild);
	}
}

Node* BST::RecursiveSearch(Node* p, int key){
	if(p == nullptr)
		return nullptr;
	if(p->data > key)
		return RecursiveSearch(p->lchild, key);
	if(p->data < key)
		return RecursiveSearch(p->rchild, key);
	return p;
}

Node* BST::NonRecursiveSearch(int key){
	Node* p = root;
	if(p == nullptr) return nullptr;
	while(p){
		if(p->data > key)
			p = p->lchild;
		else if(p->data < key)
			p = p->rchild;
		else{
			return p;
		}
	}
	return nullptr;
}

Node* BST::NonRecursiveFindMin(){
	Node* p = root;
	if(p == nullptr)
		return nullptr;
	while(p->lchild != nullptr)
		p = p->lchild;
	return p;
}

Node* BST::FindMin(Node* p){
	if(p==nullptr)
		return nullptr;
	if(p->lchild != nullptr)
		return FindMin(p->lchild);
	return p;
}

Node* BST::FindMax(Node* p){
	if(p == nullptr)
		return nullptr;
	if(p->rchild != nullptr)
		return FindMax(p->rchild);
	return p;
}

Node* BST::RecursiveInsert(Node* p, int key){
	Node *t = nullptr;
	if(p==nullptr){
		t = new Node(key);
		return t;
	}
	if(p->data>key)
		p->lchild = RecursiveInsert(p->lchild, key);
	else
		p->rchild = RecursiveInsert(p->rchild, key);
	return p;
}

Node* BST::RecursiveInsert(Node* p, Node* key){
	if(p==nullptr){
		return key;
	}
	if(p->data>key->data)
		p->lchild = RecursiveInsert(p->lchild, key);
	else
		p->rchild = RecursiveInsert(p->rchild, key);
	return p;
}

int BST::Height(Node* p){
	if(p == nullptr)
		return -1;
	int l=0,r=0;
	l = Height(p->lchild);
	r = Height(p->rchild);
	return l>r?l+1:r+1;
}

Node* BST::InPre(Node* p){
	while(!p && !p->rchild)
		p = p->rchild;
	return p;
}

Node* BST::InSucc(Node* p){
	while(!p && !p->lchild)
		p = p->lchild;
	return p;
}

Node* BST::RecursiveDelete(Node* p, int key){
	Node *q = nullptr;
	if( p == nullptr)
		return nullptr;
	if(!p->lchild && !p->rchild){
		if(p->data == key){
			delete p;
			p = nullptr;
			return nullptr;
		}
	}
	if(p->data > key)
		p->lchild = RecursiveDelete(p->lchild, key);
	else if(p->data < key)
		p->rchild = RecursiveDelete(p->rchild, key);
	else{
		if(Height(p->lchild) > Height(p->rchild)){
			q = InPre(p->lchild);
			p->data = q->data;
			p->lchild = RecursiveDelete(p->lchild, p->data);
		}
		else{
			q = InSucc(p->rchild);
			p->data = q->data;
			p->rchild = RecursiveDelete(p->rchild, p->data);
		}
	}
	return p;
}

Node* BST::FindLCA(Node* p, Node* alpha, Node* beta){
	while(1){
		if(p->data > alpha->data && p->data < beta->data)
			return p;
		if(p->data < alpha->data)
			p = p->rchild;
		if(p->data > beta->data)
			p = p->lchild;
	}
}

bool BST::isBST(Node *p){
	if(!p)
		return true;
	if(p->lchild && FindMax(p->lchild)->data > p->data)
		return false;
	if(p->rchild && FindMin(p->rchild)->data < p->data)
		return false;
	if(!isBST(p->lchild) || !isBST(p->rchild))
		return false;
	return true;
}

bool BST::isBST(Node* p, int *prev){
	if(!p) return true;
	if(!isBST(p->lchild, prev))
		return false;
	if(p->data < *prev)
		return false;
	*prev = p->data;
	return isBST(p->rchild, prev);
}

Node* BST::Append(Node* a, Node* b){
	//a = head of left CDLL
	//b = head of right CDLL
	//aLast, bLast = last nodes of left and right CDLL resp.
	if(!a)
		return b;
	if(!b)
		return a;
	Node *aLast, *bLast;
	aLast = a->lchild;
	bLast = b->lchild;
	aLast->rchild = b;
	b->lchild = aLast;
	a->lchild = bLast;
	bLast->rchild = a;
	return a;
}

Node* BST::TreetToList(Node *p){
	if(!p)
		return nullptr;
	// aList, bList = head of left and right CDLL resp.
	Node *aList, *bList;
	aList = TreetToList(p->lchild);
	bList = TreetToList(p->rchild);
	p->lchild = p;
	p->rchild = p;
	aList = Append(aList, p);
	aList = Append(aList, bList);
	return aList;
}

void BST::DisplayCDLL(Node *head){
	Node *ptr = head;
	do{
		cout<<ptr->data<<" ";
		ptr = ptr->rchild;
	}while(ptr != head);
}


int main(){
	BST t;
	//int i;
	//t.createTree();
	//int key=0;
	// //Recursive Search
	// //cout<<"Enter the element you want to search: "<<endl;
	// cin>>key;
	// Node* SearchResult = t.RecursiveSearch(t.root, key);
	// if(SearchResult)
	// 	cout<<"The value of search result is "<<SearchResult->data<<endl;


	// //Non Recursive Search
	// //cout<<"Enter the element you want to search: "<<endl;
	// cin>>key;
	// Node* SearchResult = t.NonRecursiveSearch(key);
	// if(SearchResult)
	// 	cout<<"The value of search result is "<<SearchResult->data<<endl;

	// //Find minimum node - NonRec
	// Node* min = t.FindMinimum();
	// if(min)
	// 	cout<<min->data<<endl;

	// //Find minimum node - Rec
	// Node* min = t.FindMin(t.root);
	// if(min)
	// 	cout<<min->data<<endl;

	// //Recursive Insert
	// t.root = t.RecursiveInsert(t.root, 58);
	// t.LevelOrder(t.root);
	// cout<<endl;
	// t.InOrder(t.root);
	// cout<<endl;


	// // Recursive delete
    // t.InOrder(t.root);
    // cout<<endl;
    // // t.root = t.RecursiveDelete(t.root, 8);
    // // t.root = t.RecursiveDelete(t.root, 5);
    // t.InOrder(t.root);
    // cout<<"End of program"<<endl;

    // //Find LCA
    // Node *alpha, *beta, *LCA;
    // alpha = new Node(5);
    // beta = new Node(20);
    // t.root = t.RecursiveInsert(t.root, 32);
    // t.root = t.RecursiveInsert(t.root, 15);
    // t.root = t.RecursiveInsert(t.root, 50);
    // t.root = t.RecursiveInsert(t.root, -4);
    // t.root = t.RecursiveInsert(t.root, 17);
    // t.root = t.RecursiveInsert(t.root, alpha);
    // t.root = t.RecursiveInsert(t.root, beta);

    // LCA = t.FindLCA(t.root, alpha, beta);
    // cout<<LCA->data<<endl;


    //Checking if a binary tree is bst or not
    // t.root = t.RecursiveInsert(t.root, 32);
    // t.root = t.RecursiveInsert(t.root, 15);
    // t.root = t.RecursiveInsert(t.root, 50);
    // t.root = t.RecursiveInsert(t.root, -4);
    // t.root = t.RecursiveInsert(t.root, 17);
    // t.root = t.RecursiveInsert(t.root, 9);
    // t.root = t.RecursiveInsert(t.root, 4);

	// int min = INT_MIN;
    // if(t.isBST(t.root, &min))
    // 	cout<<"The tree is a bst."<<endl;
    // else
    // 	cout<<"Not BST"<<endl;

    //Converting Tree to CDLL
    t.root = t.RecursiveInsert(t.root, 32);
    t.root = t.RecursiveInsert(t.root, 15);
    t.root = t.RecursiveInsert(t.root, 50);
    t.root = t.RecursiveInsert(t.root, -4);
    t.root = t.RecursiveInsert(t.root, 17);

	Node *head = t.TreetToList(t.root);
	t.DisplayCDLL(head);
}

