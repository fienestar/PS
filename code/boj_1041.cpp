/*
    주사위
    https://www.acmicpc.net/problem/1041
*/
#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	ull v[6];
	for(auto& c:v)cin >> c;

	if(N == 1){
		cout << accumulate(begin(v),end(v),-*max_element(begin(v),end(v)));
	}else{
		bool used[6] = {};
		size_t lused[3] = {6, 6};
		function<ull(size_t,size_t)> find = [&](size_t c, size_t k)->ull{
			if(c == 0)return 0;
			--c;

			ull m = -1;
			for(size_t j=0; j!=6; ++j)
				if(std::find(begin(lused), end(lused), j) == end(lused) && !used[j]){
					used[j] = true;
					lused[c] = 5-j;
					auto res = find(c, j);
					if(res != -1)
						m = min(m, v[j]+res);
					lused[c] = 6;
					used[j] = false;
				}
			return m;
		};

		ull s3 = find(3,-1);
		ull s2 = find(2,-1);
		ull s1 = find(1,-1);

		cout << s3*4 + s2*(N-2)*4 + s2*(N-1)*4 + s1*(N-1)*(N-2)*4 + s1*(N-2)*(N-2);
	}
}