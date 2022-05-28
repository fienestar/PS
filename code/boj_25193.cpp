/*
    곰곰이의 식단 관리
    https://www.acmicpc.net/problem/25193
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	string s;
	cin >> s;

	size_t count = 0;
	for(auto c:s) count += c != 'C';
	cout << s.size() / (count+1);
}