/*
    차이 그래프
    https://www.acmicpc.net/problem/11900
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	size_t N;
	cin >> N;

	vector<uint32_t> A(N);
	static bool visited[2000][2000];
	for(size_t i=1; i!=N; ++i){
		cin >> A[i];
		if(!A[i]) A[i] = -1;
	}

	auto f = [&](size_t i, size_t j) -> uint32_t&{
		return A[(i-j+N)%N];
	};

	for(size_t k=0; k!=N; ++k)
		for(size_t i=0; i!=N; ++i)
			if(f(i,k) != -1)
				for(size_t j=0; j!=N; ++j){

if(visited[(k-i+N)%N][(k-j+N)%N]){
	i = k = j = N - 1;
	break;
}
visited[(k-i+N)%N][(k-j+N)%N]=true;

					if(f(k,j) != -1)
						f(i,j) = min(f(i,j),f(i,k)+f(k,j));
}

	size_t Q;
	cin >> Q;

	while(Q--){
		size_t a, b;
		cin >> a >> b;
		cout << (int)f(a,b) << "\n";
	}
}