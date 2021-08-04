/*
    Counting Inversions
    https://www.acmicpc.net/problem/10090
*/
#include <bits/stdc++.h>

using namespace std;

int N;
int t[2000000];

void set_t(size_t idx, int new_n)
{
    t[idx] = new_n;
}

int get_t(size_t idx)
{
    return t[idx];
}

int query(int l, int r)
{
    int ans = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans += get_t(l++);
        if (r & 1) ans += get_t(--r);
    }
    return ans;
}

void update(int pos, int val)
{
    set_t(pos + N,val);
    for (pos += N; pos > 1; pos >>= 1)
        set_t(pos >> 1,get_t(pos) + get_t(pos ^ 1));
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N;

    vector<pair<size_t,size_t>> v(N);
    for(size_t i=0; i!=N; ++i){
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end());

    size_t cnt = 0;
    for(auto& c:v){
        cnt += query(c.second, N);
        update(c.second, 1);
    }

    cout << cnt;
}