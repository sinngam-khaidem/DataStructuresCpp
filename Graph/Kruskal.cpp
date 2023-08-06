//Kruskal Algorithm using min heap -- O(nlogn)
#include<iostream>
#include<queue>
#define MAXVERTEX 10 
#define MAXEDGE 10

using namespace std;

class Edge{
public:
    int start;
    int stop;
    int cost;
    Edge(int start, int stop, int cost){
        this->start = start;
        this->stop = stop;
        this->cost = cost;
    }
};

class DisjointSet{
public:
    int parent[MAXVERTEX];
    int rank[MAXVERTEX];
    int size;
    DisjointSet(int size);
    int FindParent(int component);
    void Union(int u, int v);
};

DisjointSet::DisjointSet(int size){vb                                         b 
    this->size = size;
    for(int i=0; i<size; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int DisjointSet::FindParent(int component){
    if(parent[component] == component)
        return component;
    return FindParent(parent[component]);
}

void DisjointSet::Union(int u, int v){
    if(rank[u] > rank[v])
        parent[v] = u;
    else if(rank[v] > rank[u])
        parent[u] = v;
    else{
        rank[u]++;
        parent[u] = v;
    }
}

class Cmp{
public:
    bool operator()(Edge p, Edge q){
        return p.cost > q.cost;
    }
};

void Kruskal(int edges[MAXEDGE][3], int numEdge, int numVertex){
    priority_queue<Edge, vector<Edge>, Cmp> pq;
    DisjointSet d(numVertex);
    Edge e(-1,-1,-1);
    int x,y;
    int minCost = 0;
    for(int i=0; i<numEdge; i++){
        pq.push(Edge(edges[i][0], edges[i][1], edges[i][2]));
    }
    while(!pq.empty()){
        e = pq.top(); pq.pop();
        x = d.FindParent(e.start);
        y = d.FindParent(e.stop);
        if(x != y){
            d.Union(x, y);
            minCost += e.cost;
            cout<<e.start <<" - "<<e.stop<<" = "<<e.cost<<endl;
        }
    }
    cout<<"Number of edges is "<<numVertex-1<<endl;
    cout<<"Minimum cost spannning tree: "<<minCost<<endl;
}

int main(){
    int numEdge = 9;
    int numVertex = 8;
    // int edges[numEdge][3] = { { 0, 1, 10 },
    //       { 0, 2, 6 },
    //       { 0, 3, 5 },
    //       { 1, 3, 15 },
    //       { 2, 3, 4 } };
    int edges[numEdge][3] = {{0,1,1},
                            {0,2,7},
                            {1,3,4},
                            {1,4,9},
                            {2,3,5},
                            {4,6,8},
                            {4,5,3},
                            {5,7,6},
                            {6,7,2}};
    Kruskal(edges, numEdge, numVertex);
 
}