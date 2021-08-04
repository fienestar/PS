/*
    영화 수집
    https://www.acmicpc.net/problem/3653
*/
#include <bits/stdc++.h>

using namespace std;

template <class T>
class segment_tree
{
    vector<T> m_data;
    function<T(const T&, const T&)> m_join;
public:
    segment_tree(size_t n, T default_value, function<T(const T&, const T&)> join)
        :m_join(join)
    {
        size_t i = 1;
        while (i < n) i <<= 1;

        m_data.resize(i << 1, default_value);

        for (size_t j = i; j--;)
            m_data[j] = m_join(m_data[j << 1], m_data[j << 1 | 1]);
    }

    void update(size_t node_i, T value)
    {
        m_data[node_i] = value;
        while (node_i >>= 1)
            m_data[node_i] = m_join(m_data[node_i << 1], m_data[node_i << 1 | 1]);
    }

    size_t leafSize()
    {
        return m_data.size() >> 1;
    }

    size_t nodeSize()
    {
        return m_data.size();
    }

    // [leaf_begin, leaf_end)
    void queryByRange(size_t leaf_begin, size_t leaf_end, function<void(const T&)> query)
    {
        size_t b = leafSize() + leaf_begin;
        size_t e = leafSize() + leaf_end;

        while (b < e) {
            if (b & 1)query(getNode(b++));
            if (e & 1)query(getNode(--e));

            b >>= 1; e >>= 1;
        }
    }

    T getLeaf(size_t leaf_i)
    {
        return getNode(leafSize() + leaf_i);
    }

    T getNode(size_t node_i)
    {
        return m_data[node_i];
    }
};

void solve()
{
	size_t n,m;
	cin >> n >> m;

	vector<size_t> pos(n);
	for(size_t i=0; i!=n; ++i)
		pos[i] = n-i-1;

	segment_tree<int> seg(n+m, 1, [](int a, int b) { return a+b; });

	for(size_t i=n; i!=n+m; ++i){
		size_t k;
		cin >> k;
		--k;

		int sum = 0;
		seg.queryByRange(0,pos[k],[&sum](int n){sum += n;});
		cout << n - sum - 1 << " ";

		seg.update(seg.leafSize() + pos[k], 0);
		pos[k] = i;
	}
	cout << "\n";
}


int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t T;
	cin >> T;

	while(T--)solve();
}