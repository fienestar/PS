/*
    암호 만들기
    https://www.acmicpc.net/problem/1759
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t L, C;
	cin >> L >> C;

	vector<char> cs(C);
	for(auto& c:cs)
		cin >> c;

	sort(cs.begin(),cs.end());

	vector<char> result(L);
	function<void(size_t,size_t)> dfs = [&](size_t i, size_t k){
		if(i == L){
			size_t aeiou = 0;
			size_t others = 0;

			for(auto c:result)
				if(find("aeiou", "aeiou"+5, c) == "aeiou"+5)
					++others;
				else
					++aeiou;

			if(others < 2 || aeiou < 1)
				return;

			for(auto c:result)
				cout << c;
			cout << "\n";
			return;
		}

		for(; k!=cs.size(); ++k){
			result[i] = cs[k];
			dfs(i+1,k+1);
		}
	};
	dfs(0,0);
}