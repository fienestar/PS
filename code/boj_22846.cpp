/*
    인증된 쉬운 게임
    https://www.acmicpc.net/problem/22846
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    size_t K;
    cin >> K;

    static bool win[100001];

    for(size_t i=K; i; i--)
        for(size_t j=1; j*j<=i; ++j)
            if(i%j == 0)
                for(size_t k=0; k!=2; ++k) {
                    if(i+j <= K && win[i+j] == false) {
                        win[i] = true;
                        break;
                    }
                    j = i/j;
                }

    if(win[1])
        cout << "Kali";
    else
        cout << "Ringo";
}