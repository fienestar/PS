/*
    수열과 쿼리 24
    https://www.acmicpc.net/problem/17408
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

	size_t N;
	cin >> N;

	using ll = long long;
	using p = pair<ll,ll>;
	vector<p> v(N);

	for(auto& c:v){
		cin >> c.first;
		c.second = -1;
	}

	auto join = [](p a,p b){
		ll arr[4] = {a.first,a.second,b.first,b.second};
		sort(arr, arr+4);
		return p(arr[3], arr[2]);
	};

	segment_tree<p> seg(v.begin(), v.end(), p(-1,-1), join);

	size_t M;
	cin >> M;

	while(M--){
		ll o,i,j;
		cin >> o >> i >> j;

		if(o == 1)
			seg.update(seg.leafSize()+i-1,p(j,-1));
		else{
			--i;
			p result = {-1,-1};
			seg.queryByRange(i,j,[&](p n){ result = join(result, n); });
			cout << result.first + result.second << "\n"; 
		}
	}
}