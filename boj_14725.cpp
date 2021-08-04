/*
    개미굴
    https://www.acmicpc.net/problem/14725
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	struct tree
	{
		map<string, tree> subtrees;
	};
	tree root;
	string name;

	while(N--){
		size_t K;
		cin >> K;

		tree *next = &root;
		while(K--){
			cin >> name;
			next = &next->subtrees[name];
		}
	}

	size_t dept = 0;
	function<void(tree&)> print = [&](tree& t){
		for(auto& subtree:t.subtrees){
			for(size_t i=0; i!=dept; ++i)
				cout << "--";
			cout << subtree.first << "\n";
			++dept;
			print(subtree.second);
			--dept;
		}
	};


	print(root);
}