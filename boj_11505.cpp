/*
    구간 곱 구하기
    https://www.acmicpc.net/problem/11505
*/
#include <bits/stdc++.h>

using namespace std;

template <class T>
class segment_tree
{
    vector<T> m_data;
    function<T(const T&, const T&)> m_join;
public:
    template <class It>
    segment_tree(It begin, It end, T default_value, function<T(const T&, const T&)> join)
        :m_join(join)
    {
        size_t i = 1;
        size_t n = distance(begin, end);
        while (i < n) i <<= 1;

        m_data.resize(i << 1, default_value);

        for (size_t j = i; begin != end; ++j, ++begin)
            m_data[j] = *begin;

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


int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N, M, K;
	cin >> N >> M >> K;
	M += K;

	using ull = unsigned long long;
        vector<ull> v(N);
        for(auto& c:v)
            cin >> c;

	segment_tree<ull> seg(v.begin(), v.end(), 1, [](ull a, ull b) { return a*b%1000000007; });

	while(M--){
		ull o,i,j;
		cin >> o >> i >> j;

		if(o == 2){
			ull mul = 1;
			if(i>j)swap(i,j);
			seg.queryByRange(i-1, j, [&mul](ull n){mul = mul*n%1000000007;});
			cout << mul << "\n";
		}else
			seg.update(seg.leafSize() + i - 1, j);
	}
}