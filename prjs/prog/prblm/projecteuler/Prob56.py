#!/usr/bin/python
def digitsum (n):
	sum=0
	while n>0:
		sum+=n%10
		n/=10
	return sum
dsum=0;
for i in range(1,100):
   for j in range(1,100):
      val = i**j
      dg = digitsum(val)
      print dg
      if dg > dsum:
          dsum=dg
print dsum
 

