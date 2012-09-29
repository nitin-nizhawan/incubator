ull brent(ull N){
    if(N%2==0){
        return 2;
    }
    ull y,c,m;
    y = rand()%(N-1)+1; y = y*(ull(rand()%(N-1)+1));
    c = rand()%(N-1)+1; c = y*(ull(rand()%(N-1)+1));
    m = rand()%(N-1)+1; m = y*(ull(rand()%(N-1)+1));
    ull g=1,r=1,q=1;
    while(g==1){        
        x = y;
        for (ull i=0;i<r;i++){
            y = ((y*y)%N+c)%N;
        }
        k = 0;
        while (k<r && g==1){
            ys = y;
            for(ull i=0;i<min(m,r-k);i++){
                y = ((y*y)%N+c)%N;
                q = q*(abs(x-y))%N;
            }
            g = gcd(q,N);
            k = k + m;
        }
        r = r*2;
    }
    if (g==N){
        while(true){
            ys = ((ys*ys)%N+c)%N;
                g = gcd(abs(x-ys),N);
                if (g>1){
                    break;
                }
        }
    }

    return g;
}
