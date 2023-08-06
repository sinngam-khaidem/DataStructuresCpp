#include<iostream>
#include<stack>
#include"queue.h"
#include"stack.h"
#define INT_MIN -9999

using std::stack;

using namespace std;


class Tree{
	public:
		Node* root;
		Tree(){root = nullptr;}
		void createTree();
		void NonRecursivePreorder(Node* p);
		void PreOrder(Node* p);
		void NonRecursiveInorder(Node* p);
		void InOrder(Node* p);
		void NonRecursivePostOrder(Node* p);
		void PostOrder(Node* p);
		void LevelOrder(Node* p);
		int Height(Node* p);
		int HeightWithoutRecursion();
		int FindMax(Node* p);
		int IterativeFindMax();
		bool FindInBinaryTreeUsingRecursion(Node* p, int key);
		Node* FindInBinaryTreeWithoutRecursion(int key);
		void InsertInBinaryTree(int data);
		int SizeOfBinaryTree(Node* p);
		int LevelOrderSizeOfBinaryTree();
		void LevelOrderTraversalInReverse();
		void DeleteBinaryTree(Node* p);
		Node* DeepestNode();
		void DeleteDeepestNode();
		void DeleteNode(int key);
		int NumberOfLeaves();
		int NumberOfFullNodesInBTUsingLevelOrder();
};


