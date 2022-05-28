/*
    삼각형의 최단 경로
    https://www.acmicpc.net/problem/2155
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	ll A, B;
	cin >> A >> B;

	if(A > B)swap(A,B);

	ll bm = 0;
	while(bm*bm < B) ++bm;
	--bm;

	ll am = 0;
	while(am*am < A) ++am;
	--am;

	ll c = 0;
	ll ans = 0;
	while(am != bm){
		if((A-(am*am))%2 == 0){
			++A;
			++c;
			++ans;
		}
		A = A - am*am + 1 + (am+1)*(am+1);
		++am;
		++ans;
	}

	if(B > A)
		ans += B - A;
	else if(A - 2*c <= B && B <= A)
		ans += (A-B)%2;
	else
		ans += A-2*c-B;

	cout << ans;
}