#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Object{
public:
	int label;
	float profit;
	float weight;
	float ratio;
	Object(int l, float p, float w){
		label = l;
		profit = p;
		weight = w;
		ratio = p/w;
	}
};

class Cmp{
public:
	bool operator()(Object p, Object q){
		return p.ratio > q.ratio; //decreasing order
	}
};

void knapsack(vector<Object> v, float M){
	Cmp ratioCmp;
	int n = v.size();
	int i;
	float total_profit, capacity, x[10];
	for(i=0; i<n; i++){
		x[i] = 0.0;
	}
	sort(v.begin(), v.end(), ratioCmp);
	
	total_profit = 0.0; capacity = M;
	for(i=0; i<n; i++){
		if(v[i].weight>capacity)
			break;
		x[i] = 1;
		total_profit += v[i].profit;
		capacity -= v[i].weight;
	}

	if(i<n)
		x[i] = (float)capacity/v[i].weight;
	total_profit += v[i].profit*x[i];

	cout<<"Profit by weight ratio of each objects are: "<<endl;
	for(i=0; i<n; i++){
		cout<<"Object " << v[i].label <<" - "<<v[i].ratio<<endl;
	}

	cout<<"The objects considered are: "<<endl;
	for(i=0; i<n; i++){
		if(x[i] != 0.0){
			cout<<"Object "<< v[i].label<<endl;
		}
	}

	cout<<"Total maximum profit: "<<endl;
	cout<<total_profit<<endl;
}

int main(){
	vector<Object> vec = {Object(1, 5,1), Object(2, 10,3), Object(3, 15,5), Object(4, 7,4), Object(5, 8,1), Object(6, 9,3), Object(7, 4,2)};
	float knapsackCapacity = 15;	
	knapsack(vec, knapsackCapacity);
}