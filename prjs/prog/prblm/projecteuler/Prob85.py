#!/usr/bin/python
# number of rectangles in a nxm rectangle or (n+1)x(m+1) grid of dots is C(n+1,2),C(m+1,2)
#Another way to get this is SUM(i=1,n) SUM(j=1,m) i*j, which can be written in python as
#### ------- code ---------####
#sum=0
#for i in range (1,n+1):
#	for j in range (1,m+1):
#		sum+=i*j
####-----------------------#####
# number of squares in a nxn square is n(n+1)(2*n+1)/6 ie. 1^2 + 2^2 + 3^2 + 4^2 .... n^2

import math

#closest_i
c_i=0;
#closest_j
c_j=0;
#closest_rects to 2 million
c_rect_diff=2000000;
for i in range(2,2000):
	for j in range(1,i+1):
		num_rects=(i*(i+1)*j*(j+1))/4
		num_diff= math.fabs(num_rects-2000000)
		if(num_diff<c_rect_diff):
			c_i=i
			c_j=j
			c_rect_diff=num_diff
			print "%d : %d : %d : area=%d" % (num_rects,c_i,c_j,c_i*c_j)
