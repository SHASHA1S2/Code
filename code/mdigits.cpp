#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

vector<int> fun(int N)
{
	vector<int> arr(10);
	long long p;
	p=N;
	long long count=0

	if(N==0) {	arr[0]=1;return arr;}
	if(N==1) {	arr[0]=1;arr[1]=1;return arr;}
	while(p>=10)
	{
		p=p/10;count++;
	}
	vector<int > b (10);
	vector<int > c (10);
	b=fun(0,pow(10,count)-1); 
	c=fun(N-pow(10,count);
	for(int i=0;i<10;i++)
		b[i]=b[i]*p + c[i];
	return b;

}

int main()
{




}
1345
(0-9) 134 (0-5) 1 (0-9) (1345/100)*10 0 10 1 10 2 10 3 10 4 6  
