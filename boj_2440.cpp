/*
    별 찍기 - 3
    https://www.acmicpc.net/problem/2440
*/
#include <iostream>

using namespace std;

void PutChars(char c,size_t n){
    while(n--)fputc(c,stdout);
}

int main()
{
    size_t N;
    cin>>N;
    for(size_t i=0;i!=N;++i){
        PutChars('*',N-i);
        cout << "\n";
    }
}
