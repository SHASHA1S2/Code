#include<cstdio>
#include<iostream>
using namespace std;

long long check(long long r,long long x,long long y1,long long y2)
{
	long long ans=1;
	if(r>=(x+y1)*(x+y1) && (r>=(x+y2)*(x+y2))) return 1; 
	if(r<=(x-y2)*(x-y2) && r<=(x-y1)*(x-y1) && x<y1 && x<y2) return 1;	
	if(r<=(x-y2)*(x-y2) && r<=(x-y1)*(x-y1) && x>y1 && x>y2) return 1;	
	return 0;
}
int main()
{
	long long x1,y1,r1,s1,x2,y2,r2,s2;
	cin>>x1>>y1>>r1>>s1>>x2>>y2>>r2>>s2;
	long long ans=0;
	long long dis=(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);

	ans+= check(dis,r1,r2,s2) + check(dis,s1,r2,s2) + check(dis,r2,r1,s1) + check(dis,s2,r1,s1);
	cout<<ans<<endl;

	return 0;	
}
