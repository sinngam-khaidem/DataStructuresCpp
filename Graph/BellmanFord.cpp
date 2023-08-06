#include<iostream>
#include<vector>
#define MAX 10
#define INFINITY 9999
using namespace std;

int n = 7;
int cost[MAX][MAX] = {{0,6,5,5,0,0,0},
					{0,0,0,0,-1,0,0},
					{0,-2,0,0,1,0,0},
					{0,0,-2,0,0,-1,0},
					{0,0,0,0,0,0,3},
					{0,0,0,0,0,0,3},
					{0,0,0,0,0,0,0}};
int dist[MAX];

class Edge{public:
	int u;
	int v;
	Edge(int x, int y){
		u = x;
		v = y;
	}
};

bool BellmanFord(int start){
	int i,j;
	vector<Edge> vec;

	//Initializing distance array
	for(i=0; i<n; i++){
		if(cost[start][i] != 0)
			dist[i] = cost[start][i];
		else
			dist[i] = INFINITY;
	}

	//Making a vector of edges.
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(cost[i][j] != 0){
				vec.push_back(Edge(i,j));
			}
		}
	}
	dist[start] = 0;

	for(int num=1; num<=n-1; num++){
		for(auto e: vec){
			if(dist[e.u] + cost[e.u][e.v] < dist[e.v])
				dist[e.v] = dist[e.u] + cost[e.u][e.v];
		}	
	}

	//Checking presence of negative weight cycle
	for(auto e: vec){
		if(dist[e.u] + cost[e.u][e.v] < dist[e.v])
			return false;
	}	
	return true;
}

int main(){
	bool check;
	check = BellmanFord(0);
	if(check){
		for(int i=0; i<n; i++){
			cout<<"Distance from source to "<<i<<": "<<dist[i]<<endl;
		}
	}
	else{
		cout<<"Negative weight cycle present."<<endl;
	}
}