#include<iostream>
#define INFINITY 9999
#define V 12

int G[V][V] = {{9,0,7,3,2,0,0,0,0,0,0,0},
				{0,0,0,0,0,4,2,1,0,0,0,0},
				{0,0,0,0,0,2,7,0,0,0,0,0},
				{0,0,0,0,0,0,0,11,0,0,0,0},
				{0,0,0,0,0,0,11,8,0,0,0,0},
				{0,0,0,0,0,0,0,0,6,5,0,0},
				{0,0,0,0,0,0,0,0,4,3,0,0},
				{0,0,0,0,0,0,0,0,0,5,6,0},
				{0,0,0,0,0,0,0,0,0,0,0,4},
				{0,0,0,0,0,0,0,0,0,0,0,2},
				{0,0,0,0,0,0,0,0,0,0,0,5},
				{0,0,0,0,0,0,0,0,0,0,0,0}};

float c(int a, int b){
	return G[a][b];
}

void FGraph(int k, int n, int *p){
	float cost[n], min;
	int d[n];
	int i,j,r, minVertex;
	for(i=0; i<n; i++) {
		cost[i] = 0.0;
		d[i] = i;
	}
	for(j = n-2; j>=0; j--){
		cost[j] = INFINITY;
		minVertex = 0;
		for(r=0; r<n; r++){
			if(G[j][r] != 0){
				min = c(j, r) + cost[r];
				if(min < cost[j]){
					cost[j] = min;
					minVertex = r;
				} 
			}
		}
		d[j] = minVertex;
	}

	p[0] = 0; p[k-1] = n-1;
	for(j=1; j<k-1; j++){
		p[j] = d[p[j-1]];
	}
}

int main(){
	int stages = 5;
	int vertices = V;
	int path[stages];
	FGraph(stages, vertices, path);
	for(int i=0; i<stages; i++)
		std::cout<<path[i]<<" ";
	std::cout<<std::endl;
}