#!/usr/bin/python
primes=[2,3,5]
def isPrime(n):
	if(n<2):
		return False
	sqrt1=n**(0.5)
	count=0
        while(primes[count]<=sqrt1):
		if (n%primes[count]==0):
			return False
		count=count+1
	return True
def createPrimes():
	testnum=3
	while(testnum<1000000):
		if(isPrime(testnum)):
			primes.append(testnum)
		testnum=testnum+2
def checkNum(n):
	div=100000000
	while(n>0):
                #print n
		if(isPrime(n)==False):
			return False
		n=n%div
		div=div//10
	return True
createPrimes()
nums = [[2,3,5,7]]
digits=8
i=0
while(digits>1):
	tmpar=[]
	numslst = nums[i]
        for j in range(0,len(numslst)):
		oddn=1
		while(oddn<10):
			newnum=numslst[j]*10+oddn
			if(isPrime(newnum)):
				tmpar.append(newnum)
			oddn=oddn+2
	nums.append(tmpar)
	i=i+1
	digits=digits-1	
digits=1
ans=[]
while(digits<8):
	numlst=nums[digits]
	print numlst
	for j in range(0,len(numlst)):
		print numlst[j]
		if(checkNum(numlst[j])):
			ans.append(numlst[j])
	digits=digits+1	
print "--------------------"
print reduce(lambda x,y: x+y,ans)
