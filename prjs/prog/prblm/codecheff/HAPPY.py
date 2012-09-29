#!/usr/bin/python
graph1 = [[0 for col in range(30)] for row in range(30)]
dim1=0
gnodes = [0 for col in range(30)]
nused=0
he=0

def determinant(mat):
    size = len(mat)
    if( size == 1):
        return mat[0][0]
    if( size == 2):
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]
    size0len = len(mat[0])
    result=0
    for i in range(size0len):
        temp = [[0 for col in range(size0len)] for row in range(size)]
        for j in range(1,size):
            for k in range (size0len):
                if(j<k):
                    temp[j-1][k]=mat[j][k]
                if(k>j):
                    temp[j-1][k-1]=mat[j][k]
        result = result + mat[0][i]*(-1**i)*determinant(temp);
    return result

def resetProb():
    global graph1  
    global dim1
    global gnodes 
    global nused
    global he
    dim1=0
    graph1 = [[0 for col in range(30)] for row in range(30)]
    gnodes = [0 for col in range(30)]
    nused=0
    he=0

def inputProb():
    global dim1
    global graph1
    global gnodes
    global nused
    global he
    dim1 = input()
    for i in range(dim1):
        row1 = input();
        for j in range(dim1):
            graph1[i][dim1-j-1]=row1%10
            row1=row1/10
    he = input()
    for k in range(he):
        row2 = raw_input()
        row3 = row2.split()
        strt = int(row3[0])
        end = int(row3[1])
        graph1[strt-1][end-1]=2
        graph1[end-1][strt-1]=2
        if (gnodes[strt-1]==0):
            gnodes[strt-1]=1
            nused=nused+1
        if (gnodes[end-1]==0):
            gnodes[end-1]=1
            nused=nused+1
    

def solve1():
    global dim1
    global graph1
    global gnodes
    global nused
    global he
    return 1
def solve2():
    global dim1
    global graph1
    global gnodes
    global nused
    global he
    return 2
def solve3():
    global dim1
    global graph1
    global gnodes
    global nused
    global he
    return 3
def solve4():
    global dim1
    global graph1
    global gnodes
    global nused
    global he
    return 4
def solve5():
    global dim1
    global graph1
    global gnodes
    global nused
    global he
    return 5
def solve6():
    global dim1
    global graph1
    global gnodes
    global nused
    global he
    return 6


def solveProb():
    global dim1
    global graph1
    global gnodes
    global nused
    global he
    
    if (he < nused):
        if (he==1): 
            return solve1()
        if (he==2):
            return solve2()
        if(he==3):
            return solve3()
        if(he==4):
            return solve4()
        if(he==5):
            return solve5()
        if(he==6):
            return solve6()
    return 0

############### Main Prog
testcases = input()
while (testcases>0):
    inputProb()
    ans = solveProb()
    print ans
    resetProb()
    testcases=testcases-1
