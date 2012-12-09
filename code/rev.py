def rev(x):
	p=0
	while(x):
		p=p*10+x%10
		x=x/10
	return p

t=0
for i in range(100,1000):
	for j in range (100,1000):
		if(rev(i*j)==i*j)  :
			if(i*j>t):
				t=i*j
	
print t
