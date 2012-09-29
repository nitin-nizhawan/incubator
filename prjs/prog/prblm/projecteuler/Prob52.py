#!/usr/bin/python
digitflag2=[0,0,0,0,0,0,0,0,0,0]
digitflagx=[0,0,0,0,0,0,0,0,0,0]
def clearFlag(dflag):
	for i in range(0,10):
		dflag[i]=0

def setflag(dflag,n):
        clearFlag(dflag);
	while n>0:
		dflag[n%10]=1
		n/=10
def intlength(a):
	return len(str(a))
def flagsequal():
	for i in range(0,10):
		if digitflag2[i]!=digitflagx[i]:
			return False
	return True
def vectormatch(a,b):
	setflag(digitflag2,a)
	setflag(digitflagx,b)
	return flagsequal()
def samedigits(a,b):
#	if(intlength(a) != intlength(b)):
#		return False
	if(vectormatch(a,b) == False):
		return False
	return True
def isC(i):
        i2i = 2*i
	return samedigits(i2i,3*i) and samedigits(i2i,4*i) and samedigits(i2i,5*i) and samedigits(i2i,6*i)


for i in range(1,1112000):
	if isC(i):
		print "%d" % (i)
