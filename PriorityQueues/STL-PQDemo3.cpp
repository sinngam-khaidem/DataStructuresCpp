#include<iostream>
#include<queue>

using namespace std;

class Cmp{
public:
	bool operator()(int& p, int& q){
		return p > q;
	}
};

//Maxheap - <
//Minheap - >

int main(){
	priority_queue<int, vector<int>, Cmp> pq;
	pq.push(45);
	pq.push(2);
	pq.push(23);
	pq.push(67);
	pq.push(10);

	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;
}