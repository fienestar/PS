/*
    선린의 터를
    https://www.acmicpc.net/problem/21968
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    size_t T;
    cin >> T;

    while(T--){
        using ull = unsigned long long;
        ull N;
        cin >> N;

        ull A = 0;
        for(ull i=1, j=1; i<123456789123; i<<=1, j*=3)
            if(N&i)
                A += j;

        cout << A << "\n";
    }
}