/*
    명령 프롬프트
    https://www.acmicpc.net/problem/1032
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Code here!
    size_t N;
    string in,cmp;
    
    cin >> N >> in;
    
    vector<char> ans(in.begin(),in.end());
    while(--N){
        cin >> cmp;
        for(size_t i=0;cmp[i];++i)
            if(cmp[i] != in[i])
                ans[i] = '?';
    }
    copy(ans.begin(),ans.end(),ostream_iterator<char>{cout,""});
}