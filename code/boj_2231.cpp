/*
    분해합
    https://www.acmicpc.net/problem/2231
*/
#include <iostream>

using namespace std;

size_t GetSum(size_t N)
{
    size_t S=0;
    S+=N;
    do S+=N%10; while(N/=10);
    return S;
}

int main()
{
    size_t N;
    cin >> N;
    for(size_t i=1;i<=N;++i)
        if(GetSum(i) == N){
	    cout << i;
	    return 0;
        }
    cout << 0;
}