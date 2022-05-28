/*
    가장 긴 팰린드롬 부분 문자열
    https://www.acmicpc.net/problem/14444
*/
#include <bits/stdc++.h>

using namespace std;

// Manacher
vector<size_t> manacher(string str)
{
    str.resize(str.size() << 1 | 1);
    for (size_t i = str.size() >> 1; i--; ) {
        str[i << 1 | 1] = str[i];
        str[i << 1] = '#';
    }

    str[str.size() ^ 1] = '#';

    vector<size_t> p(str.size());
    size_t r, c;
    r = c = 0;
    for (size_t i = 0; str[i]; ++i) {
        auto& k = p[i] = 0;

        if (i <= r)
            k = min(p[2 * c - i], r - i);

        while (i >= p[i] + 1 && i + p[i] + 1 < str.size() && str[i - p[i] - 1] == str[i + p[i] + 1])
            p[i]++;

        if (r < i + p[i])
        {
            r = i + p[i];
            c = i;
        }
    }

    return p;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    string word;
    cin >> word;

    auto result(manacher(move(word)));
    cout << *max_element(result.begin(), result.end());
}