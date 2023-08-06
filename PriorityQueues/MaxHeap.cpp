#include<iostream>

using namespace std;

void swap(int *x, int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

class MaxHeap{
private:
	int* a;
	int capacity;
	int size;
public:
	MaxHeap(int capac = 10);
	void doubleSize();
	void percolateUp(int i);
	void percolateDown(int i);
	void Insert(int key);
	int Delete();
	void Display();
};

MaxHeap::MaxHeap(int capac){
	capacity = capac;
	a = new int[capacity];
	size = 0;
}

void MaxHeap::doubleSize(){
	int *temp = new int[2*capacity];
	for(int i=0; i<size; i++){
		temp[i] = a[i];
 	}
 	a = temp;
 	temp = nullptr;
}

void MaxHeap::percolateDown(int i){
	int l,r,largest;
	largest = i;
	l = 2*i + 1;
	r = 2*i + 2;
	if(l<size && a[l] > a[largest])
		largest = l;
	if(r<size && a[r]> a[largest])
		largest = r;
	if(largest != i){
		swap(a[i], a[largest]);
		percolateDown(largest);
	}
}

void MaxHeap::percolateUp(int i){
	int parent = (i-1)/2;
	if(parent<0)
		return;
	if(a[parent] < a[i]){
		swap(a[parent], a[i]);
		percolateUp(parent);
	}
}

void MaxHeap::Insert(int key){
	a[size++] = key;
	for(int i=size/2 -1 ; i>=0; i--)
		percolateUp(i);
}

int MaxHeap::Delete(){
	int val = a[0];
	a[0] = a[--size];
	percolateDown(0);
	return val; 

}

void MaxHeap::Display(){
	for(int i=0; i<size; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main(){
	MaxHeap h;
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



