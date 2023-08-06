#include<iostream>

using namespace std;

void swap(int *x, int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

class MinHeap{
private:
	int* a;
	int capacity;
	int size;
public:
 	MinHeap(int capac = 10);
	void doubleSize();
	void percolateUp(int i);
	void percolateDown(int i);
	void Insert(int key);
	int Delete();
	void Display();
};

MinHeap::MinHeap(int capac){
	capacity = capac;
	a = new int[capacity];
	size = 0;
}

void MinHeap::doubleSize(){
	int *temp = new int[2*capacity];
	for(int i=0; i<size; i++){
		temp[i] = a[i];
 	}
 	a = temp;
 	temp = nullptr;
}

void MinHeap::percolateDown(int i){
	int l,r, smallest;
	smallest = i;
	l = 2*i + 1;
	r = 2*i + 2;
	if(l<size && a[l] < a[smallest])
		smallest = l;
	if(r<size && a[r]< a[ smallest])
		smallest = r;
	if( smallest != i){
		swap(a[i], a[ smallest]);
		percolateDown( smallest);
	}
}

void MinHeap::percolateUp(int i){
	int parent = (i-1)/2;
	if(parent<0)
		return;
	if(a[parent] > a[i]){
		swap(a[parent], a[i]);
		percolateUp(parent);
	}
}

void MinHeap::Insert(int key){
	a[size++] = key;
	for(int i = size/2 -1; i>=0; i--)
		percolateUp(i);
}

int MinHeap::Delete(){
	int val = a[0];
	a[0] = a[--size];
	percolateDown(0);
	return val; 

}

void MinHeap::Display(){
	for(int i=0; i<size; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main(){
 MinHeap h;
	h.Insert(27);
	h.Insert(19);
	h.Insert(20);
	h.Insert(10);
	h.Insert(7);
	h.Insert(50);
	h.Display();
	cout<<"You deleted "<< h.Delete()<<endl;
	h.Display();
}



