/*
    A+B - 7
    https://www.acmicpc.net/problem/11021
*/
#include <iostream>

using namespace std;

int main()
{
    size_t T,A,B;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    for(size_t i=0;i!=T;++i){
	cin>>A>>B;
	cout<<"Case #"<<i+1<<": "<<A+B<<"\n";
    }
}