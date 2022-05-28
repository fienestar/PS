/*
    치킨댄스를 추는 곰곰이를 본 임스
    https://www.acmicpc.net/problem/25191
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N, A, B;
	cin >> N >> A >> B;
	cout << min(N, A/2+B);
}