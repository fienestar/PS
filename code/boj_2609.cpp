/*
    최대공약수와 최소공배수
    https://www.acmicpc.net/problem/2609
*/
// 사용된 알고리즘: 
// R:
// T:

#include <bits/stdc++.h>

using namespace std;

#ifndef LOCAL
#define LOCAL(x) ((void)0)
#endif

int main()
{
    LOCAL(OUTPUT_TO_FILE);
    LOCAL(INPUT_FROM_FILE);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Code here!
    size_t A,B,a,b,t;
    cin >> A >> B;
    a = A;
    b = B;
    while(b){
        t = a;
        a = b;
        b = t%b;
    }
    cout << a << "\n" << A*B/a;
}