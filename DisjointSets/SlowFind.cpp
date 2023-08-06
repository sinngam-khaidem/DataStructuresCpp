#include<iostream>
#define MAX 20

using namespace std;

class DisjointSet{
public:
    int S[MAX];
    int size;
    DisjointSet(int size); //MAKESET(int S[], int size)
    int FIND(int X);
    void UNION(int root1, int root2);
};

DisjointSet::DisjointSet(int size){
    this->size = size;
    int i;
    for(i=0; i<size; i++)
        S[i] = i;
}

int DisjointSet::FIND(int X){
    if(!(X>=0 && X<size))
        return -1;
    if(S[X] == X)
        return X;
    else
        return FIND(S[X]);
}

void DisjointSet::UNION(int root1, int root2){
    if(FIND(root1) == FIND(root2))
        return;
    if(!(root1 >=0 && root1<size) || !(root2 >=0 && root2<size))
        return;
    S[root1] = root2;
}

void printArr(int a[], int n){
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    DisjointSet d(5);
    printArr(d.S, d.size);
    d.UNION(2,4);
    printArr(d.S, d.size);
}