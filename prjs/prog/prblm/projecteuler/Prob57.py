#!/usr/bin/python
import math
def gcd(m,n):
	
	while(n>0):
		tmp = m%n
		m=n
		n=tmp
	
	return m;

def d(n):
	size=0
	while(n>0):
		n=int(n/10)
		size=size+1
	
	return size


p=3
q=2
count=1;
result=0;
while(count<1001):
    tp = p+q+q
    tq = p+q
    p = tp
    q = tq
    tp = gcd(p,q);
    p = p/tp;
    q= q/tp;
    if(d(p)>d(q)):
	    result=result+1;
	     
    count=count+1;
print result


