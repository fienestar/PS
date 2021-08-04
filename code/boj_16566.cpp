/*
    카드 게임
    https://www.acmicpc.net/problem/16566
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
};

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N,M,K;
	cin >> N >> M >> K;

	vector<size_t> v(M);
	for(auto& c:v)
		cin >> c;

	sort(v.begin(), v.end());

	segment_tree<size_t> seg(v.begin(), v.end(), -1, [](size_t a,size_t b) {
		return max(a, b);
	});

	while(K--){
		size_t n;
		cin >> n;

		size_t i = 1;
		while(i < seg.leafSize()){
			i <<= 1;
			if(seg.nodeAt(i) <= n)i |= 1;
		}

		cout << seg.nodeAt(i) << "\n";

		seg.update(i, 0);
	}
}