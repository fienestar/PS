/*
    교수님은 기다리지 않는다
    https://www.acmicpc.net/problem/3830
*/
// 사용된 알고리즘: union-find
// R: X
// T: 0

#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using pll=pair<size_t,ll>;

vector<pll> uf;
// uf[b] = {a,w}
// b = a + w

pll root(size_t idx,ll w=0)
{
    if(uf[idx].first==idx)
        return {idx,w};

    uf[idx]=root(uf[idx].first,uf[idx].second);
    
    return {uf[idx].first,uf[idx].second+w};
}

// A = root(a)
// B = root(b)
// a = A + AK
// 

void merge(size_t a,size_t b,ll w)
{
    pll root_a = root(a);
    pll root_b = root(b);

    if(root_a.first!=root_b.first)
        uf[root_b.first]={root_a.first,root_a.second - root_b.second + w};
}

pll get_diff(size_t a,size_t b)
{
    pll root_a = root(a);
    pll root_b = root(b);
    return {
            root_a.first==root_b.first, root_b.second-root_a.second
        };
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Code here!
    size_t N,M;
    
    while(cin >> N >> M){

        uf.resize(N+1);
        for(size_t i=N;i--;)
            uf[i+1]={i+1,0};
        
        while(M--){
            char m;
            size_t a,b;
            ll w;
            cin >> m >> a >> b;
            if(m=='!'){
                cin>>w;
                merge(a,b,w);
            }else{
                pll rslt = get_diff(a,b);
                if(rslt.first)
                    cout << rslt.second << "\n";
                else
                    cout << "UNKNOWN\n";
            }
        }
    }
}