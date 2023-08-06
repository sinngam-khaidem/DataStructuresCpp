#include<iostream>
#include<queue>

using namespace std;

class Point2D{
private:
	float x;
	float y;
public:
	Point2D(float u, float v){
		x = u;
		y = v;
	}
	float getX(){
		return x;
	}
	float getY(){
		return y;
	}
};

//Comparator class
class LeftRight{
public:
	bool operator()(Point2D& p, Point2D& q){
		return p.getX() < q.getX();
	}
};

int main(){
	priority_queue<Point2D, vector<Point2D>, LeftRight> pq; // maxheap based on the key value x-coordinate

	pq.push(Point2D(7,99));
	pq.push(Point2D(2, 86));
	pq.push(Point2D(4,56.3));
	pq.push(Point2D(3, 63.2));
	pq.push(Point2D(9.8, 9.5));

	while(!pq.empty()){
		Point2D point = pq.top();
		cout<<point.getX()<<" ";
		pq.pop();
	}
}