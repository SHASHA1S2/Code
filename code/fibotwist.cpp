#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
ll  MOD;

ll fibonacci[55][2][2];

void init()
{
//   fibonacci[1][2][2] = {{1,1},{1,0}};
  fibonacci[1][0][0]=1;
  fibonacci[1][0][1]=1;
  fibonacci[1][1][0]=1;
  fibonacci[1][1][1]=0;
  for(int i=2;i<55;i++)
  {
    fibonacci[i][0][0] = (fibonacci[i-1][0][0]%MOD*fibonacci[i-1][0][0]%MOD + fibonacci[i-1][0][1]%MOD*fibonacci[i-1][1][0]%MOD)%MOD;
    fibonacci[i][0][1] = (fibonacci[i-1][0][0]%MOD*fibonacci[i-1][0][1]%MOD + fibonacci[i-1][0][1]%MOD*fibonacci[i-1][1][1]%MOD)%MOD;
    fibonacci[i][1][0] = (fibonacci[i-1][0][0]%MOD*fibonacci[i-1][1][0]%MOD + fibonacci[i-1][1][0]%MOD*fibonacci[i-1][1][1]%MOD)%MOD;
    fibonacci[i][1][1] = (fibonacci[i-1][0][1]%MOD*fibonacci[i-1][1][0]%MOD + fibonacci[i-1][1][1]%MOD*fibonacci[i-1][1][1]%MOD)%MOD;
  }
}


ll Fibo(ll n)
{
  ll counter=1;
  ll ret[2][2]={{1,0},{0,1}};
  ll tmp[2][2];
  while(n)
  {
    if(n&1)
    {
      //Multiply return array with fibonacci[counter]
      tmp[0][0]=((ret[0][0]*fibonacci[counter][0][0])%MOD+(ret[0][1]*fibonacci[counter][1][0])%MOD)%MOD;
      tmp[0][1]=((ret[0][0]*fibonacci[counter][0][1])%MOD+(ret[0][1]*fibonacci[counter][1][1])%MOD)%MOD;
      tmp[1][0]=((ret[1][0]*fibonacci[counter][0][0])%MOD+(ret[1][1]*fibonacci[counter][1][0])%MOD)%MOD;
      tmp[1][1]=((ret[1][0]*fibonacci[counter][0][1])%MOD+(ret[1][1]*fibonacci[counter][1][1])%MOD)%MOD;
      ret[0][0]=tmp[0][0];
      ret[0][1]=tmp[0][1];
      ret[1][0]=tmp[1][0];
      ret[1][1]=tmp[1][1];
    }
    n/=2;
    counter++;
  }
  return ret[0][1]%MOD;
}

int main()
{
	
		int T;
		scanf("%d",&T);
		while(T--)
		{
			ll n;ll m;
			scanf("%lld%lld", &n,&MOD);
			init();
			ll ans = (2* Fibo(n+2) - n -2) % MOD; 
			if(ans<0)
				ans+=MOD;
			printf("%lld\n",ans);
		}
		return 0;
}



