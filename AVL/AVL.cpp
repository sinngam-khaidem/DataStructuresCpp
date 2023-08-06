#include<iostream>

using namespace std;

class Node{
public:
	Node *lchild, *rchild;
	int data;
	int height;
	Node(int data){
		lchild = rchild = nullptr;
		this->data = data;
		height = 1;
	}
};

class AVLTree{
public:
	Node* root;
	AVLTree(){
		root = nullptr;
	}
	int NodeHeight(Node *p);
	int BalanceFactor(Node *p);
	Node* LLRotation(Node* p);
	Node* RRRotation(Node* p);
	Node* LRRotation(Node* p);
	Node* RLRotation(Node *p);
	Node* InPre(Node *p);
	Node* InSucc(Node *p);
	Node* insertNode(Node* p, int key);
	Node* deleteNode(Node* p, int key);
	void Inorder(Node *p);
};

//Height of leaf node is 1.
int AVLTree::NodeHeight(Node *p){
	int hl, hr;
	hl = (p && p->lchild)? p->lchild->height:0;
	hr = (p && p->rchild)? p->rchild->height:0;
	return hl>hr?hl+1:hr+1;
}

int AVLTree::BalanceFactor(Node *p){
	int hl, hr;
	hl = (p && p->lchild)? p->lchild->height:0;
	hr = (p && p->rchild)? p->rchild->height:0;
	return hl-hr;
}

Node* AVLTree::LLRotation(Node *p){
	Node *pl = p->lchild;
	Node *plr = pl->rchild;

	pl->rchild = p;
	p->lchild = plr;

	pl->height = NodeHeight(pl);
	p->height = NodeHeight(p);
	if(p == root)
		root = pl;
	return pl;
}

Node* AVLTree::LRRotation(Node *p){
	Node *pl = p->lchild;
	Node *plr = pl->rchild;

	p->lchild = plr->rchild;
	pl->rchild = plr->lchild;
	plr->lchild = pl;
	plr->rchild = p;

	p->height = NodeHeight(p);
	pl->height = NodeHeight(pl);
	plr->height = NodeHeight(plr);
	if(p == root)
		root = plr;
	return plr;
}

Node* AVLTree::RRRotation(Node *p){
	Node *pr = p->rchild;
	Node *prl = pr->lchild;

	p->rchild = prl;
	pr->lchild = p;
	p->height = NodeHeight(p);
	pr->height = NodeHeight(pr);

	if(p == root)
		root = pr;
	return pr;	
}

Node* AVLTree::RLRotation(Node *p){
	Node *pr = p->rchild;
	Node *prl = pr->lchild;

	p->rchild = prl->lchild;
	pr->lchild = prl->rchild;
	prl->lchild = p;
	prl->rchild = pr;

	p->height = NodeHeight(p);
	pr->height = NodeHeight(pr);
	prl->height = NodeHeight(prl);
	if( p== root)
		root = prl;
	return prl;
}

Node* AVLTree::insertNode(Node *p, int key){
	Node *t = nullptr;
	if(!p){
		t = new Node(key);
		return t;
	}
	if(p->data > key)
		p->lchild = insertNode(p->lchild, key);
	else
		p->rchild = insertNode(p->rchild, key);
	p->height = NodeHeight(p);
	if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
		return LLRotation(p);
	else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
		return LRRotation(p);
	else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
		return RLRotation(p);
	else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
		return RRRotation(p);
	return p;
}

Node* AVLTree::deleteNode(Node *p, int key){
	if(p==nullptr)
		return nullptr;
	if(!p->lchild && !p->rchild){
		if(p->data == key){
			delete p;
			return nullptr;
		}
	}

	if(p->data > key)
		p->lchild = deleteNode(p->lchild, key);
	else if(p->data < key)
		p->rchild = deleteNode(p->rchild, key);
	else{
		Node *t;
		if(NodeHeight(p->lchild) > NodeHeight(p->rchild)){
			t = InPre(p->lchild);
			p->data = t->data;
			p->lchild = deleteNode(p->lchild, t->data);
			if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1 || BalanceFactor(p->rchild) == 0){
				return RLRotation(p);
			}
			else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1){
				return RRRotation(p);
			}
		}
		else{
			t = InSucc(p->rchild);
			p->data = t->data;
			p->rchild = deleteNode(p->rchild, t->data);
			if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1 || BalanceFactor(p->rchild) == 0){
				return LLRotation(p);
			}
			else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){
				return LRRotation(p);
			}
		}
	}
	return p;
}

Node* AVLTree::InPre(Node* p){
	while(p->rchild)
		p = p->rchild;
	return p;
}

Node* AVLTree::InSucc(Node* p){
	while(p->lchild)
		p = p->lchild;
	return p;
}

void AVLTree::Inorder(Node *p){
	if(p){
		Inorder(p->lchild);
		cout<<p->data<<" ";
		Inorder(p->rchild);
	}
}

int main(){
	AVLTree a;
	// a.root = a.insertNode(a.root, 30);
	// a.root = a.insertNode(a.root, 20);
	// a.root = a.insertNode(a.root, 40);
	// a.root = a.insertNode(a.root, 10);
	// a.root = a.insertNode(a.root, 25);
	// a.root = a.insertNode(a.root, 50);
	// a.root = a.insertNode(a.root, 5);
	// a.root = a.insertNode(a.root, 15);
	// a.root = a.insertNode(a.root, 28);
	// cout<<"Root before inserting 4: "<<a.root->data<<endl;
	// a.Inorder(a.root);
	// cout<<endl;
	// a.root = a.insertNode(a.root, 4);
	// cout<<"Root after inserting 4: "<<a.root->data<<endl;
	// a.Inorder(a.root);
	// cout<<endl;

	//Deletion test
	a.root = a.insertNode(a.root, 30);
	a.root = a.insertNode(a.root, 10);
	a.root = a.insertNode(a.root, 40);
	a.root = a.insertNode(a.root, 20);
	a.root = a.insertNode(a.root, 5);
	a.Inorder(a.root);
	cout<<endl;
	a.root = a.deleteNode(a.root, 40);
	a.Inorder(a.root);
	cout<<endl;
}