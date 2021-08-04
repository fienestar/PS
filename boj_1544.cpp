/*
    사이클 단어
    https://www.acmicpc.net/problem/1544
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	set<string> s;
	size_t count = 0;
	while(N--){
		string inp;
		cin >> inp;

		if(s.find(inp) != s.end()) continue;

		++count;
		for(size_t i=0; i!=inp.size(); ++i)
			s.insert(inp.substr(i, inp.size()) + inp.substr(0, i));
	}

	cout << count;
}