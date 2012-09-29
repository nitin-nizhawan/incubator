#!/usr/bin/python
#using vector cross product and dot products
# A,B,C are vectors to a,b,c vertices and P is vector for point p
# then cross(P-A,B-A) denoted which side of edge ab point p lies, for it to be inside triangle it should on same side as c
# therefore to find out if they are on same side we take dot product of cross products dot(cross(P-A,B-A),cross(C-A,B-A)) 
# we repeat it for all three edges ie. if c=cross , d=dot then d(c(P-A,B-A),c(C-A,B-A))>0 && d(c(P-B,C-B),c(A-B,C-B))&&d(c(P-C,A-C),c(B-C,A-C)) tell if point is inside

# another way is  to find the vectors connecting the point to each of the triangles three vertices and sum the angles between those vectors. If the sum of the angles is 2*pi then the point is inside the triangle, otherwise it is not

def cross(a,b):
	x=a[1]*b[2]-a[2]*b[1]
	y=a[2]*b[0]-a[0]*b[2]
	z=a[0]*b[1]-a[1]*b[0]
	retVal = [x,y,z]
	return retVal
# dot product to be used for sign detection, therefore not dividing by mod
def dot(a,b):
	return a[0]*b[0]+a[1]*b[1]+a[2]*b[2]
P=[0,0,0]
def sub(x,y):
	return [x[0]-y[0],x[1]-y[1],x[2]-y[2]]

def isOriginInside(A,B,C):
	AB=sub(B,A)
	BC=sub(C,B)
	CA=sub(A,C)
	d1=dot(cross(sub(P,A),AB),cross(sub(C,A),AB))
	d2=dot(cross(sub(P,B),BC),cross(sub(A,B),BC))
	d3=dot(cross(sub(P,C),CA),cross(sub(B,C),CA))
	if d1 > 0 and d2 > 0 and d3 > 0:
		return True
	return False
fd = open( "triangles.txt" )
content = fd.readline()
count=0
while (content != "" ):
	content.replace( "\n", "" )   
	# process content
	coords=content.split(',')
	for i in range(len(coords)):
		coords[i]=int(coords[i])
	print coords
	if isOriginInside([coords[0],coords[1],0],[coords[2],coords[3],0],[coords[4],coords[5],0]) == True:
		count = count+1
	content = fd.readline()
print count
