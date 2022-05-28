/*
    인사성 밝은 곰곰이
    https://www.acmicpc.net/problem/25192
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	string s;
	size_t count = 0;
	set<string> user;
	while(cin >> s){
		if(s == "ENTER")
			user = set<string>();
		else{
			count += !user.count(s);
			user.insert(s);
		}
	}

	cout << count;
}