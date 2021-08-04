/*
    가운데를 말해요
    https://www.acmicpc.net/problem/1655
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	size_t M;
	cin >> M;

	priority_queue<int, vector<int>, greater<int>> minq;
	priority_queue<int, vector<int>, less<int>> maxq;
	list<int> ans;

	for(size_t i=0; i!=M; ++i){
		int n;
		cin >> n;
		if(maxq.size() < minq.size()){
			if(minq.top() < n){
				int t = minq.top();
				minq.pop();
				minq.push(n);
				n = t;
			}
			maxq.push(n);
			ans.push_back(maxq.top());
		}else{
			if(maxq.size() && maxq.top() > n){
				int t = maxq.top();
				maxq.pop();
				maxq.push(n);
				n = t;
			}
			minq.push(n);
			ans.push_back(minq.top());
		}
	}

	for(auto& s:ans)
		cout << s << "\n";
}
