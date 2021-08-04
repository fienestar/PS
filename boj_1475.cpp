/*
    방 번호
    https://www.acmicpc.net/problem/1475
*/
// 사용된 알고리즘: 
// R: X
// T: 0

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Code here!
    size_t cnt[10]={},mx=0;
    size_t N,C;
    cin >> N;
    if(N==0){
        cout << 1;
        return 0;
    }
    do{
        C=N%10;
        if(C==9||C==6){
            C=6;
            ++cnt[C];
            mx=max(mx,(cnt[C]>>1)+(cnt[C]&1));
            continue;
        }
        ++cnt[C];
        mx=max(mx,cnt[C]);
    }while(N/=10);
    cout << mx;
}