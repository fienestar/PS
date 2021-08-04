/*
    숨바꼭질
    https://www.acmicpc.net/problem/1697
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    size_t N,K;
    cin >> N >> K;

    queue<size_t> q;

    if(K < N){
        cout << N - K;
        return 0;
    }

    vector<size_t> m(200000,-1);

    q.push(N);
    m[N] = 0;
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        if(p == K){
            cout << m[p];
            return 0;
        }
assert(p < K*2);
#define up(n) \
if(n < K*2 && m[n] > m[p]+1){\
    m[n] = m[p]+1;\
    q.push(n);\
}
        up(p*2);
        up(p+1);
        up(p-1);
#undef up
    }
    
}