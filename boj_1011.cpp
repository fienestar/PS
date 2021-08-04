/*
    Fly me to the Alpha Centauri
    https://www.acmicpc.net/problem/1011
*/
#include <bits/stdc++.h>

using namespace std;

size_t solve()
{
    size_t x,y;
    cin >> x >> y;

    size_t i = 0;
    while(i*(i+1) < y-x)
        ++i;

    size_t j = 0;
    while(j*(j+1)+j+1 < y-x)
        ++j;

    return min(i*2,j*2+1);
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    size_t T;
    cin >> T;

    while(T--)
        cout << solve() << "\n";
}