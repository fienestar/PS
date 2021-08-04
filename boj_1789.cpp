/*
    수들의 합
    https://www.acmicpc.net/problem/1789
*/
#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;

class VI
{
    ll _N;
public:
    using iterator_category = random_access_iterator_tag;
    using difference_type   = ll;
    using value_type        = ll;
    using pointer           = ll*;
    using reference         = ll&;
    VI(ll N):_N(N) {}
    ll operator*() { return _N * (_N+1) / 2; }
    operator ll&() { return _N; }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll S;
    cin >> S;
    
    cout << --upper_bound(VI(1),VI(1<<17),S);
}