void Tree::createTree(){
	Node *p, *t;
	int x;
	Queue q(100);
	root = new Node;
	cout<<"Enter root value: ";
	cin>>x;
	root->data=x;
	root->lchild = nullptr;
	root->rchild = nullptr;
	q.enqueue(root);

	while(!q.isEmpty()){
		p = q.dequeue();
		cout<<"Enter left child value of "<<p->data<<": ";
		cin >> x;
		if(x != -1){
			t = new Node;
			t->data = x;
			t->lchild = nullptr;
			t->rchild = nullptr;
			p->lchild = t;
			q.enqueue(t);
		}
		cout << "Enter right child value of "<<p->data<<": ";
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

void Tree::NonRecursiveInorder(Node* p){
    Stack myStack(100);
    while(1){
        while(p){
            myStack.push(p);
            p = p->lchild;
        }
        if(myStack.isEmpty())
            break;
        p = myStack.pop();
        cout<<p->data<<" ";
        p = p->rchild;
    }
    myStack.~Stack();
}
void Tree::InOrder(Node* p){
	if(p){
		InOrder(p->lchild);
		cout<< p->data<< " ";
		InOrder(p->rchild);
	}
}

void Tree::NonRecursivePostOrder(Node* p){

}

void Tree::PostOrder(Node* p){
	if(p){
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		cout<<p->data<<" ";
	}
}

void Tree::NonRecursivePreorder(Node* p){
    Stack myStack(100);
    while(1){
        while(p){
            cout<<p->data<<" ";
            myStack.push(p);
            p = p->lchild;
        }
        if(myStack.isEmpty())
            break;
        p = myStack.pop();
        p = p->rchild;
    }
    myStack.~Stack();
}

void Tree::PreOrder(Node* p){
	if(p){
		cout<<"p->data"<<" ";
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
}

void Tree::LevelOrder(Node* p){
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
int Tree::Height(Node* p){
	int l = 0;
	int r = 0;
	if(p==nullptr)
		return -1;
	l = Height(p->lchild);
	r = Height(p->rchild);
	if(l>r){
		return l+1;
	}
	else{
		return r+1;
	}
}

int Tree::HeightWithoutRecursion(){
	Node* p = root;
	int height = -1;
	if(!p)
		return 0;
	Queue q(100);
	q.enqueue(p);
	q.enqueue(nullptr);
	while(!q.isEmpty()){
		p = q.dequeue();
		if(p == nullptr){
			if(!q.isEmpty())
				q.enqueue(nullptr);
			height++;
		}
		else{
			if(p->lchild)
				q.enqueue(p->lchild);
			if(p->rchild)
				q.enqueue(p->rchild);
		}
	}
	return height;
}

int Tree::FindMax(Node* p){
	int val, left, right, max = INT_MIN;
	if(p != nullptr){
		val = p->data;
		left = FindMax(p->lchild);
		right = FindMax(p->rchild);
		if(left>right)
			max = left;
		else
			max = right;
		if(max<val)
			max = val;
	}
	return max;
}

int Tree::IterativeFindMax(){
	int max = INT_MIN;
	Node* p = root;
	if(p->data>max)
		max = p->data;
	Queue q(100);
	q.enqueue(p);
	while(!q.isEmpty()){
		p = q.dequeue();
		if(p->lchild){
			if(p->lchild->data > max)
				max = p->lchild->data;
			q.enqueue(p->lchild);
		}
		if(p->rchild){
			if(p->rchild->data > max)
				max = p->rchild->data;
			q.enqueue(p->rchild);
		}
	}
	return max;
}

bool Tree::FindInBinaryTreeUsingRecursion(Node* p, int key){
	if(p->data == key)
		return true;
	bool l, r;
	l = false;
	r = false;
	if(p->lchild){
		l = FindInBinaryTreeUsingRecursion(p->lchild, key);
	}
	if(p->rchild){
		r = FindInBinaryTreeUsingRecursion(p->rchild, key);
	}
	if(l == true || r == true)
		return true;
	else
		return false;
}

Node* Tree::FindInBinaryTreeWithoutRecursion(int key){
	Node* p = root;
	if(p->data == key)
		return p;
	Queue q(100);
	q.enqueue(p);
	while(!q.isEmpty()){
		p = q.dequeue();
		if(p->lchild){
			if(p->lchild->data == key)
				return p->lchild;
			q.enqueue(p->lchild);
		}
		if(p->rchild){
			if(p->rchild->data == key)
				return p->rchild;
			q.enqueue(p->rchild);
		}
	}
	return nullptr;
}

void Tree::InsertInBinaryTree(int data){
	Node* p = root;
	Node* newNode = new Node;
	newNode->data = data;
	newNode->lchild = newNode->rchild = nullptr;
	if(p==nullptr){
		p = newNode;
		return;
	}
	if(p->lchild == nullptr){
		p->lchild = newNode;
		return;
	}
	if(p->rchild == nullptr){
		p->rchild = newNode;
		return;
	}
	Queue q(100);
	q.enqueue(p);
	while(!q.isEmpty()){
		p = q.dequeue();
		if(p->lchild){
			if(p->lchild->lchild == nullptr){
				p->lchild->lchild = newNode;
				return;
			}
			if(p->lchild->rchild == nullptr){
				p->lchild->rchild = newNode;
				return;
			}
			q.enqueue(p->lchild);
		}
		if(p->rchild){
			if(p->rchild->lchild == nullptr){
				p->rchild->lchild = newNode;
				return;
			}
			if(p->rchild->rchild == nullptr){
				p->rchild->rchild = newNode;
				return;
			}
			q.enqueue(p->rchild);
		}
	}
}	

int Tree::SizeOfBinaryTree(Node* p){
	if(p==nullptr)
		return 0;
	int l,r;
	l=r=0;
	l = SizeOfBinaryTree(p->lchild);
	r = SizeOfBinaryTree(p->rchild);
	return l+r+1;
}

int Tree::LevelOrderSizeOfBinaryTree(){
	int count = 0;
	Node* p = root;
	Queue q(100);
	if(p!=nullptr)
		count++;
	q.enqueue(p);
	while(!q.isEmpty()){
		p = q.dequeue();
		if(p->lchild){
			count++;
			q.enqueue(p->lchild);
		}
		if(p->rchild){
			count++;
			q.enqueue(p->rchild);
		}
	}
	return count;
}

void Tree::LevelOrderTraversalInReverse(){
	Node* p = root;
	Queue q(50);
	stack<int> stk;
	stk.push(p->data);
	q.enqueue(p);
	while(!q.isEmpty()){
		p = q.dequeue();
		if(p->lchild){
			stk.push(p->lchild->data);
			q.enqueue(p->lchild);
		}
		if(p->rchild){
			stk.push(p->rchild->data);
			q.enqueue(p->rchild);
		}
	}
	while(!stk.empty()){
		cout<<stk.top()<<" ";
		stk.pop();
	}
}

Node* Tree::DeepestNode(){
	Node* p = root;
	Queue q(100);
	q.enqueue(p);
	while(!q.isEmpty()){
		p = q.dequeue();
		if(p->lchild)
			q.enqueue(p->lchild);
		if(p->rchild)
			q.enqueue(p->rchild);
	}
	return p;
}

void Tree::DeleteDeepestNode(){
	Node *t=nullptr,*p = root;
	Queue q(50);
	Queue n(50);
	q.enqueue(p);
	n.enqueue(p);
	int i=0;
	while(!q.isEmpty()){
		p = q.dequeue();
		i++;
		if(i%2 == 0)
			t = n.dequeue();
		if(p->lchild){
			q.enqueue(p->lchild);
			n.enqueue(p->lchild);
		}
		if(p->rchild){
			q.enqueue(p->rchild);
			n.enqueue(p->rchild);
		}
	}
	if(t->lchild == p){
		t->lchild = nullptr;
	}
	else{
		t->rchild = nullptr;
	}
	delete p;
	p = nullptr;
}

void Tree::DeleteNode(int key){
	Node* target = FindInBinaryTreeWithoutRecursion(key);
	if(target == nullptr)
		cout<<"Key not found."<<endl;
	else{
		Node* deepest = DeepestNode();
		target->data = deepest->data;
		DeleteDeepestNode();
		cout<<"Key deleted successfully."<<endl;
	}
}

int Tree::NumberOfLeaves(){
	Node* p = root;
	int count = 0;
	if(p == nullptr)
		return 0;
	Queue q(100);
	if(!p->lchild && !p->rchild)
		count++;
	q.enqueue(p);
	while(!q.isEmpty()){
		p = q.dequeue();
		if(p->lchild){
			if(!p->lchild->lchild && !p->lchild->rchild)
				count++;
			q.enqueue(p->lchild);
		}
		if(p->rchild){
			if(!p->rchild->lchild && !p->rchild->rchild)
				count++;
			q.enqueue(p->rchild);
		}
	}
	return count;
}

int Tree::NumberOfFullNodesInBTUsingLevelOrder(){
	int count = 0;
	Node* p = root;
	Queue q(100);
	q.enqueue(p);
	if(p->lchild && p->rchild)
		count++;
	while(!q.isEmpty()){
		p = q.dequeue();
		if(p->lchild){
			if(p->lchild->lchild && p->lchild->rchild)
				count++;
			q.enqueue(p->lchild);
		}
		if(p->rchild){
			if(p->rchild->lchild && p->rchild->rchild)
				count++;
			q.enqueue(p->rchild);
		}
	}
	return count;
}

// void Tree::DeleteBinaryTree(Node* p){
// //Delete the children node before deleting the parent. Use Post order traversal.
// 	if(p != nullptr){
// 		DeleteBinaryTree(p->lchild);
// 		DeleteBinaryTree(p->rchild);
// 		delete p;
// 	}
// }

int main(){
	Tree t;
	t.createTree();
	// cout<<t.IterativeFindMax()<<endl;
	// int check;
	// check = t.FindInBinaryTreeUsingRecursion(t.root, 900);
	// if(check == true)
	// 	cout<<"Present"<<endl;
	// else
	// 	cout<<"Absent"<<endl;

	// check = t.FindInBinaryTreeWithoutRecursion(8);
	// if(check == true)
	// 	cout<<"Present"<<endl;
	// else
	// 	cout<<"Absent"<<endl;

	// t.InsertInBinaryTree(44);
	// t.LevelOrder(t.root);
	// cout<<endl;
	// cout<<"Size of Binary tree using recursion is "<<t.SizeOfBinaryTree(t.root)<<endl;
	// cout<<"Size of Binary tree without recursion is "<<t.LevelOrderSizeOfBinaryTree()<<endl;

	// t.LevelOrder(t.root);
	// cout<<endl;
	// t.LevelOrderTraversalInReverse();
	// cout<<endl;

	// //Deleting the binary tree.
	// cout<<"Before deleting. "<< t.SizeOfBinaryTree(t.root)<<endl;
	// t.PostOrder(t.root);
	// cout<<endl;
	// t.DeleteBinaryTree(t.root);

	// cout<<"After deleting. "<< t.SizeOfBinaryTree(t.root)<<endl; 

	// //Height of Binary tree.
	// cout<<"Height with recursion "<<t.Height(t.root)<<endl;
	// cout<<"Height Without Recursion "<<t.HeightWithoutRecursion()<<endl;

	// //Deepest Node of a binary tree
	// Node* deepest = t.DeepestNode();
	// cout<<"Data of deepest Node: "<<deepest->data<<endl;

	// t.LevelOrder(t.root);
	// t.DeleteDeepestNode();
	// t.LevelOrder(t.root);

	// //Delete Node using key
	// int key;
	// cout<<"Enter key to be deleted: "<<endl;
	// cin>>key;
	// t.DeleteNode(key);
	// t.LevelOrder(t.root);
	// cout<<endl;
	// cout<<endl;

	// //Counting number of leaves.
	// cout<<"Number of leaves is "<<t.NumberOfLeaves()<<endl;

	//Counting number of full nodes.
	cout<<"Number of full nodes is "<<t.NumberOfFullNodesInBTUsingLevelOrder()<<endl;

}






