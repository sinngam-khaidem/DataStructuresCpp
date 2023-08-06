#include<iostream>
#include<queue>

using namespace std;

class Student{
public:
	Student(string name, int marks){
		this->name = name;
		this->marks = marks;
	}
	string name;
	int marks;
};

class Cmp{
public:
	bool operator()(Student& p, Student& q){
		return p.marks < q.marks;
	}
};

int main(){
	priority_queue<Student, vector<Student>, Cmp> pq;
	Student Amelie("Amelie", 78);
	Student Jonh("John", 98);
	Student Bond("Bond", 32);
	Student Peter("Peter", 57);

	pq.push(Amelie);
	pq.push(Jonh);
	pq.push(Peter);
	pq.push(Bond);

	while(!pq.empty()){
		cout<<pq.top().marks<<endl;
		pq.pop();
	}
}