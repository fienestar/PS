/*
    로마 숫자 만들기
    https://www.acmicpc.net/problem/16922
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	size_t N;
	cin >> N;

	bool used[20*50+1] = {};
	size_t cnt = 0;

	for(size_t I=0; I<=N; ++I)
		for(size_t V=0; I+V<=N; ++V)
			for(size_t X=0; I+V+X<=N; ++X){
				size_t sum = I + 5*V + 10*X + 50*(N-I-V-X);
				if(not used[sum]){
					used[sum] = true;
					++cnt;
				}
			}

	cout << cnt;
}