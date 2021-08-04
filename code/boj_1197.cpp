/*
    최소 스패닝 트리
    https://www.acmicpc.net/problem/1197
*/
#include <bits/stdc++.h>

// 폰코딩

using namespace std;

using e_t = tuple<size_t,size_t,int>;
vector<e_t> E;
vector<size_t> uf;

void GetInput()
{
    size_t n,m;
    size_t a,b,c;
    cin >> n >> m;
    uf.resize(n+1);
    while(m--){
        cin >> a >> b >> c;
        E.emplace_back(a,b,c);
    }
}

size_t GetRoot(size_t n)
{
    list<size_t> common_set;
    while(uf[n] != 0){
        common_set.push_back(n);
        n = uf[n];
    }
    for(auto i:common_set)
        uf[i] = n;
    return n;
}

int Solve()
{
    int sum = 0;
    sort(E.begin(),E.end(),
        [](e_t a,e_t b){
        return get<2>(a) < get<2>(b);
    });
    for(e_t& e:E){
        auto[a,b,c] = e;
        a = GetRoot(a);
        b = GetRoot(b);
        if(a!=b){
            uf[a] = b;
            sum+=c;
        }
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    GetInput();
    printf("%d",Solve());
}