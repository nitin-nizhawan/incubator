T =int(input())
while T>0:
    N = int(input())
    ans=0
    mp={}
    insec={}
    for i in range(0,N-1):
        str = input().split()
        ans=ans + int(str[2][0:len(str[2])-1])
        mp[str[0]]={'n':str[1],'c':str[2]}
        insec[str[1]]=True
    first=""
    for x in mp:
       if (x not in insec):
           first=x
           break
    next = first
    while next in mp:
        print (next,mp[next]['n'],mp[next]['c'])
        next = mp[next]['n']
    print("%d$\n"%ans)
    T = T-1