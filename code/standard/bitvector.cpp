#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

typedef struct point{
  long long x;
  long long y;
} point;

long long K;
point arr[15];
long long hcf(long long a,long long b)
{
  long long t;
  if(a<b)  { t=a;a=b;b=t;}
  if(b==0) return a;  
  hcf(b,a%b);
}

long long lcm2(long long a ,long long b)
{
  return (a*b)/hcf(a,b); 
}

long long lcm()
{
  long long c=1,i;
  for(i=0;i<K;i++)
    {if(arr[i].y==1)
      {c=lcm2(arr[i].x,c);}}
  return c;
}
int main()
{
  long long n;
  cin>>n>>K;
  for(long long i=0;i<K;i++)
    cin>>arr[i].x;
  long long ans=0;
  for(long long i=0;i<pow(2,K);i++)
    {
      long long count=0,i1=0;
      long long p=i,j;
      for(j=0;j<K;j++)
	arr[j].y=0;
      while(p)
	{
 	  if(p%2) {arr[i1].y=1;count++;}
	  p=p/2;i1++;
	}
      p=lcm();
      if(count%2) ans-=n/p;
      else ans+=n/p;
    }
  cout<<ans<<endl;
  return 0;
}


