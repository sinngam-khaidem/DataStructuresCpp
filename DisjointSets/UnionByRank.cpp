#include<iostream>
#define MAX 20

using namespace std;

class DisjointSet{
public:
    int S[MAX];
    int Rank[MAX];
    int size;
    DisjointSet(int size); //MAKESET(int S[], int size)
    int FIND(int X);
    void UNION(int a, int b);
};

DisjointSet::DisjointSet(int size){
    this->size = size;
    int i;
    for(i=0; i<size; i++){
        S[i] = i;
        Rank[i] = 0;
    }
}

int DisjointSet::FIND(int X){
    if(!(X>=0 && X<size))
        return -1;
    if(S[X] == X)
        return X;
    else
        return FIND(S[X]);
}

void DisjointSet::UNION(int a, int b){
    int u,v;
    u = FIND(a); v = FIND(b);
    if(Rank[u] > Rank[v])
        S[v] = u;
    else if(Rank[v] > Rank[u])
        S[u] = v;
    else{
        Rank[u]++;
        S[v] = u;
    }
}

void printArr(int a[], int n){
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    DisjointSet d(6);
    printArr(d.S, d.size);
    d.UNION(0,1);
    d.UNION(1,2);
    d.UNION(3,4);
    d.UNION(1,3);
    printArr(d.S, d.size);
}