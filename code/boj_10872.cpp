/*
    팩토리얼
    https://www.acmicpc.net/problem/10872
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
    size_t N,R=1;
    cin >> N;
    loop(i,N)R*=i+1;
    cout << R;
}