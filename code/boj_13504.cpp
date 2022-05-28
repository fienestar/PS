/*
    XOR 합
    https://www.acmicpc.net/problem/13504
*/
#include <bits/stdc++.h>

using namespace std;

void solve()
{
	size_t N;
	cin >> N;

	using node_t = uint32_t[2];
	static node_t nodes[10000000];
	memset(nodes, 0, sizeof(nodes));
	auto root = nodes[0];
	size_t node_idx = 1;

	auto mark = [&](uint32_t& node){
		if(!node) node = node_idx++;
		return node;
	};

	auto reg = [&](int v){
		auto node = root;
		for(size_t i=31; i--;)
			node = nodes[mark(node[!!(v & (1 << i))])];
	};

	auto maximize = [&](int v){
		auto node = root;
		for(size_t i=31; i--;){
			int selected = 0;
			if(node[0] && node[1])
				selected = !(v & (1 << i));
			else if(node[1])
				selected = 1;

			v ^= selected << i;
			node = nodes[node[selected]];
		}

		return v;
	};

	int sum = 0;
	int M = 0;
	reg(0);
	while(N--){
		int a;
		cin >> a;
		sum ^= a;

		M = max(M, maximize(sum));
		reg(sum);
	}

	cout << M << "\n";
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t T;
	cin >> T;

	while(T--)solve();
}