#include<iostream>
#include<queue>
#define MAX_TREE_HT 100

using namespace std;

struct MinHeapNode{
	char data;
	int freq;
	struct MinHeapNode *lchild, *rchild;
};

struct MinHeapNode* newNode(char data, int freq){
	struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
	temp->data = data;
	temp->freq = freq;
	temp->lchild = temp->rchild = nullptr;
	return temp;
}

class Cmp{
public:
	bool operator()(MinHeapNode* p, MinHeapNode* q){
		return p->freq > q->freq;
	}
};

struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size){
	priority_queue<struct MinHeapNode*, vector<struct MinHeapNode*>, Cmp> pq;
	for(int i=0; i<size; i++){
		pq.push(newNode(data[i], freq[i]));
	}

	struct MinHeapNode *temp, *left, *right;
	for(int i=1; i<size; i++){ //until size 1
		left = pq.top(); pq.pop();
		right = pq.top(); pq.pop();
		temp = newNode('$', left->data+ right->data);

		temp->lchild = left;
		temp->rchild = right;
		pq.push(temp);
	}
	MinHeapNode* root = pq.top(); pq.pop();
	return root;
}

bool isLeaf(struct MinHeapNode* p){
	if(!p->lchild && !p->rchild)
		return true;
	return false;
}

void printArr(int arr[],int n){
	int i;
	for(i=0;i<n;i++)
		cout<<arr[i];
	cout<<endl;
}

void printCodes(struct MinHeapNode* root, int arr[], int top){
	if(root->lchild){
		arr[top] = 0;
		printCodes(root->lchild, arr, top+1);
	}
	if(root->rchild){
		arr[top] = 1;
		printCodes(root->rchild, arr, top+1);
	}
	if(isLeaf(root)){
		cout<<root->data<<": ";
		printArr(arr, top);
	}
}

void HuffmanCodes(char data[], int freq[], int size){
	struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
	int arr[MAX_TREE_HT], top = 0;
	printCodes(root, arr, top);

}

int main(){
	char arr[] = { 'A', 'B', 'C', 'D', 'E'};
	int freq[] = { 3, 5, 6, 4, 2};

	int size = sizeof(arr) / sizeof(arr[0]);
	HuffmanCodes(arr, freq, size);
}
