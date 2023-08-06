#include<iostream>
#define INFINITY 9999
#define MAX 10

using namespace std;

void Dijkstra(int start, int AdjMatrix[MAX][MAX], int n){
	int i,j,minDistance,cost[MAX][MAX], dist[n], nextNode,w;
	bool visited[MAX];
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(AdjMatrix[i][j] != 0)
				cost[i][j] = AdjMatrix[i][j];
			else
				cost[i][j] = INFINITY;
		}
	}

	for(i=0; i<n; i++){
		visited[i] = false;
		dist[i] = cost[start][i];
	}

	visited[start] = true;  dist[start] = 0;
	for(int num=1; num<n-1; num++){
		minDistance = INFINITY;
		for(i=1; i<n; i++){
			if(visited[i] == false && dist[i]<minDistance){
				nextNode = i;
				minDistance = dist[i];
			}
		}
		visited[nextNode] = true;
		for(w=0; w<n; w++){
			if(visited[w] == false){
				if(dist[w] > dist[nextNode] + cost[nextNode][w])
					dist[w] = dist[nextNode] + cost[nextNode][w];
			}
		}
	}

	for(i=0; i<n; i++){
		cout<<"Distance from source to "<<i<<": "<<dist[i]<<endl;
	}
}
int main(){
	int V, start;
	int AdjMatrix[MAX][MAX] = {{0,50,45,10,0,0},
					  {0,0,10,15,0,0},
					  {0,0,0,0,30,0},
					  {20,0,0,0,15,0},
					  {0,20,35,0,0,0},
					  {0,0,0,3,0,0}};
	V = 6;
	start = 0;
	Dijkstra(start,AdjMatrix, V);

}