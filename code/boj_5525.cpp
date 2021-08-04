/*
    IOIOI
    https://www.acmicpc.net/problem/5525
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    size_t N,M;
    char in[2'000'000] = {};
    size_t cnt=0;
    size_t cni=0;
    cin >> N >> M >> in;
    size_t last_ioi = 0;
    
    for(size_t i=0;i<M+2;++i){
        if(in[i] == 'I'){
            if(~cni&1)++cni;
            else{
                if(cni+1 >= N*2)
                    cnt+=(cni-1)/2-N+1;
                cni=1;
            }
        }else{
            if(cni&1)++cni;
            else{
                if(cni+1 >= N*2)
                    cnt+=(cni-1)/2-N+1;
                cni=0;
            }
        }
    }
    cout << cnt;
}