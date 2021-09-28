/*
    열혈강호 2
    https://www.acmicpc.net/problem/11376
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N, M;
	cin >> N >> M;

	vector<list<size_t>> v(N);
	for(auto& c:v){
		size_t wn,w;
		cin >> wn;

		while(wn--){
			cin >> w;
			c.push_back(w-1);
		}
	}

	vector<size_t> own(M,-1);
	vector<size_t> work_count(N);
	bool visited[1000];
	function<bool(size_t,size_t)> can = [&](size_t i, size_t work){
		visited[work] = true;
		if(own[work] == -1){
			own[work] = i;
			++work_count[i];
			return true;
		}

		for(auto& w:v[own[work]])
			if(w != work && !visited[w] && can(own[work], w)){
				own[work] = i;
				++work_count[i];
				return true;
			}

		return false;
	};

	size_t ans = 0;
	for(size_t i=0; i!=N; ++i){
		memset(visited,0,1'000);
		for(auto& c:v[i]){
			ans += can(i, c);
			if(work_count[i] == 2)
				break;
		}
	}

	cout << ans;
}