#!/usr/bin/python
def rmax(n):
	retVal=[2,2]
	n2=n*n
#	for i in range (1,n,2):  we should check only odd number and deliberately skip even one as for them rem is always 2, euler gives error if even numbers are not included, do not why it is so, i have sent a mail to one of the members for this
	for i in range (1,n):
		newRem=(2*i*n)%n2
		if retVal[0]<newRem:
			retVal=[newRem,i]
	return retVal
rmaxsum=0;
for i in range(3,1001):
	rmaxval=rmax(i)
	print "a=%d ,rmax=%d , n=%d" % (i,rmaxval[0],rmaxval[1])
	rmaxsum+=rmaxval[0]
	if rmaxval[1]%2==0:
		print "-----------------------------------"
print rmaxsum
