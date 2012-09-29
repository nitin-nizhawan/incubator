#!/usr/bin/python
factvals = (1,1,2,6,24,120,720,5040,40320,362880)
def factdigitsum(n):
	sum=0
	while n>0:
		sum+=factvals[n%10]
		n/=10
	return sum
factsum=0
for i in range(9,999999):
        factdigitsumi=factdigitsum(i)
	if i==factdigitsumi:
		factsum+=i
print factsum

