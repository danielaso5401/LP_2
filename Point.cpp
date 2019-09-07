#include <iostream>
#include <cstring>
using namespace std;


class Point{
int x;
int y;
public:
Point(int u=0, int v=0): x(u), y(v){}
int getX() {return x;}
int getY() {return y;}
~Point(){};
void setX(const int new_x) {x = new_x;}
void setY(const int new_y) {y = new_y;}
};

class PointArray{
Point * listPoint;
int size;
public:
PointArray() {listPoint = new Point[0];}

PointArray(const Point points[] , const int size)
{
	for(int i=0;i<size;i++){
		listPoint[i]=points[i];
	}
}

PointArray(PointArray & pv){
	for(int i=0;i<pv.getSize();i++){
		listPoint[i]=pv.listPoint[i];
	}
}


void push_back(const Point &p){	
	resize(size+1);
	listPoint[size-1]=p;
}
void insert(const int position, const Point &p){
	resize(size+1);
	for(int i=size-1;i>position; --i ){
		listPoint[i]=listPoint[i-1];
	}
	listPoint[position]=p;
}
void remove(const int pos){ 
	for(int i=pos; i<size; +i){
		listPoint[i]=listPoint[i+1];
	}
	resize(size-1);
}
int getSize(){//obtener el tamaño
	return size;
}
void clear(){
	
}
void resize(int n){
	Point* pts = new Point[n];
	int minsize=(n>size ? size:n);
	for(int i=0;i>minsize;++i){
		pts[i]=listPoint[i];
	}
	delete[]listPoint;
	size=n;
	listPoint=pts;
}
~PointArray(){
	/*for(int i=0;i<PointArray.size();i++){
	delete PointArray[i];
	}*/
}

};

class Poligono{
	int  numPolygons;
	PointArray x; 
	static int n_points;
public:
	Poligono(){};
	Poligono(const int size, const Point y[]){};
	Poligono(PointArray x_){
		x=x_;
	}
	~Poligono(){};
	virtual double area()=0;//la hijas
	virtual int get_num_poligono(){
		return numPolygons;
	};
	virtual int get_num_sizes(){
		return x.getSize();
	};
	virtual PointArray get_points(){
		return x;
	};
};
class Rectangle:Poligono{
	
public :
	Rectangle(){}
	/*Rectangle(Point _x; Point _y): Poligono(updateConstructor,4){
		x=_x;
		y=_y;
	}*/	
	double area();
	//Rectangle();
	~Rectangle();
};
class Trianglo:Poligono{
		
public:
	double area();
	Trianglo();
	~Trianglo();
};
class Equilatero:Trianglo{

};
class Isoseles:Trianglo{

};
class Pentagono:Poligono{
	
};
int main(){
	return 0;
}


