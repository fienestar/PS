/*
    경로 찾기
    https://www.acmicpc.net/problem/11403
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N;
	cin >> N;

	vector<vector<int>> can_go(N, vector<int>(N));
	for(auto& line:can_go)
		for(auto& e:line)
			cin >> e;

	for(size_t k=0; k!=N; ++k)
		for(size_t i=0; i!=N; ++i)
			for(size_t j=0; j!=N; ++j)
				can_go[i][j] |= can_go[i][k] && can_go[k][j];

	for(auto& line:can_go){
		for(auto& e:line)
			cout << e << " ";
		cout << "\n";
	}
}