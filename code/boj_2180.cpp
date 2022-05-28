/*
    소방서의 고민
    https://www.acmicpc.net/problem/2180
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    size_t N;
    cin >> N;

    using puu = pair<size_t, size_t>;
    vector<puu> abp(N);
    size_t k = 0;
    for(size_t i=0; i!=N; ++i){
        auto& [a,b] = abp[i];
        cin >> a >> b;

        if(a == 0 && b == 0)
            swap(abp[k++], abp[i]);
    }

    auto eval = [](puu& a, puu& b){
        return a.second * b.first;
    };

    sort(begin(abp)+k, end(abp), [&](puu& a, puu& b){
        return eval(a,b) < eval(b,a);
    });

    size_t t = 0;
    for(auto& [a,b]:abp)
        t = ((a+1)*t + b) % 40000;

    cout << t;
}