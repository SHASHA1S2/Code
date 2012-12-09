#!/usr/bin/python

# find the number of ways to reach a total with the given number of combinations
import math


denominations = [2, 1]
d = {}

def count_combs(left, i, comb, add):
    if add != None: comb.append(add)
    if left == 0 or (i+1) == len(denominations):
        if (i+1) == len(denominations) and left > 0:
            comb.append( left )
            i += 1
        while i < len(denominations):
            comb.append( 0 )
            i += 1
        tot = sum(comb)
        di = "|".join([str(left), str(i), str(comb), str(add)])
        d[di] = math.factorial(tot) * (2**(tot-1))/ (math.factorial(comb[0])* math.factorial(comb[1]))
        return d[di]
    cur = denominations[i]
    l = 0
    for x in range(0, int(left/cur)+1):
        di = "|".join([str(left-x*cur), str(i+1), str(comb[:]), str(x)])
        if di in d:
            l = l+d[di]
        else: 
            l = l + count_combs(left-x*cur, i+1, comb[:], x)
    return l%1000000007


t = int(raw_input())
for i in range(t):
    n = int(raw_input())
    print count_combs(n, 0, [], None)
