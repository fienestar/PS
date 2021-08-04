/*
    Strongly Connected Component
    https://www.acmicpc.net/problem/2150
*/
#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
constexpr ull ull_n = sizeof(ull) * 8;

char buf[1 << 17];
inline char readChar() {
	static int idx = 1 << 17;
	if (idx == 1 << 17) {
		fread(buf, 1, 1 << 17, stdin);
		idx = 0;
	}
	return buf[idx++];
}
inline size_t readUINT32() {
	size_t sum = 0;
	size_t cur = readChar();

	while (cur == 10 || cur == 32)
		cur = readChar();

	while (cur >= 48 && cur <= 57) {
		sum = sum * 10 + cur - 48;
		cur = readChar();
	}

	return sum;
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t V = readUINT32(), E = readUINT32();

	vector<list<size_t>> edges(V);
	vector<list<size_t>> reversed_edges(V);
	while (E--) {
		size_t A = readUINT32(), B = readUINT32();
		--A; --B;

		edges[A].push_back(B);
		reversed_edges[B].push_back(A);
	}

	static ull in_scc[157];
	ull* current_visited;
	vector<list<size_t>>* current_edges;
	function<void(size_t)> visit = [&](size_t v) {
		current_visited[v / ull_n] |= (1ull << v % ull_n);

		for (auto next : (*current_edges)[v])
			if (!(current_visited[next / ull_n] & (1ull << next % ull_n)) && !(in_scc[next / ull_n] & (1ull << next % ull_n)))
				visit(next);
	};

	list<list<size_t>> scc_list;
	static ull visited[2][157];

	for (size_t i = 0; i != V; ++i)
		if (!(in_scc[i / ull_n] & (1ull << (i % ull_n)))) {
			memset(visited[0], 0, sizeof(visited[0]));
			current_visited = visited[0];
			current_edges = &reversed_edges;
			visit(i);

			memset(visited[1], 0, sizeof(visited[1]));
			current_visited = visited[1];
			current_edges = &edges;
			visit(i);

			list<size_t> scc;
			for (size_t k = 0; k != 157; ++k) {
				auto mark = visited[0][k] & visited[1][k] & ~in_scc[k];
				if (!mark)continue;
				for (size_t j = 0; j != ull_n; ++j)
					if (mark & (1ull << j))
						scc.push_back(k * ull_n + j + 1);
				in_scc[k] |= mark;
			}

			scc_list.emplace_back(move(scc));
		}

	cout << scc_list.size() << "\n";
	for (auto& scc : scc_list) {
		for (auto& v : scc)
			cout << v << " ";
		cout << "-1\n";
	}
}