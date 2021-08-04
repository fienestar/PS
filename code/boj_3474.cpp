/*
    교수가 된 현우
    https://www.acmicpc.net/problem/3474
*/
#include <bits/stdc++.h>

using namespace std;

double log5(double n)
{
    return log10(n)/log10(5);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Code here!
    size_t T,N;
    cin >> T;
    
    while(cin >> N){
        size_t n2,n5;
        size_t c2,c5;
        n2 = n5 = N;
        c2 = c5 = 0;

        while(n2/=2)c2+=n2;
        while(n5/=5)c5+=n5;

        cout << min(c2,c5) << "\n";
    }
}