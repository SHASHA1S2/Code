
t=input()
while t:
	s=raw_input()
	k,N=s.split()
	N=int(N)
	k=int(k)
	ans=0
	count=0
	p=1
	while(N):
		if(N%2):
			ans+=p
		N=N/2
		p*=k
	print ans
	t=t-1
