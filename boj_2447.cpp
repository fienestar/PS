/*
    별 찍기 - 10
    https://www.acmicpc.net/problem/2447
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

static vector<vector<int>> v;

void print(size_t x,size_t y,size_t N)
{
    if(N==1){
        v[x][y]=1;
        return;
    }
    static int moveX[] = {0,0,0,1,1,2,2,2};
    static int moveY[] = {0,1,2,0,2,0,1,2};
    N/=3;
    for(size_t i=0;i!=8;++i)
        print(x+moveX[i]*N,y+moveY[i]*N,N);
}

int main()
{
    //LOCAL(OUTPUT_TO_FILE);
    //LOCAL(INPUT_FROM_FILE);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Code here!
    size_t N;
    cin >> N;
    v.resize(N,vector<int>(N));
    print(0,0,N);
    for(auto& i:v){
        for(auto& j:i)
            cout << (j?"*":" ");
        cout << endl;
    }
}