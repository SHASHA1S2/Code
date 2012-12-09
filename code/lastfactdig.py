import sys
try:
	N=input()
except EOFError:
	N=-1
arr=[1]*102
dig=1
for i in range(2,100):
	n=i
	while(n%10==0):
		n=n/10
	n=n%10
	if((dig*n)%10==0): dig=(dig*n)/10
	else: dig=(dig*n)%10
	arr[i]=dig
while (N!=-1):
	
	N=N%100
	print arr[N]
	try:
		N=input()
		
	except EOFError:
		N=-1
		
