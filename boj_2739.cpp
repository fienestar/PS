/*
    구구단
    https://www.acmicpc.net/problem/2739
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

int main()
{
    LOCAL(OUTPUT_TO_FILE);
    //LOCAL(INPUT_FROM_FILE);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Code here!
    size_t N;
    cin >> N;
    for(size_t i=1;i<=9;++i)
        cout << N << " * " <<  i << " = " << N*i << endl;
}