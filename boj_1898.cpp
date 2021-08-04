/*
    이전 수열은 어떤 수열일까
    https://www.acmicpc.net/problem/1898
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	size_t N;
	cin >> N;

	vector<size_t> S(N);
	for(auto& s:S)
		cin >> s;

	vector<size_t> alter(N+1);
	list<size_t> result;

	for(auto& s:S)
		if(alter[s])
			result.push_back(alter[s]);
		else if(s != 1 && not alter[s-1]){
			alter[s-1] = s;
			alter[s] = s-1;
			result.push_back(s-1);
		}else{
			alter[s] = s;
			result.push_back(s);
		}

	for(auto& s:result)
		cout << s << "\n";
}