/*
    토마토
    https://www.acmicpc.net/problem/7576
*/
#include <bits/stdc++.h>

using namespace std;

#define not_in_range(i,j) (i<0 || i>=M || j<0 || j>=N)
using pos = pair<int,int>;

int main()
{
    static int moveX[4] = {1,-1,0,0};
    static int moveY[4] = {0,0,1,-1};
    int M,N;
    int m[1000][1000];
    queue<pos> q;
    int count = 0;
    int day = 0;
    
    cin >> N >> M;
    for(int x=0;x!=M;++x)
        for(int y=0;y!=N;++y){
            cin >> m[x][y];
            switch(m[x][y]){
                case -1:
                    break;
                case 0:
                    ++count;
                    break;
                case 1:
                    for(int i=0;i!=4;++i)
                        q.emplace(x+moveX[i],y+moveY[i]);
                    break;
            }
        }
    q.emplace(9999,9999);
    if(count)
    while(!q.empty()){
        auto[x,y] = q.front();
        q.pop();
        
        if(x==9999&&y==9999){
            if(count&&!q.empty())q.emplace(9999,9999);
            ++day;
            continue;
        }
        
        if(not_in_range(x,y) || m[x][y])continue;

        m[x][y]=1;
        --count;
        for(size_t i=0;i!=4;++i)
            q.emplace(x+moveX[i],y+moveY[i]);
    }
    
    if(count)cout << -1;
    else cout << day;
}