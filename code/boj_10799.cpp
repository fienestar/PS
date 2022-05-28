/*
    쇠막대기
    https://www.acmicpc.net/problem/10799
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;

	size_t b = 0;
	size_t ans = 0;
	for(size_t i=0; s[i]; ++i)
		if(s[i] == '(')
			++b;
		else{
			--b;
			if(i && s[i-1] == '(')
				ans += b;
			else
				ans += 1;
		}

	cout << ans;
}