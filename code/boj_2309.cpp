/*
    일곱 난쟁이
    https://www.acmicpc.net/problem/2309
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

#define loop(i,N) for(::std::size_t i=0;i!=N;++i)
#define sloop(i,String) for(::std::size_t i=0;String[i];++i)
#define rloop(i,N) for(::std::size_t i=N;i--;)
#define all(v) v.begin(),v.end()

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    static int v[9],sum=0;
    for(auto& i:v){ cin>>i; sum+=i; }
    sort(v,v+9);
    loop(i,9)loop(j,9){
	if(i==j)continue;
        if(sum-v[i]-v[j]==100){
	    for(size_t k=0;k!=9;++k)
		if(k!=i&&k!=j)cout << v[k] << "\n";
	    return 0;
	}
    }
}