#include<iostream>
#include "Queue.h"
#define PRIORITIES 3
#define MAX 10

using namespace std;

struct Element{
	char Id;
	int priority;
};

class PriorityQueues{
private:
	int max_priority;
	Queue **MyQueues;
public:
	PriorityQueues();
	void Insert(struct Element* x);
	char Delete();
	void DisplayPriorityQueues();
};

PriorityQueues::PriorityQueues(){
	int i,n;
	MyQueues = new Queue*[PRIORITIES];
	n = sizeof(MyQueues)/sizeof(MyQueues[0]);
	for(i=0; i<n; i++){
		MyQueues[i] = new Queue(MAX);
	}
}

void PriorityQueues::Insert(struct Element* x){
	int p = x->priority, i;
	MyQueues[p-1]->enqueue(x->Id);
}

char PriorityQueues::Delete(){
	char x = '\0';
	int i;
	for(i=0; i<PRIORITIES; i++)
		if(!MyQueues[i]->isEmpty()){
			x=MyQueues[i]->dequeue();
			break;
		}
	return x;
}

void PriorityQueues::DisplayPriorityQueues(){
	int i;
	for(i=0; i<PRIORITIES; i++){
		MyQueues[i]->Display();
	}
}

int main(){
	struct Element inputs[] = {{'A', 1}, {'B', 1}, {'C', 2}, {'D', 3}, {'E',2}, {'F', 1}, {'G', 2}, {'H', 3}, {'I', 2}, {'J',2}};
	PriorityQueues *P = new PriorityQueues();
	int n,i;
	n = sizeof(inputs)/sizeof(inputs[0]);
	for(i=0; i<n; i++){
		P->Insert(&inputs[i]);
	}
	P->DisplayPriorityQueues();




}