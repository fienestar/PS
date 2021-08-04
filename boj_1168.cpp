/*
    요세푸스 문제 2
    https://www.acmicpc.net/problem/1168
*/
#include <bits/stdc++.h>

using namespace std;

template < class T >
class static_segment_tree {
    vector < T > m_tree;

    function < T(const T&,
        const T&) > m_join;

    void init() {
        for (size_t i = m_tree.size() >> 1; --i;)
            m_tree[i] = m_join(m_tree[i << 1], m_tree[i << 1 | 1]);
    }
public:
    static_segment_tree(function < T(const T&,
        const T&) > join, size_t n) : m_tree(n << 1), m_join(join) {
        init();
    }

    template < class It >
    static_segment_tree(function < T(const T&,
        const T&) > join, It begin, It end) : m_tree(), m_join(join) {
        size_t n = distance(begin, end);
        m_tree.resize(n << 1);
        for (size_t i = 0; i != n; ++i)
            m_tree[n + i] = *begin++;

        init();
    }

    size_t query(size_t n, size_t& offset) {
        offset = n = (n + offset) % m_tree[1];
        size_t min = m_tree.size() >> 1;
        size_t idx = 1;
        while (idx < min) {
            if (m_tree[idx << 1] <= n) {
                idx <<= 1;
                n -= m_tree[idx];
                idx |= 1;
            }
            else
                idx <<= 1;
        }
        return idx - min;
    }

    void update(size_t i, const T& val) {
        m_tree[i += (m_tree.size() >> 1)] = val;
        for (; i >>= 1;)
            m_tree[i] = m_join(m_tree[i << 1], m_tree[i << 1 | 1]);
    }

    size_t get(size_t idx) {
        return m_tree[(m_tree.size() >> 1) + idx];
    }
};

int main() {
    size_t N, K;
    cin >> N >> K;

    size_t len = 1;
    while (len < N) len <<= 1;

    vector < size_t > data(len, 1);
    fill(data.begin() + N, data.end(), 0);

    static_segment_tree <size_t> seg([](size_t a, size_t b) {
        return a + b;
        }, data.begin(), data.end());

    K -= 1;
    size_t offset = 0;

    vector<size_t> ans(N);

    for (size_t i = 0; i != N; ++i) {
        size_t idx = seg.query(K, offset);
        seg.update(idx, 0);
        ans[i] = idx + 1;
    }

    cout << "<";
    for (size_t i = 0; i != N - 1; ++i)
        cout << ans[i] << ", ";
    cout << ans[N - 1] << ">";
}