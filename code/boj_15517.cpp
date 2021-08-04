/*
    Array Manipulation at Moloco (Hard)
    https://www.acmicpc.net/problem/15517
*/
#include <bits/stdc++.h>

using namespace std;

template <class T>
class CMPTree
{
	CMPTree* _greater; // ...or_eq
	CMPTree* _less;
	T _value;
	size_t _size;

	void release(CMPTree* (CMPTree::* sub))
	{
		CMPTree* p_sub = this->*sub;
		_size -= p_sub->_size;
		this->*sub = nullptr;
	}

	void rebalance(CMPTree* (CMPTree::* sub))
	{
		return;
		CMPTree* p_sub = this->*sub;
		if (p_sub && _size < p_sub->_size * 2) {
			release(sub);
			p_sub->Insert<false>(this);
		}
	}

	template <bool is_root>
	size_t Insert(CMPTree* (CMPTree::* sub), CMPTree* sub_value)
	{
		CMPTree* p_sub = this->*sub;
		_size += sub_value->_size;

		if (p_sub == nullptr) {
			this->*sub = sub_value;
			return 0;
		}
		else {
			size_t result = p_sub->Insert<false>(sub_value);
			if constexpr(not is_root)
				rebalance(sub);
			return result;
		}
	}

	template <bool is_root>
	size_t Insert(CMPTree* sub)
	{
		if (sub->_value < _value)
			return Insert<is_root>(&CMPTree::_less, sub);
		else {
			size_t less_size = 0;
			if (_less)
				less_size = _less->_size;
			return (_value < sub->_value) + less_size + Insert<is_root>(&CMPTree::_greater, sub);
		}
	}

public:
	CMPTree(T value)
		:_greater(nullptr), _less(nullptr), _value(value), _size(1) {}

	~CMPTree()
	{
		/*
		delete _greater;
		delete _less;
		*/
	}

	size_t insert(T value)
	{
		size_t expected_size = _size + 1;
		size_t result = Insert<true>(new CMPTree(value));

		assert(_size == expected_size);

		return result;
	}
};

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N;
	cin >> N;

	int root_value;
	cin >> root_value;

	CMPTree<int> root(root_value);
	cout << "0\n";

	while (--N) {
		int value;
		cin >> value;
		cout << root.insert(value) << "\n";
	}
}