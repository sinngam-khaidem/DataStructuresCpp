#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Job{
public:
	char label;
	int profit;
	int dead;
	Job(char lab, int d, int p){
		label = lab;
		profit = p;
		dead = d;
	}
};

class ProfitCompare{
public:
	bool operator()(Job p, Job q){
		return p.profit > q.profit;
	}
};

void JobScheduling(vector<Job> J){
	int i, k, r, q, n;
	float tp = 0;
	n = J.size();
	J.insert(J.begin(), Job('$', 0, 0));

	k = 1;
	for(i=2; i<=n; i++){
		r = k;
		Job newJob = J[i];
		while((J[r].dead > J[i].dead)&&(J[r].dead != r))
			r = r-1;
		if((J[r].dead <= J[i].dead) && J[i].dead > r){
			for(q = k; q>=r+1; q--)
				J[q+1] = J[q];
			J[r+1] =  newJob; k = k+1;
		}
	}

	//Printing the jobs
	cout<<"The jobs selected are in the order: "<<endl;
	for(i=1; i<=k; i++){
		tp += J[i].profit;
		cout<<J[i].label<<" ";
	}
	cout<<endl;
	cout<<"Total profit: "<<tp<<endl;
}

int main(){
	//vector<Job> j{Job('A', 2, 100), Job('B', 1, 15), Job('C', 2,10), Job('D', 1, 27)}; //D A 127
	vector<Job> j{Job('A',2,20), Job('B', 2,15), Job('C', 1,10), Job('D',3,5), Job('E', 3,1)}; // A B D 40
	ProfitCompare cmp;
	sort(j.begin(), j.end(), cmp);

	JobScheduling(j);
}
