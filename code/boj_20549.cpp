/*
    인덕이의 고민
    https://www.acmicpc.net/problem/20549
*/
#include <bits/stdc++.h>

using namespace std;
using puu = pair<size_t, size_t>;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	size_t cost[3];
	for(auto& c:cost)
		cin >> c;

	size_t x, y;
	cin >> x >> y;

	size_t M;
	cin >> M;

	size_t board[50][50] = {};
	size_t end = (1 << M) - 1;
	while(M--){
		size_t x, y;
		cin >> x >> y;
		board[x][y] = 1 << M;
	}

	using state_t = tuple<size_t, size_t, size_t, size_t, size_t>;
	priority_queue<state_t, vector<state_t>, greater<state_t>> pq;
	for(size_t i=0; i!=3; ++i)
		pq.emplace(cost[i], i, x, y, 0);

	bool visited[50][50][1 << 5] = {};
	while(true){
		auto [w, k, x, y, m] = pq.top();
		pq.pop();

		if(m == end){
			cout << w;
			return 0;
		}

		for(size_t i=0; i!=4; ++i)
			for(size_t j=0; j!=2; ++j){
				auto run = [&](size_t dx, size_t dy){
					if(j == 1) swap(dx, dy);

					static int bx[] = {1,1,-1,-1};
					static int by[] = {1,-1,1,-1};
					size_t mx = x + dx * bx[i];
					size_t my = y + dy * by[i];

					if(mx >= N || my >= N)return;

					size_t mm = m | board[mx][my];
					if(mm == end){
						cout << w;
						exit(0);
					}
					if(visited[mx][my][mm])return;
					visited[mx][my][mm] = true;

					for(size_t i=0; i!=3; ++i)
						pq.emplace(w+cost[i], i, mx, my, mm);
				};

				if(k == 0){
					run(1,2); run(2,1);
				}else
					for(size_t i=1; i!=N; ++i)
						run(i*(k==1),i);
			}
	}
}