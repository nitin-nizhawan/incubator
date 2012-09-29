#!/usr/bin/python
def numdigits(n):
	count=0
	while n>0:
		count=count+1
		n/=10
	return count
total=0
for i in range(1,10):
	pow=1
	num=i**pow
	numdig = numdigits(num)
	while numdig==pow:
                print "%d , %d , %d" % (num,i,pow)
		total=total+1
		pow=pow+1
                num=i**pow
		numdig=numdigits(num)
print total
