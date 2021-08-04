/*
    단지번호붙이기
    https://www.acmicpc.net/problem/2667
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	vector<vector<int>> m(N,vector<int>(N,0));
	for(auto& c:m)
		for(auto& v:c){
			char k;
			cin >> k;
			v = k - '0';
		}
	auto f = [&](size_t i, size_t j) {
		queue<pair<size_t,size_t>> q;
		m[i][j] = 0;
		q.emplace(i,j);

		size_t count = 0;
		while(not q.empty()){
			auto[x,y] = q.front();
			++count;
			q.pop();

			static int dx[] = {1,-1,0,0};
			static int dy[] = {0,0,1,-1};

			for(size_t i=0; i!=4; ++i){
				size_t mx = x + dx[i];
				size_t my = y + dy[i];
				if(mx < N && my < N && m[mx][my] == 1){
					m[mx][my] = 0;
					q.emplace(mx,my);
				}
			}
		}
		return count;
	};

	vector<size_t> counts;

	for(size_t i=0; i!=N; ++i)
		for(size_t j=0; j!=N; ++j)
			if(m[i][j] == 1)
				counts.push_back(f(i,j));

	sort(counts.begin(),counts.end());

	cout << counts.size() << "\n";
	for(auto& count:counts)
		cout << count << "\n";
}