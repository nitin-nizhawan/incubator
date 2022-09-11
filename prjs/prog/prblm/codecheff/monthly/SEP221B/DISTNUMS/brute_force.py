
MOD = 1000000007
def gen_sol(n,depth,sol,K):
    if(depth > K):
        return
    for x in range(1,n+1):
        if(n%x ==0):
            sol[str(x*n)]=x*n
            gen_sol(x*n,depth+1,sol,K)

def solve(N,K):
    sol={}
    gen_sol(N,1,sol,K)
    ans=sum_sol(sol)
    ans = ans % MOD
    print(str(ans))


#print(sol)
def sum_sol(sol):
  sumq = 0;
  for key in sol:
    sumq = sumq + sol[key]
  return sumq


inp=[
[1,5],
[2,2],
[10,1],
[6,1],
[6,2],
[6,4],
[77,3],
[143,3],
[30,2],       
[30,3],       
[300,1],
[300,2],
]
inp2=[
       [ 300,1],
[25,1],
[4,1],
[3,1],
       [300,2]
       ]

for i in range(0,len(inp)):
  N = inp[i][0]
  K = inp[i][1]
  print("N=%d,K=%d"%(N,K))
  solve(N,K)

