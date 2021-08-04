/*
    A+B - 3
    https://www.acmicpc.net/problem/10950
*/
#include <iostream>

using namespace std;

int main()
{
    size_t T,A,B;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--){
	cin>>A>>B;
	cout<<A+B<<"\n";
    }
}