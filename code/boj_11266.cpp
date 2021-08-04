/*
    단절점
    https://www.acmicpc.net/problem/11266
*/
#include <bits/stdc++.h>

using namespace std;

/*
단절점의 조건

!root: 자식중에 현재 노드보다 낮은 깊이로 가는 자식이 없는가?
root: 자식이 두개 이상인가?
*/
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t V,E;
	cin >> V >> E;

	vector<list<size_t>> Es(V);
	while(E--){
		size_t A,B;
		cin >> A >> B;
		--A; --B;

		Es[A].emplace_back(B);
		Es[B].emplace_back(A);
	}

	vector<size_t> is_cv(V, false);
	vector<size_t> id(V, 0);
	size_t id_idx = 1;

	function<size_t(size_t)> get_min_sub_id = [&](size_t n){
		id[n] = id_idx++;

		size_t min_sub_id = id[n];
		for(auto& e:Es[n]){
			size_t result = id[e];
			if(!result){
				result = get_min_sub_id(e);
				if(result >= id[n])
					is_cv[n] = true;
			}
			min_sub_id = min(min_sub_id, result);
		}

		return min_sub_id;
	};

	for(size_t i=0; i!=V; ++i)
		if(!id[i]){
			id[i] = id_idx++;
			size_t sub = 0;
			for(auto& e:Es[i])
				if(!id[e]){
					++sub;
					get_min_sub_id(e);
				}
			is_cv[i] = (sub >= 2);
		}

	list<size_t> answer;
	for(size_t i=0; i!=V; ++i)
		if(is_cv[i])
			answer.emplace_back(i+1);

	cout << answer.size() << "\n";
	for(auto& v:answer)
		cout << v << " ";
}