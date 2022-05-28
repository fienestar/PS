/*
    단어 수학
    https://www.acmicpc.net/problem/1339
*/
#include <bits/stdc++.h>
    
using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N;
	cin >> N;

	vector<size_t> sum('Z'-'A'+1);
	string word;
	while(N--){
		cin >> word;
		size_t s = 1;
		for(size_t i=word.size(); i--;){
			sum[word[i]-'A'] += s;
			s *= 10;
		}
	}

	sort(sum.rbegin(), sum.rend());

	size_t ans = 0;
	for(size_t i=0; i!=10; ++i)
		ans += sum[i] * (9-i);

	cout << ans;
}