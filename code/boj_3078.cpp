/*
    좋은 친구
    https://www.acmicpc.net/problem/3078
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	size_t N, K;
	cin >> N >> K;

	vector<size_t> l[19];
	string name;
	for(size_t i=0; i!=N; ++i){
		cin >> name;
		l[name.size()-2].push_back(i);
	}

	size_t ans = 0;
	for(auto& v:l)if(v.size()){
		size_t i = 0;
		size_t sub_count = 0;
		for(size_t j=0; j!=v.size(); ++j)
			if(v[j] - v[i] <= K)
				++sub_count;
			else{
				ans += --sub_count;
				++i; --j;
			}
		ans += --sub_count;
		ans += (sub_count-1)*(sub_count)/2;
	}
	cout << ans;
}