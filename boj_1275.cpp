/*
    커피숍2
    https://www.acmicpc.net/problem/1275
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

	size_t N, Q;
	cin >> N >> Q;

	using ll = long long;
	vector<ll> v(N);
	for(auto& c:v)
		cin >> c;

	segment_tree<ll> seg(v.begin(), v.end(), 0, [](ll a, ll b){
		return a+b;
	});

	while(Q--){
		size_t x, y;
		cin >> x >> y;
		if(x > y)swap(x,y);
		--x;

		x += seg.leafSize();
		y += seg.leafSize();

		ll sum = 0;
		while(x < y){
			if(x & 1) sum += seg.nodeAt(x++);
			if(y & 1) sum += seg.nodeAt(--y);
			x >>= 1; y >>= 1;
		}
		cout << sum << "\n";

		size_t a;
		ll b;
		cin >> a >> b;
		--a;

		seg.update(a + seg.leafSize(), b);
	}
}