/*
    함께 블록 쌓기
    https://www.acmicpc.net/problem/18427
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
    int dp[1001]={1};
    int ch[1001]={};
    stringstream ss;
    char s[50];
    int N,M,H,K;
    cin.getline(s,50);
    ss.clear();
    ss.str(s);
    ss >> N >> M >> H;
    
    while(N--){
        cin.getline(s,50);
        ss.clear();
        ss.str(s);
        while(ss >> K){
            for(int i=0;i+K<=H;++i)
                if(dp[i])
                    ch[i+K]+=dp[i];
        }
        for(int i=0;i<=H;++i)
            if(ch[i]){
                dp[i]=(dp[i]+ch[i])%10007;
                ch[i]=0;
            }
    }
    cout << dp[H];
}