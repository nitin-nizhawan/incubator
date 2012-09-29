#!/usr/bin/python
import math
max_prime=999999
primes=[2,3]
def isPrime(n):
	sqrt1 = math.floor(math.sqrt(n))
	i=0;
	while primes[i]<=sqrt1:
		if n%primes[i]==0:
			return False
		i=i+1
	return True
def createPrimes():
	nextnum=5
	while nextnum<max_prime:
		if(isPrime(nextnum) == True):
			primes.append(nextnum)
		nextnum = nextnum +2

createPrimes()
totalnum=1
totalprimes=0
for i in xrange(3,112130,2):
	totalnum=totalnum+4
        n=i
	d1=n*n-2*n+2
	if isPrime(d1)==True:
		totalprimes=totalprimes+1
	d1=n*n-n+1
	if isPrime(d1)==True:
		totalprimes=totalprimes+1
	d1=n*n-3*n+3
	if isPrime(d1)==True:
		totalprimes=totalprimes+1
        print "%d , %d" % (totalnum,totalprimes)
	if 10*totalprimes <= totalnum:
		print i
		break
	
