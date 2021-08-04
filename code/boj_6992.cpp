/*
    Arithmetic Sequence
    https://www.acmicpc.net/problem/6992
*/
#include <bits/stdc++.h>

using namespace std;

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	if(v.size() == 0)
		return os << "[]";

	os << "[" << v[0];
	for(size_t i=1; i!=v.size(); ++i)
		os << ", " << v[i];
	os << "]";

	return os;
}

void solve()
{
	size_t N;
	cin >> N;

	vector<int> sequence(N);
	for(auto& c:sequence)
		cin >> c;

	int diff = sequence[1] - sequence[0]; // Assume that "sequence" contains at least 2 entries.

	for(size_t i=1; i!= sequence.size(); ++i)
		if(sequence[i] - sequence[i-1] != diff){
			cout << "The sequence " << sequence << " is not an arithmetic sequence.\n";
			return;
		}

	vector<int> answer(5);
	answer[0] = sequence[N-1] + diff;
	for(size_t i=1; i!=5; ++i)
		answer[i] = answer[i-1] + diff;

	cout << "The next 5 numbers after " << sequence << " are: " << answer << "\n";
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t T;
	cin >> T;

	while(T--)
		solve();
}