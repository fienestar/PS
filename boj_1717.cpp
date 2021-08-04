/*
    집합의 표현
    https://www.acmicpc.net/problem/1717
*/
// 사용된 알고리즘: 
// R: X
// T: 0

#include <bits/stdc++.h>

using namespace std;

#ifndef LOCAL
#define LOCAL(x) ((void)0)
#endif
#define endl "\n"
#define elif else if
#define ifn(v) if(v);else
#define elifn(v) else ifn(v)

vector<size_t> uf;

size_t root(size_t X)
{
    if(uf[X]==0)
        return X;
    return uf[X]=root(uf[X]);
}

void merge(size_t A,size_t B)
{
    if(root(A)!=root(B))
        uf[root(A)]=root(B);
}

int main()
{
    //LOCAL(OUTPUT_TO_FILE);
    LOCAL(INPUT_FROM_FILE);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Code here!
    size_t N,M,a,b,o;
    cin>>N>>M;
    uf.resize(N+2); // 1 ~ N+1

    while(M--){
        cin>>o>>a>>b;
        if(o==0)
            merge(a+1,b+1);
        else
            cout<<("NO\n\0YES\n"+4*(root(a+1)==root(b+1)));
    }
}