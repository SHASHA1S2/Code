#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

#define INF 100000000

using namespace std;
typedef struct point
{
	int x;
	int y;
}point;

point t;
point A[100009];

bool compare(point a,point b)
{
	
	if(a.x-t.x > 0 && b.x-t.x > 0)
		return (a.y-t.y)*(b.x-t.x) < (b.y-t.y)*(a.x-t.x);
	if(a.x-t.x > 0 && b.x - t.x < 0)
		return false;
	if(a.x-t.x < 0 && b.x - t.x > 0)
		return true;
	if(a.x-t.x < 0 && b.x-t.x < 0)
		return (a.y-t.y)*(b.x-t.x) > (b.y-t.y)*(a.x-t.x);
}

int cw(point a,point b,point c)
{
	int x1=b.x-a.x;
	int y1=b.y-a.y;
	int x2=c.x-b.x;
	int y2=c.y-b.y;
	return x1*y2-x2*y1<0;
}

int ccw(point a,point b,point c)
{
	int x1=b.x-a.x;
	int y1=b.y-a.y;
	int x2=c.x-b.x;
	int y2=c.y-b.y;
	return x1*y2-x2*y1>=0;
}

int main()
{
	int T,N;
	scanf("%d",&T);
	while(T--)
	{
		int i,index,min=INF;
		scanf("%d",&N);
		for(i=0;i<N;i++)
		{
			scanf("%d%d",&A[i].x,&A[i].y);	
			if(A[i].y<=min)
			{
				if((A[i].y==min && A[i].x<A[index].x) || A[i].y<min)
				{
					index=i;
					min=A[i].y;
				}
			}
		}
		printf("%d %d\n",A[index].x,A[index].y);
		t=A[index];
		sort(A,A+N,compare);		
		for (int i=0;i<N;i++)
			printf("%d %d\n",A[i].x,A[i].y);
		printf("end\n");
		vector<point> Hull;
		Hull.push_back(A[0]);
		Hull.push_back(A[1]);
		for(i=2;i<N;i++)
		{
			int sz=Hull.size();
			if (cw(Hull[sz-1],Hull[sz-2],A[i]))
				Hull.push_back(A[i]);
			else 
			{
				while (Hull.size()>=2&&ccw(Hull[Hull.size()-1],Hull[Hull.size()-2],A[i]))
					Hull.pop_back();
				Hull.push_back(A[i]);
			}
		}
		for(i=0;i<Hull.size();i++)
		{
			printf("%d %d\n",Hull[i].x,Hull[i].y);
		}
	}

	return 0;
}
