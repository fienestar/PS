/*
    숫자 정사각형
    https://www.acmicpc.net/problem/1051
*/
#include <bits/stdc++.h>

using namespace std;

bool same(vector<size_t> v)
{
    for(auto c:v)
        if(c!=v[0])return false;
    return true;
}

size_t has(vector<vector<size_t>>& v,size_t len)
{
    for(size_t i=len;i!=v.size();++i)
        for(size_t j=len;j!=v[i].size();++j)
            if(same({v[i-len][j-len],v[i-len][j],v[i][j-len],v[i][j]}))
                return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t N,M;
    cin >> N >> M;
    vector<vector<size_t>> v(N,vector<size_t>(M));

    for(auto& i:v)
        for(auto& j:i){
            char c;
            cin >> c;
            j = c - '0';
        }

    for(size_t i=min({N,M});i--;)
        if(has(v,i)){
            cout << (i+1)*(i+1);
            return 0;
        }
}