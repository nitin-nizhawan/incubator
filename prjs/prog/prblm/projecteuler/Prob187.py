#!/usr/bin/python
import math
max_prime=50000000
primes=[2,3,5]

def isPrime(n):
	sqrt1 = math.floor(math.sqrt(n))
	i=2;
	while primes[i]<=sqrt1:
		if n%primes[i]==0:
			return False
		i=i+1
	return True
def createPrimes():
	primecount=3
	nextnum=7
        skip3=1
	while nextnum<max_prime:
		if(isPrime(nextnum) == True):
			primes.append(nextnum)
			primecount=primecount+1
		nextnum = nextnum + 2*skip3
		skip3=1-skip3
	return primecount

pcount=createPrimes()
print pcount
	
