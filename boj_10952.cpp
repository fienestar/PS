/*
    A+B - 5
    https://www.acmicpc.net/problem/10952
*/
#include <iostream>

using namespace std;

int main()
{
    size_t A,B;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>A>>B && A && B){
	cout<<A+B<<"\n";
    }
}