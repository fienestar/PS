/*
    백설공주와 난쟁이
    https://www.acmicpc.net/problem/2912
*/
#include <bits/stdc++.h>

using namespace std;

template <class T>
class segment_tree
{
	vector<T> m_tree;
	function<T(const T&, const T&)> m_join;

public:
	template <class It>
	segment_tree(It begin, It end, const T& default_value, function<T(const T&, const T&)> join)
		:m_join(join)
	{
		size_t node_count = 1;
		size_t init_value_count = distance(begin, end);
		while (node_count < init_value_count)node_count <<= 1;
		m_tree.resize(node_count << 1, default_value);

		for (size_t i = node_count; begin != end; ++i)
			m_tree[i] = *begin++;

		for (size_t i = node_count; i--;)
			m_tree[i] = m_join(m_tree[i << 1], m_tree[i << 1 | 1]);
	}

	size_t leafSize() { return m_tree.size() >> 1; }
	size_t nodeSize() { return m_tree.size(); }
	const T& leafAt(size_t idx) { return m_tree[(m_tree.size() >> 1) + idx]; }
	const T& nodeAt(size_t idx) { return m_tree[idx]; }
	size_t leaf2node(size_t i) { return i + (m_tree >> 1); }

	// [leaf_begin, leaf_end)
	void queryByRange(size_t leaf_begin, size_t leaf_end, function<void(const T&)> query)
	{
		size_t b = leafSize() + leaf_begin;
		size_t e = leafSize() + leaf_end;

		while (b < e) {
			if (b & 1)query(nodeAt(b++));
			if (e & 1)query(nodeAt(--e));

			b >>= 1; e >>= 1;
		}
	}

	void update(size_t i, const T& new_value)
	{
		m_tree[i] = new_value;

		while (i >>= 1)
			m_tree[i] = m_join(m_tree[i << 1], m_tree[i << 1 | 1]);
	}
};

constexpr size_t freq_div = 40000;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	using color_t = uint16_t;
	size_t N, C;
	cin >> N >> C;

	using freq_t = vector<size_t>;
	vector<color_t> line(N);
	freq_t null_freq(C, 0);
	vector<freq_t> freq_list(N / freq_div + !!N % freq_div, null_freq);
	for (size_t i = 0; i != N; ++i) {
		cin >> line[i];
		--line[i];

		++freq_list[i / freq_div][line[i]];
	}

	segment_tree<freq_t> seg(freq_list.begin(), freq_list.end(), null_freq,
		[&](const freq_t& a, const freq_t& b) {
			freq_t result = a;
			for (size_t i = 0; i != C; ++i)
				result[i] += b[i];
			return result;
		}
	);

	size_t M;
	cin >> M;

	while (M--) {
		size_t a, b;
		cin >> a >> b;
		--a;

		size_t range_size = b - a;

		freq_t result(C, 0);
		for (; a % freq_div && a != b; ++a)
			++result[line[a]];

		for (; b % freq_div && a != b; --b)
			++result[line[b-1]];

		seg.queryByRange(a / freq_div, b / freq_div, [&](const freq_t& v) {
			for (size_t i = 0; i != C; ++i)
				result[i] += v[i];
			});

		size_t i;
		for (i = 0; i != C; ++i)
			if (result[i] > range_size / 2) {
				cout << "yes " << i + 1 << "\n";
				break;
			}

		if (i == C)
			cout << "no\n";
	}
}