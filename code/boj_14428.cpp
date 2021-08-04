/*
    수열과 쿼리 16
    https://www.acmicpc.net/problem/14428
*/
#include <bits/stdc++.h>

using namespace std;

template <class T>
class segment_tree
{
	vector<T> m_tree;
	function<T(const T&, const T&)> m_join;
	
	void init()
	{
		for (size_t i = m_tree.size() >> 1; --i;)
			m_tree[i] = m_join(m_tree[i << 1], m_tree[i << 1 | 1]);
	}
public:
	segment_tree(function<T(const T&, const T&)> join, size_t n)
		:m_tree(n << 1),m_join(join) {
		init();
	}

	template <class It>
	segment_tree(function<T(const T&, const T&)> join, It begin, It end)
		:m_tree(), m_join(join)
	{
		size_t n = distance(begin, end);
		m_tree.resize(n << 1);
		for (size_t i = 0; i != n; ++i)
			m_tree[n + i] = *begin++;

		init();
	}

	void query(size_t begin, size_t end, function<void(const T&)> query)
	{
		begin += m_tree.size() >> 1;
		end += m_tree.size() >> 1;

		for (; begin < end; begin >>= 1, end >>= 1)
		{
			if (begin & 1)query(m_tree[begin++]);
			if (end & 1)query(m_tree[--end]);
		}
	}

	void update(size_t i, const T& val)
	{
		m_tree[i += (m_tree.size() >> 1)] = val;
		for (; i >>= 1;)
			m_tree[i] = m_join(m_tree[i << 1], m_tree[i << 1 | 1]);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	size_t N;
	cin >> N;

	using pis = pair<int, size_t>;
	vector<pis> input(N);
	for(size_t i=0; i!=N; ++i){
		cin >> input[i].first;
		input[i].second = i;
	}

	segment_tree<pis> seg([](pis a,pis b){
		return min(a,b);
	},input.begin(),input.end());

	size_t M;
	cin >> M;

	while(M--){
		size_t t,a,b;
		cin >> t >> a >> b;
	  
		if(t == 1)
			seg.update(a-1,pis(b,a-1));
		else{
			pis m = {1'000'000'001, -1};
			seg.query(a-1, b, [&m](pis v){ m = min(m, v); });
			cout << m.second+1 << "\n";
		}
	}
}