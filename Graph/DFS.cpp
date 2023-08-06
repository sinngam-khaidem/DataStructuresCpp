#include<iostream>
#include<stack>
#define MAX 10

using namespace std;

int n = 7; //number of vertices
int G[MAX][MAX] = {{0,1,0,1,1,0,0},
					{1,0,1,0,0,1,1},
					{0,1,0,0,0,0,0},
					{1,0,0,0,0,0,0},
					{1,0,0,0,0,0,0},
					{0,1,0,0,0,0,0},
					{0,1,0,0,0,0,0}};
bool visited[MAX];

int getAdjacentUnvisitedVertex(int v){
	for(int j=0; j<n; j++){
		if(G[v][j] != 0 && visited[j] == false)
			return j;
	}
	return -1;
}

void resetVisitedList(){
	for(int i=0; i<n; i++)	visited[i] = false;
}

void DFS(int start){
	int i,v;
	resetVisitedList();
	stack<int> stk;
	stk.push(start);
	visited[start] = true;
	cout<<start<<" ";
	while(!stk.empty()){
		v = getAdjacentUnvisitedVertex(stk.top());
		if(v == -1){
			stk.pop();
		}
		else{
			stk.push(v);
			visited[v] = true;
			cout<<v<<" ";
		}
	}
	cout<<endl;
	//reset
	resetVisitedList();
}

int main(){
	DFS(1);
}
