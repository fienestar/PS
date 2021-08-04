/*
    피리 부는 사나이
    https://www.acmicpc.net/problem/16724
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N,M;
	cin >> N >> M;

	vector<vector<size_t>> m(N,vector<size_t>(M));
	for(auto& c:m)
		for(auto& v:c){
			char k;
			cin >> k;
			v = find("UDLR", "UDLR"+4, k) - "UDLR";
		}

	int dx[] = {-1,1,0,0};
	int dy[] = {0,0,-1,1};
	size_t merge_index = 4;

	auto check = [&](size_t i, size_t j){
		queue<pair<size_t,size_t>> q;
		q.emplace(i,j);

		size_t x = i, y = j;
		do{
			size_t mx = x + dx[m[x][y]];
			size_t my = y + dy[m[x][y]];
			m[x][y] = merge_index;

			x = mx;
			y = my;
		}while(m[x][y] < 4);

		return m[x][y] == merge_index++;
	};

	size_t count = 0;
	for(size_t i=0; i!=N; ++i)
		for(size_t j=0; j!=M; ++j)
			if(m[i][j] < 4)
				count += check(i,j);

	cout << count;
}