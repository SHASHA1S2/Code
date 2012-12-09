t=input()
while t:
	s=raw_input()
	a,b=(int(x) for x in s.split())
	if a==0:
		print 0
	elif b==0:
		print 1
	elif a%10==0:
		print 0
	else:
		b=b%4;
		a=a%10;
		print (a**b) % 10
	t=t-1
