/*
    세로읽기
    https://www.acmicpc.net/problem/10798
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	string ss[5];
	size_t ml = 0;
	for(auto& s:ss){
		cin >> s;
		ml = max(ml, s.size());
	}

	for(size_t i=0; i!=ml; ++i)
		for(size_t j=0; j!=5; ++j)
			if(i < ss[j].size())
				cout << ss[j][i];
}