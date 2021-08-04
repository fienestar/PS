/*
    럭키 스트레이트
    https://www.acmicpc.net/problem/18406
*/
// 사용된 알고리즘: dp?
// R: X
// T: 0

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string N;
    size_t sum=0;
    cin >> N;
    for(size_t i=0;i!=N.size()/2;++i)
        sum+=N[i]-'0';
    for(size_t i=N.size()/2;i!=N.size();++i)
        sum-=N[i]-'0';
    cout << (sum?"READY":"LUCKY");
}