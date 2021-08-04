/*
    별 찍기 - 7
    https://www.acmicpc.net/problem/2444
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

void chars(char C, size_t N)
{
    while(N--)cout << C;
}

void charsln(char C, size_t N)
{
    chars(C,N);
    cout << endl;
}

#define stars(N) chars('*',N)
#define starsln(N) charsln('*',N)
#define spaces(N) chars(' ',N)
#define spacesln(N) charsln(' ',N)

int main()
{
    LOCAL(OUTPUT_TO_FILE);
    //LOCAL(INPUT_FROM_FILE);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Code here!
    size_t N,i=0;
    cin >> N;
    do{
        spaces(N-i-1);
        starsln(2*i+1);
    }while (++i!=N);
    --i;
    while(i--)
    {
        spaces(N-i-1);
        starsln(2*i+1);
    }
}