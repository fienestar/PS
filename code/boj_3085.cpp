/*
    사탕 게임
    https://www.acmicpc.net/problem/3085
*/
#include <bits/stdc++.h>

using namespace std;

size_t a[52][52]={};
size_t N;

size_t max_length()
{
    size_t s=0;
    size_t m=0;
    for(size_t i=1;i!=N;++i){
        for(size_t j=1;j!=N;++j){
            if(a[i][j]!=a[i][j-1]){
                m=max(m,s);
                s=0;
            }
            ++s;
        }
        m = max(m,s);
    }
    for(size_t i=1;i!=N;++i){
        for(size_t j=1;j!=N;++j){
            if(a[j][i]!=a[j-1][i]){
                m=max(m,s);
                s=0;
            }
            ++s;
        }
        m = max(m,s);
    }
    return m;
}

#define in_range(x,y) (1<=x&&x<=N && 1<=y&&y<=N)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char c;
    cin >> N;
    ++N;
    for(size_t i=1;i!=N;++i)
        for(size_t j=1;j!=N;++j)
            cin >> (char&)a[i][j];

    int mx[2]={0,1};
    int my[2]={1,0};
    size_t m=0;
    for(size_t i=1;i!=N;++i)
        for(size_t j=1;j!=N;++j)
            for(size_t v=0;v!=2;++v){
                if(!in_range(i+mx[v],j+my[v]))continue;
                swap(a[i][j],a[i+mx[v]][j+my[v]]);
                m=max(m,max_length());
                swap(a[i][j],a[i+mx[v]][j+my[v]]);
            }
    cout << m;
}