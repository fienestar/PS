/*
    사탕 배달
    https://www.acmicpc.net/problem/17305
*/
#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	ull N, W;
	cin >> N >> W;

	vector<ull> s[6];

	s[3].reserve(N/2);
	s[5].reserve(N/2);
	s[3].push_back(0);
	s[5].push_back(0);

	while(N--){
		ull ti,si;
		cin >> ti >> si;
		s[ti].push_back(si);
	}

	for(size_t i=3; i!=7; i+=2){
		sort(s[i].begin()+1, s[i].end(), greater<ull>());
		for(size_t j=1; j!=s[i].size(); ++j)
			s[i][j] += s[i][j-1];
	}

	ull s_max = 0;

#define safe_get(container, index) \
(((index) < (container).size()) ? ((container)[(index)]) : (container)[(container).size()-1])

	for(size_t i=0; i*5 <= W && i!=s[5].size(); ++i)
		s_max = max(s_max, s[5][i] + safe_get(s[3],(W-5*i)/3));

	cout << s_max;
}