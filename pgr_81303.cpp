/*
    표 편집
    https://programmers.co.kr/learn/courses/30/lessons/81303
*/
#include <string>
#include <vector>
#include <functional>
#include <stack>
#include <iostream>

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

string solution(int n, int k, vector<string> cmd)
{
    stack<size_t> deleted;
    segment_tree<size_t> exist_count(n, 1, [](size_t a, size_t b) { return a + b; });
    auto find = [&exist_count](size_t sum) {
        size_t i = 1;

        while (i < exist_count.leafSize()) {
            i <<= 1;
            if (exist_count.getNode(i) < sum) {
                sum -= exist_count.getNode(i);
                i |= 1;
            }
        }

        return i;
    };

    size_t pos = k + exist_count.leafSize();
    size_t sum = k + 1;
    size_t total = n;

    for (auto& line : cmd) {
        switch (line[0]) {
        case 'U':
            sum -= stol(line.data() + 2);

            pos = find(sum);

            break;
        case 'D':
            sum += stol(line.data() + 2);

            pos = find(sum);

            break;
        case 'C':
            exist_count.update(pos, 0);
            deleted.push(pos);

            --total;

            sum = min(sum, total);

            pos = find(sum);
            break;
        case 'Z':
            exist_count.update(deleted.top(), 1);
            if (deleted.top() < pos)
                ++sum;
            ++total;
            deleted.pop();
            break;
        }
    }

    vector<char> answer(n);
    for (size_t i = 0; i != n; ++i)
        if (exist_count.getLeaf(i))
            answer[i] = 'O';
        else
            answer[i] = 'X';

    return string(answer.begin(), answer.end());
}