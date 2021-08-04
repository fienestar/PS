/*
    수 정렬하기 2
    https://www.acmicpc.net/problem/2751
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    size_t N;
    cin >> N;

    vector<int> v(N);
    for(auto& c:v)
        cin >> c;

    sort(v.begin(), v.end());

    for(auto c:v)
        cout << c << " ";
}