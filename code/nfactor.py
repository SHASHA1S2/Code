primes = [1]*10005

	
def compute():
	for i in range(2,10005):
		if(primes[i]):
			j=2*i
			while(j<10005):
				primes[j]=0
				j=j+i
		
def solve(N):
	ans=1
	for j in range(2,N+1):
		if(primes[j]):
			t=N
			cnt=0
			while t:
				t/=j
				cnt+=t
			ans*=(2*cnt + 1)
	return ans

compute()
n=input()
while(n):
	print solve(n)
	n=input()

			


	
