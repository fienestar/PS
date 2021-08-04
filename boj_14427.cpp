/*
    수열과 쿼리 15
    https://www.acmicpc.net/problem/14427
*/
#include <bits/stdc++.h>

using namespace std;

template <class T>
class segment_tree
{
    vector<T> m_tree;
    function<T(const T&,const T&)> m_join;

public:
    template <class It>
    segment_tree(It begin, It end, const T& default_value, function<T(const T&,const T&)> join)
        :m_join(join)
    {
        size_t node_count = 1;
        size_t init_value_count = distance(begin, end);
        while(node_count < init_value_count)node_count <<= 1;
        m_tree.resize(node_count << 1, default_value);

        for(size_t i = node_count; begin != end; ++i)
            m_tree[i] = *begin++;
        
        for(size_t i = node_count; i--;)
            m_tree[i] = m_join(m_tree[i << 1], m_tree[i << 1 | 1]);
    }

    size_t leafSize() { return m_tree.size() >> 1; }
    size_t nodeSize() { return m_tree.size(); }
    const T& leafAt(size_t idx) { return m_tree[(m_tree.size() >> 1) + idx]; }
    const T& nodeAt(size_t idx) { return m_tree[idx]; }
    size_t leaf2node(size_t i) { return i + (m_tree >> 1); }

    void update(size_t i, const T& new_value)
    {
        m_tree[i] = new_value;

        while(i >>= 1)
            m_tree[i] = m_join(m_tree[i << 1], m_tree[i << 1 | 1]);
    }

    template <class Function>
    void range_query(size_t begin, size_t end, Function query)
    {
        begin += leafSize();
        end += leafSize();

        while(begin < end){
            if(begin & 1) query(begin++);
            if(end & 1) query(--end);
            begin >>= 1; end >>= 1;
        }
    }
};

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N;
	cin >> N;

	vector<int> A(N+1);
	for(size_t i=0; i!=N; ++i)
		cin >> A[i];
	A[N] = 1'000'000'001;

	vector<size_t> idx(N);
	for(size_t i=0; i!=N; ++i)
		idx[i] = i;

	segment_tree<size_t> seg(idx.begin(), idx.end(), N, [&](size_t a, size_t b){
		if(A[a] == A[b])
			return min(a, b);
		else if(A[a] < A[b])
			return a;
		else
			return b;
	});

	size_t M;
	cin >> M;
	while(M--){
		size_t c;
		cin >> c;
		if(c == 2)
			cout << seg.nodeAt(1)+1 << "\n";
		else{
			size_t i; int v;
			cin >> i >> v;
			--i;

			A[i] = v;
			seg.update(seg.leafSize()+i,  i);
		}
	}
}