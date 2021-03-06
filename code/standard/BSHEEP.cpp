#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include <cmath>
#include <cstring>

using namespace std;

// this is the complete convexHull code which uses two up and down hulls .
// Finally merge the two to get the desired result.

typedef struct point {
	int x , y , index;
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
	
	// to maintain in the anticlockwise order 
	for (int i = 0; i < down.size (); i++) 
		a.push_back (down[i]);
	
	reverse (up.begin() , up.end() );
	for (int i = 1; i + 1 < up.size(); i++) 
		a.push_back (up[i]);
	
	for (int i = 0; i < a.size(); i++)
		cout << a[i].x << " " << a[i].y << " " << a[i].index << endl;
	cout << "fianlly done" << endl;
	/*
	for (int i = 0; i < up.size(); i++) {
		a.push_back(up[i]);
	}
	for (int i = down.size() - 2; i >= 1; i--) {
		a.push_back(down[i]);
	}
	*/
}

double distancing (point a, point b) {
	return sqrt ( (b.x-a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

int visx[20005];
int visy[20005];

int main() {
	int T;
	scanf ("%d" , &T);
	
	while (T--) {
		memset (visx , 0 ,sizeof (visx) );
		memset (visy , 0 , sizeof (visy) );
		vector <point> a;
		int n;
		scanf ("%d" , &n);

		for (int i = 0; i < n; i++) {
			int x , y;
			scanf ("%d %d" , &x , &y);
			point p;
			p.x = x;
			p.y = y;
			p.index = i + 1;
			
			if (visx[x + 10000] == 0 && visy[y + 10000] == 0) {
				a.push_back (p);
				visx[x + 10000] = 1;
				visy[y + 10000] = 1;
			}
		}
		
		sort (a.begin() , a.end() , cmp);
		convexHull(a);
		cout << "Hull points" << endl;		
		for (int i = 0; i < a.size() ;i++) {
			cout << a[i].x << " " <<a[i].y << endl;
		
		cout << "doing" << endl;
		// perimeter;
		}
		double perimeter = 0;
		for (int i = 0; i < a.size() ; i++) {
			perimeter += distancing (a[i] , a [(i + 1) % a.size()]);
		}
		
		printf("%.2lf\n" , perimeter);
		
		for (int i = 0; i < a.size() ; i++)
			printf("%d ", a[i].index);
		printf("\n");
	}
	
	
	return 0;
}
