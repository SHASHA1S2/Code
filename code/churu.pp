#include<iostream>
#include<cstdio>
#include<bitset>
#include<algorithm>

using namespace std;

int a[17];

const int N = 10000000;

bitset<N + 5> v;

void sieve()
{
	v.set();
	for (int i = 4; i <= N; i+= 2)
		v[i] = false;
	v[0] = v[1] = false;
	v[2] = true;
	
	for (int i = 3; i * i <= N; i += 2)
	{
		if(v[i])
		{
			for (int j = i * i ; j <= N;  j += (i + i))
				v[j] = false;
		}
	}
}

int main()
{
	sieve();
	
	int T;
	scanf("%d",&T);
	
	while (T--)
	{
		int n;
		scanf("%d",&n);
		
		int k = 0;
		int sz = 0;
		int ans = 0;
		
		if (n % 3 == 0) 
		{
			printf("0\n");
			continue;
		}
		
		while (n)
		{
			a[k++] = n % 10;
			n /= 10;
		}
		sz = k;
		
		sort (a , a + sz);
		
		do 
		{
			if (a[0] == 0)
				continue;
			if (sz > 1 && !(a[sz-1] & 1))
				continue;
			
			int temp = 0;
			
			for (int i = 0; i < sz; i++)
			{
				temp *= 10;
				temp += a[i];
			}
			if (v[temp])
				ans++;
		}
		while (next_permutation(a , a + sz));
	
		printf("%d\n",ans);
	}
	
	return 0;
}


