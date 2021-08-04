/*
    A+B - 8
    https://www.acmicpc.net/problem/11022
*/
#include <iostream>
#include <vector>
#include <algorithm>

#define loop(i,N) for(::std::size_t i=0;i!=N;++i)
#define sloop(i,String) for(::std::size_t i=0;String[i];++i)
#define rloop(i,N) for(::std::size_t i=N;i--;)
#define all(v) v.begin(),v.end()

using namespace std;

int main()
{
    size_t T,A,B;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    for(size_t i=0;i!=T;++i){
	cin>>A>>B;
	cout<<"Case #"<<i+1<<": "<<A<<" + "<<B<<" = "<<A+B<<"\n";
    }
}