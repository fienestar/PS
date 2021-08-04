/*
    노솔브 방지문제야!!
    https://www.acmicpc.net/problem/15917
*/
#include <iostream>

using namespace std;

int main()
{
	size_t T,a,flag;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	while(T--) {
		cin>>a;
		flag = 1;
		for(;a!=1;a>>=1)
			if(a&1){
				flag = 0;
				break;
			}
		cout << flag << "\n";
	}
}