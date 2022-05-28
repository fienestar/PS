/*
    상어의 저녁식사
    https://www.acmicpc.net/problem/1671
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	vector<tuple<size_t,size_t,size_t>> sharks(N);
	for(auto& [x,y,z]:sharks)
		cin >> x >> y >> z;

	sort(begin(sharks), end(sharks));

	vector<size_t> group_count;
	vector<size_t> group_of(N);

	group_of[0] = 0;
	group_count.push_back(1);
	for(size_t i=1; i!=N; ++i){
		if(sharks[i-1] == sharks[i]){
			group_of[i] = group_of[i-1];
			group_count[group_of[i]]++;
		}else{
			group_of[i] = group_of[i-1]+1;
			group_count.push_back(1);
		}
	}

	vector<size_t> own(N, -1);
	bool visited[50];
	function<bool(size_t)> can = [&](size_t v){
		visited[v] = true;

		auto [x,y,z] = sharks[v];

		for(size_t i=0; i!=N; ++i){
			auto [a,b,c] = sharks[i];

			if(i == v) continue;
			if(x<a || y<b || z<c) continue;
			if(group_of[v] == group_of[i] && group_count[group_of[i]] == 1) continue;

			if(own[i] == -1 || (!visited[own[i]] && can(own[i]))){
				if(own[i] != -1 && group_of[own[i]] == group_of[i])
					++group_count[group_of[i]];
				if(group_of[v] == group_of[i])
					--group_count[group_of[i]];
				own[i] = v;
				return true;
			}
		}

		return false;
	};

	size_t count = N;
	for(size_t i=0; i!=N; ++i){
		memset(visited, 0, sizeof(visited));
		count -= can(i);
		memset(visited, 0, sizeof(visited));
		count -= can(i);
	}

	cout << count;
}