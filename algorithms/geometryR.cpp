/** Geometry Implementations **/ 
/** The Point structure here uses rectangular coordinates **/ 
#include <iostream>
#include <cstring> 
#include <fstream>
#include <cmath> 
#include <vector> 
#include <map> 

using namespace std; 

const double EPS = 1e-7; 

struct PT {
	double x, y;  //coordinates 
	PT () {};  //empty constructor 
	PT (double x, double y) : x(x), y(y) {}	 //constructor
	PT (const PT &p) : x(p.x), y(p.y) {}

	bool operator<(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }  //for sorting
	bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); } //for unique

	PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
	PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
	PT operator * (double c) const { return PT(x*c, y*c ); } 
	PT operator / (double c) const { return PT(x/c, y/c ); }
};

double dot (PT p, PT q) { return p.x*q.x + p.y*q.y; } //dot product
double cross (PT p, PT q) { return p.x*q.y - p.y*q.x; } //cross product
/** Calculate (b-a)x(c-a) **/
double area2 (PT a, PT b, PT c) { return 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (c.x - a.x) * (b.y - a.y); }//efficient calc

ostream &operator<<(ostream &os, const PT &p) {
	os << "(" << p.x << "," << p.y << ")";
}

// Is the rotation CCW? 1 if CCW, -1 if CW, 0 if collinear 
int ccw (PT a, PT b, PT c){ //equiv to (b-a)x(c-a)
	double a2 = 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (c.x - a.x) * (b.y - a.y); 
	if (a2 > 0) return +1; 
	else if (a2 < 0) return -1; 
	else return 0; 
}

// are the lines from a to b and c to d parallel? collinear?
bool LinesParallel (PT a, PT b, PT c, PT d){
	return abs(cross(b-a,c-d)) < EPS; 
}

bool LinesCollinear (PT a, PT b, PT c, PT d){
	return LinesParallel(a, b, c, d)  
		&& fabs(area2(a,b,c)) < EPS 
		&& fabs(area2(c,d,a)) < EPS; 
}

//Andrew's Algorithm for Convex Hull
//"returns" convex hull in ccw order, starting with bottommost and leftmost point
void ConvexHull (vector<PT> &pts){
	sort(pts.begin(), pts.end()); 
	pts.erase(unique(pts.begin(), pts.end()), pts.end());    //turns pts into sorted order w/ no repeats 
	vector<PT> up, dn; 
	for (int i = 0; i < pts.size(); i++){
		while (up.size() > 1 && ccw(up[up.size()-2], up.back(), pts[i]) >= 0 ) up.pop_back(); //while concave  
		while (dn.size() > 1 && ccw(dn[dn.size()-2], dn.back(), pts[i]) <= 0 ) dn.pop_back(); 
		up.push_back(pts[i]);
		dn.push_back(pts[i]);
	}
	pts = dn; 
	for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
}

int main() {
	//Answer should be 1 0 1
	cerr << LinesParallel(PT(1,1), PT(3,5), PT(2,1), PT(4,5)) << " "
	<< LinesParallel(PT(1,1), PT(3,5), PT(2,0), PT(4,5)) << " "
	<< LinesParallel(PT(1,1), PT(3,5), PT(5,9), PT(7,13)) << endl;
	//Answer should be 0 0 1
	cerr << LinesCollinear(PT(1,1), PT(3,5), PT(2,1), PT(4,5)) << " "
	<< LinesCollinear(PT(1,1), PT(3,5), PT(2,0), PT(4,5)) << " "
	<< LinesCollinear(PT(1,1), PT(3,5), PT(5,9), PT(7,13)) << endl;
	vector<PT> v; 
	double temp1, temp2; 
	//Test data 1: 8 7 7 7 -7 -7 -7 -7 7 9 0 -9 0 0 9 0 -9
	//Test data 2: 16 7 7 7 -7 -7 -7 -7 7 9 0 -9 0 0 9 0 -9 0 0 1 2 -2 1 -1 -1 3 4 4 3 -5 4 6 5
	//Answer: (0,-9) (7,-7) (9,0) (7,7) (0,9) (-7,7) (-9,0) (-7,-7)  
	int N; 
	cin >> N; 
	for (int i = 0; i<N; i++){
		cin >> temp1 >> temp2; 
		v.push_back(PT(temp1,temp2)); 
	}
	ConvexHull(v); 
	for (int i = 0; i < v.size(); i++){
		cerr << v[i]; 
		cerr << " "; 
	}
	cerr << endl; 
}
