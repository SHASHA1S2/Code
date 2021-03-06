#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// this is the complete convexHull code which uses two up and down hulls .
// Finally merge the two to get the desired result.

typedef struct point {
	int x , y;
} point;

bool cmp (point a  , point b) {
	return a.x ==  b.x  ? a.y < b.y : a.x < b.x;
}

int ccw (point a,point b , point c) {
	int x1 = b.x - a.x;
	int y1 = b.y - a.y;
	int x2 = c.x - b.x;
	int y2 = c.y - b.y;
	
	return x1 * y2 - x2 * y1 > 0;
}

int cw (point a,point b , point c) {
	int x1 = b.x - a.x;
	int y1 = b.y - a.y;
	int x2 = c.x - b.x;
	int y2 = c.y - b.y;
	
	return x1 * y2 - x2 * y1 < 0;
}


void convexHull (vector <point> &a) {
	int n = a.size();
	if (n <= 2) 
		return ;
	vector <point> up , down;
	point p1 = a[0] , p2 = a[n - 1];
	// p1 and p2
	cout << p1.x << " " << p1.y << endl;
	cout << p2.x << " " << p2.y  << endl;
	up.push_back(p1);
	down.push_back(p1);
	
	for (int i = 1; i < a.size(); i++) {
		if (i == a.size() - 1 || cw (p1 , a[i] , p2) ) {
			while (up.size () >= 2 && ccw(up[up.size() - 2] , up[up.size() - 1] , a[i]) ) {
				up.pop_back();
			}
			up.push_back(a[i]);
		}

		if (i == a.size() - 1 || ccw (p1 , a[i] , p2) ) {
			while (down.size () >= 2 && cw(down[down.size() - 2] , down[down.size() - 1] , a[i]) ) {
				down.pop_back();
			}
			down.push_back(a[i]);
		}
	}
	
	a.clear();
	
	// up
	cout << "up" << endl;
	for (int i = 0; i < up.size(); i++)
		cout << up[i].x << " " << up[i].y << endl;
	
	// down
	cout << "down" << endl;
	for (int i = 0; i < down.size(); i++)
		cout << down[i].x << " " << down[i].y << endl;
	cout << "done" << endl;
	
	for (int i = 0; i < up.size(); i++) {
		a.push_back(up[i]);
	}
	for (int i = down.size() - 2; i >= 1; i--) {
		a.push_back(down[i]);
	}
}

int main() {
	int T;
	scanf ("%d" , &T);
	
	while (T--) {
		vector <point> a;
		int n;
		scanf ("%d" , &n);
		for (int i = 0; i < n; i++) {
			int x , y;
			scanf ("%d %d" , &x , &y);
			point p;
			p.x = x;
			p.y = y;
			a.push_back (p);
		}
		sort (a.begin() , a.end() , cmp);
		convexHull(a);
		cout << endl;		
		for (int i = 0; i < a.size() ;i++) {
			cout << a[i].x << " " <<a[i].y << endl;
		}
	}
	
	
	return 0;
}
